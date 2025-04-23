from oal import coords, units

import pytest
import numpy as np
from hypothesis import given, note, strategies as st

from .helpers import sample_from_enum


@given(st.floats(allow_nan=False, allow_infinity=False), st.just(coords.rotate_x) | st.just(coords.rotate_y) | st.just(coords.rotate_z), st.just(units.DEGREES) | st.just(units.RADIANS))
def test_composition_with_inverse_rotation_is_identity(angle, routine, unit):
  A = routine(angle, units=unit)
  B = routine(-angle, units=unit)

  assert A @ B == pytest.approx(np.eye(3), rel=1e-5)

@given(st.floats(allow_nan=False, allow_infinity=False), 
       st.just((coords.rotate_x, [1,0,0])) | st.just((coords.rotate_y, [0, 1, 0])) | st.just((coords.rotate_z, [0, 0, 1])))
def test_rotation_about_an_axis_does_not_change_a_point_on_that_axis(angle, axis):
  rotate, point = axis
  A = rotate(angle)
  assert A @ point == pytest.approx(point, rel=1e-5)

@given(
    st.floats(allow_nan=False, allow_infinity=False),
    st.floats(allow_nan=False, allow_infinity=False),
    st.floats(allow_nan=False, allow_infinity=False),
    sample_from_enum(units.AngleUnit),
    sample_from_enum(coords.RotationSequence))
def test_dcm_from_euler_is_orthogonal(a,b,c, unit, sequence):
  eulers = np.array([a,b,c])
  R = coords.dcm_from_eulers(eulers, units=unit, sequence=sequence)

  # Orthogonality implies A^T == A^-1, and A^-1 @ A == I
  assert np.allclose(R.T @ R, np.eye(3))

