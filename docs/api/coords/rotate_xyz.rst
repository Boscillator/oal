``rotate_[xyz]``
===========================

:namespace: ``oal::coords``
:header: ``oal/coords/rotations.hpp``
:brief: Compute a direction cosign matrix (DCM) representing a rotation about a specified axis.

.. cpp:namespace-push:: oal::coords

.. tabs::
  .. group-tab:: C++
    .. cpp:function:: Mat3 rotate_x(const double angle_rad)
      :no-contents-entry:
    .. cpp:function:: Mat3 rotate_x(const double angle, const oal::units::AngleUnit units)
      :no-contents-entry:
    .. cpp:function:: Mat3 rotate_y(const double angle_rad)
      :no-contents-entry:
    .. cpp:function:: Mat3 rotate_y(const double angle, const oal::units::AngleUnit units)
      :no-contents-entry:
    .. cpp:function:: Mat3 rotate_z(const double angle_rad)
      :no-contents-entry:
    .. cpp:function:: Mat3 rotate_z(const double angle, const oal::units::AngleUnit units)
      :no-contents-entry:
  .. group-tab:: Python
    .. py:function:: rotate_x(angle, units=oal.units.RADIANS)
      :no-contents-entry:
    .. py:function:: rotate_y(angle, units=oal.units.RADIANS)
      :no-contents-entry:
    .. py:function:: rotate_z(angle, units=oal.units.RADIANS)
      :no-contents-entry:

Parameters
----------
:double angle: Angle theta to rotate by. In radians be default.
:AngleUnit units: Units ``angle`` is in. Defaults to radians.

Details
-------
Computes rotation matrix according to the following formula:

.. math::
  R_x(\theta) = \begin{bmatrix}
  1 & 0 & 0 \\
  0 & \cos(\theta) & \sin(\theta) \\
  0 & -\sin(\theta)& \cos(\theta)
  \end{bmatrix}

.. math::
  R_y(\theta) = \begin{bmatrix}
  \cos(\theta) & 0 & -\sin(\theta) \\
  0 & 1 & 0 \\
  \sin(\theta) & 0 & \cos(\theta)
  \end{bmatrix}

.. math::
  R_z(\theta) = \begin{bmatrix}
  \cos(\theta) & \sin(\theta) & 0 \\
  \sin(\theta) & \cos(\theta) & 0 \\
  0 & 0 & 1
  \end{bmatrix}

.. note::
  The DCM produced uses the premultiplied, passive notation convention. See :ref:`active_vs_passive_rotations` for more details.
