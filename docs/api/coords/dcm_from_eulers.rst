``dcm_from_euler``
=============================
:namespace: ``oal::coords``
:header: ``oal/coords/rotations.hpp``
:brief: Compute a direction cosign matrix (DCM) from euler angles.

.. cpp:namespace-push:: oal::coords


.. tabs::
  .. group-tab:: C++
    .. cpp:function:: Mat3 dcm_from_eulers(const Vec3Ref eulers_rad)
      :no-contents-entry:
    
    .. cpp:function:: Mat3 dcm_from_eulers(const Vec3Ref eulers, const oal::units::AngleUnit units)
      :no-contents-entry:

    .. cpp:function:: Mat3 dcm_from_eulers(const Vec3Ref eulers_rad, const RotationSequence sequence)
      :no-contents-entry:

    .. cpp:function:: Mat3 dcm_from_eulers(const Vec3Ref eulers, const oal::units::AngleUnit units, const RotationSequence sequence)
      :no-contents-entry:

    .. cpp:function:: Mat3 dcm_from_eulers(const double yaw_rad, const double pitch_rad, const double roll_rad)
      :no-contents-entry:
    
    .. cpp:function:: Mat3 dcm_from_eulers(const double yaw, const double pitch, const double roll, const units::AngleUnit units)
      :no-contents-entry:

  .. group-tab:: Python
    .. py:function:: dcm_from_eulers(eulers, units = oal.units.RADIANS, sequence = oal.coords.RotationSequence.INTRINSIC_XYZ)
      :no-contents-entry:
    
    .. py:function:: dcm_from_eulers(yaw, pitch, roll, units = oal.units.RADIANS)
      :no-contents-entry:
      :no-index:

Parameters
----------
:Vec3 eulers: Euler angles in the reverse order they appear in `sequence` in the unit given by `units`. Defaults to radians in the order :math:`(z, y, x)`.

:units::AngleUnit units: Unit the euler angles are given in. Defaults to radians.

:RotationSequence sequence: Order in which the rotations are applied. See :ref:`oal.coords.RotationSequence` for more details.

:double yaw: Rotation about the z-axis. Always uses :cpp:enumerator:`oal::coords::RotationSequence::INTRINSIC_ZYX`. In radians by default.

:double pitch: Rotation about the y-axis. Always uses :cpp:enumerator:`oal::coords::RotationSequence::INTRINSIC_ZYX`. In radians by default.

:double roll: Rotation about the x-axis. Always uses :cpp:enumerator:`oal::coords::RotationSequence::INTRINSIC_ZYX`. In radians by default.

Details
-------
.. note::
  The DCM produced uses the premultiplied, passive notation convention. See :ref:`active_vs_passive_rotations` for more details.
  The angles are given according to the right-hand rule.

Euler angles represent the rotation of a coordinate system about its basis axes.
The order in which the rotations are performed is called the rotation sequence
and is controlled by the ``sequence`` parameter. The sequence can either be
intrinsic, in which the basis angles change after each rotation, or extrinsic,
in which the axes of rotation are fixed. Because extrinsic rotations are
equivalent to the intrinsic sequence in opposite order, OAL only implements the
intrinsic sequences, but provides aliases for the equivalent extrinsic sequence.
OAL also supports proper euler angles, in which the same axis is used for the first
and last rotation.

The resultant DCM is computed by multiplication of matrices which represent rotations
about each axis in the sequence. For example, if :cpp:enumerator:`oal::coords::RotationSequence::INTRINSIC_ZYX`
is used, the final matrix would be calculated as follows:

.. math::
  R_{\text{zyx}}(\phi, \theta, \psi) = R_x(\psi) R_y(\theta) R_z(\phi)

where the matrices :math:`R_x`, :math:`R_y` and :math:`R_z` are given by
:cpp:func:`oal::coords::rotate_x`, :cpp:func:`oal::coords::rotate_y`, and
:cpp:func:`oal::coords::rotate_z` respectively. Note that for intrinsic
sequences, the order given by the sequence is reversed from the direction the
matrices appear on the page.


Examples
--------
.. tabs::
  .. group-tab:: C++
    .. code-block:: cpp

      // Default ZYX rotation sequence, results in rotation
      // about the Z axis
      const Eigen::Vector3 eulers_rad = {M_PI/2, 0, 0};
      const auto R1 = oal::coords::dcm_from_eulers(eulers_rad);

      // Specify units and sequence
      const Eigen::Vector3 eulers_deg = {90, 0, 0};
      const auto R2 = oal::coords::dcm_from_eulers(
        eulers_deg,
        oal::units::DEGREES,
        oal::coords::RotationSequence::INTRINSIC_ZXY
      )

  .. group-tab:: Python
    .. testsetup::

      import numpy as np

    .. doctest::

      >>> from oal import units, coords
      >>> coords.dcm_from_eulers([np.pi/2, 0, 0]) @ [1, 0, 0]
      array([ 6.123234e-17, -1.000000e+00,  0.000000e+00])
      >>> coords.dcm_from_eulers([90, 0, 0], units=units.DEGREES) @ [1,0,0]
      array([ 6.123234e-17, -1.000000e+00,  0.000000e+00])
      >>> coords.dcm_from_eulers([np.pi/2, 0, 0], sequence=coords.RotationSequence.INTRINSIC_XYZ) @ [1,0,0]
      array([1., 0., 0.])