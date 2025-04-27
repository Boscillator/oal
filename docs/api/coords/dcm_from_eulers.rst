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


