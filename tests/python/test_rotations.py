from oal import coords, units

import math
import pytest
import numpy as np
from hypothesis import given, note, assume, strategies as st

from .helpers import sample_from_enum


@given(
    st.floats(allow_nan=False, allow_infinity=False),
    st.just(coords.rotate_x) | st.just(coords.rotate_y) | st.just(coords.rotate_z),
    st.just(units.DEGREES) | st.just(units.RADIANS),
)
def test__rotate_xyz__composition_with_inverse_rotation_is_identity(
    angle, routine, unit
):
    A = routine(angle, units=unit)
    B = routine(-angle, units=unit)

    assert A @ B == pytest.approx(np.eye(3), rel=1e-5)


@given(
    st.floats(allow_nan=False, allow_infinity=False),
    st.just((coords.rotate_x, [1, 0, 0]))
    | st.just((coords.rotate_y, [0, 1, 0]))
    | st.just((coords.rotate_z, [0, 0, 1])),
)
def test__rotate_xyz__rotation_about_an_axis_does_not_change_a_point_on_that_axis(
    angle, axis
):
    rotate, point = axis
    A = rotate(angle)
    assert A @ point == pytest.approx(point, rel=1e-5)


@given(
    st.floats(allow_nan=False, allow_infinity=False),
    st.floats(allow_nan=False, allow_infinity=False),
    st.floats(allow_nan=False, allow_infinity=False),
    sample_from_enum(units.AngleUnit),
    sample_from_enum(coords.RotationSequence),
)
def test__dcm_from_euler__is_orthogonal(a, b, c, unit, sequence):
    eulers = np.array([a, b, c])
    R = coords.dcm_from_eulers(eulers, units=unit, sequence=sequence)

    # Orthogonality implies A^T == A^-1, and A^-1 @ A == I
    assert R.T @ R == pytest.approx(np.eye(3), rel=1e-12)


def _compute_remaining_axis(a: int, b: int) -> int:
    """
    Given two distinct axes a, b ∈ {0, 1, 2}, return the third axis.

    Raises:
        ValueError: If a or b is out of range or a == b.
    """
    if not (0 <= a <= 2) or not (0 <= b <= 2):
        raise ValueError(f"Axes must be in {{0,1,2}}, got a={a}, b={b}")
    if a == b:
        raise ValueError(f"Axes must be different, got a={a}, b={b}")
    return 3 - a - b

def _get_axis_numbers_from_sequence(sequence: coords.RotationSequence):
    """
    Given a rotation sequence, return the axis numbers in the order they are applied.
    """
    match sequence:
        case coords.RotationSequence.INTRINSIC_XYZ:
            return 0, 1, 2
        case coords.RotationSequence.INTRINSIC_XZY:
            return 0, 2, 1
        case coords.RotationSequence.INTRINSIC_YXZ:
            return 1, 0, 2
        case coords.RotationSequence.INTRINSIC_YZX:
            return 1, 2, 0
        case coords.RotationSequence.INTRINSIC_ZXY:
            return 2, 0, 1
        case coords.RotationSequence.INTRINSIC_ZYX:
            return 2, 1, 0
        case coords.RotationSequence.PROPER_XYX:
            return 0, 1, 0
        case coords.RotationSequence.PROPER_XZX:
            return 0, 2, 0
        case coords.RotationSequence.PROPER_YXY:
            return 1, 0, 1
        case coords.RotationSequence.PROPER_YZY:
            return 1, 2, 1
        case coords.RotationSequence.PROPER_ZXZ:
            return 2, 0, 2
        case coords.RotationSequence.PROPER_ZYZ:
            return 2, 1, 2
        case _:
            raise ValueError(f"Unknown rotation sequence: {sequence}")


@given(
    st.sampled_from([0, 1, 2]),
    st.sampled_from([0, 1, 2]),
    st.floats(min_value=5, max_value=45, allow_nan=False, allow_infinity=False),
    sample_from_enum(coords.RotationSequence),
)
def test__dcm_to_euler__rotation_about_an_axis_moves_point_in_correct_direction(
    rotation_axis_index, point_axis, angle_deg, sequence
):
    """
    When all other dimensions are zeroed out, check that a clockwise rotation (-theta) of the coordinate system produces a positive change in a points coordinates,
    and a counter-clockwise rotation (+theta) produces a negative change.
    """

    # We are not interested in zero rotation
    assume(angle_deg != 0.0)

    # The rotation sequence jumbles the order of the axes, so find the real axis number we are rotating about
    rotation_axis = _get_axis_numbers_from_sequence(sequence)[rotation_axis_index]
    note(f"Rotation axis: {rotation_axis}")

    # Rotating around the axis the point lies on will produce no movement, so exclude it
    assume(rotation_axis != point_axis)

    # Produce a rotation about the specified axis
    eulers_deg = np.zeros((3,))
    eulers_deg[rotation_axis_index] = angle_deg
    note(f"Eulers: {eulers_deg}")


    # Create a point that lies along a different axis
    point = np.zeros((3,))
    point[point_axis] = 1
    note(f"Point: {point}")

    # Find the axis that is not rotation_axis or point_axis
    # this is the direction we expect the point to move along
    measurement_axis = _compute_remaining_axis(rotation_axis, point_axis)
    note(f"Measurement axis: {measurement_axis}")

    # Compute DCM
    R = coords.dcm_from_eulers(eulers_deg, sequence=sequence, units=units.DEGREES)
    note(f"DCM: {R}")

    # Apply rotation
    new_point = R @ point
    note(f"New point: {new_point}")

    # Compute the expected sign of the point's coordinate along the measurement axis
    expected_sign_table = {
        (0, 1): -1,
        (0, 2): 1,
        (1, 0): 1,
        (1, 2): -1,
        (2, 0): -1,
        (2, 1): 1,
    }
    sign = expected_sign_table[(rotation_axis, point_axis)]
    note(f"Sign: {sign}")

    # The point's coordinate along the axis should have the same sign as the angle
    assert np.sign(new_point[measurement_axis]) == sign
