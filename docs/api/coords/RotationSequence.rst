``RotationSequence``
===============================

:namespace: ``oal::coords``
:header: ``oal/coords/rotations.hpp``
:brief: Order in which euler angle rotations are applied. Order is given in the order the rotations are applied, not in the order the matrices appear when written.

.. cpp:namespace-push:: oal::coords

.. tabs::
  .. group-tab:: C++
    .. cpp:enum-class:: RotationSequence
      :no-contents-entry:

      .. cpp:enumerator:: INTRINSIC_ZYX
        :no-contents-entry:
      .. cpp:enumerator:: INTRINSIC_XZY
        :no-contents-entry:
      .. cpp:enumerator:: INTRINSIC_YXZ
        :no-contents-entry:
      .. cpp:enumerator:: INTRINSIC_YZX
        :no-contents-entry:
      .. cpp:enumerator:: INTRINSIC_XYZ
        :no-contents-entry:
      .. cpp:enumerator:: INTRINSIC_ZXY
        :no-contents-entry:
      .. cpp:enumerator:: PROPER_XZX
        :no-contents-entry:
      .. cpp:enumerator:: PROPER_XYX
        :no-contents-entry:
      .. cpp:enumerator:: PROPER_YXY
        :no-contents-entry:
      .. cpp:enumerator:: PROPER_YZY 
        :no-contents-entry:
      .. cpp:enumerator:: PROPER_ZYZ 
        :no-contents-entry:
      .. cpp:enumerator:: PROPER_ZXZ 
        :no-contents-entry:
      .. cpp:enumerator:: EXTRINSIC_ZYX
        :no-contents-entry:
      .. cpp:enumerator:: EXTRINSIC_XZY
        :no-contents-entry:
      .. cpp:enumerator:: EXTRINSIC_YXZ
        :no-contents-entry:
      .. cpp:enumerator:: EXTRINSIC_YZX
        :no-contents-entry:
      .. cpp:enumerator:: EXTRINSIC_XYZ
        :no-contents-entry:
      .. cpp:enumerator:: EXTRINSIC_ZXY
        :no-contents-entry:
      .. cpp:enumerator:: YPR
        :no-contents-entry:

  .. group-tab:: Python
    .. py:class:: RotationSequence
      :no-contents-entry:

      .. py:attribute:: INTRINSIC_ZYX
        :no-contents-entry:
      .. py:attribute:: INTRINSIC_XZY
        :no-contents-entry:
      .. py:attribute:: INTRINSIC_YXZ
        :no-contents-entry:
      .. py:attribute:: INTRINSIC_YZX
        :no-contents-entry:
      .. py:attribute:: INTRINSIC_XYZ
        :no-contents-entry:
      .. py:attribute:: INTRINSIC_ZXY
        :no-contents-entry:
      .. py:attribute:: PROPER_XZX
        :no-contents-entry:
      .. py:attribute:: PROPER_XYX
        :no-contents-entry:
      .. py:attribute:: PROPER_YXY
        :no-contents-entry:
      .. py:attribute:: PROPER_YZY 
        :no-contents-entry:
      .. py:attribute:: PROPER_ZYZ 
        :no-contents-entry:
      .. py:attribute:: PROPER_ZXZ 
        :no-contents-entry:
      .. py:attribute:: EXTRINSIC_ZYX
        :no-contents-entry:
      .. py:attribute:: EXTRINSIC_XZY
        :no-contents-entry:
      .. py:attribute:: EXTRINSIC_YXZ
        :no-contents-entry:
      .. py:attribute:: EXTRINSIC_YZX
        :no-contents-entry:
      .. py:attribute:: EXTRINSIC_XYZ
        :no-contents-entry:
      .. py:attribute:: EXTRINSIC_ZXY
        :no-contents-entry:
      .. py:attribute:: YPR
        :no-contents-entry:


Details
-------
Determines the rotation sequence used by functions expecting an euler angle.
Rotations are given in the order they occur. For example,
:cpp:enumerator:`RotationSequence::INTRINSIC_ZYX` represents a rotation as
follows:

.. math::
  R(\theta, \phi, \psi) = R_x(\psi) R_y(\phi) R_z(\theta)

where :math:`R_{\text{axis}}` is a rotation purely about the given axis.

Proper sequences use the same axis for the first and last rotation.

Extrinsic sequences are notated in order the rotation occurs, and are
aliases of the inverse sequence of intrinsic rotations.

:cpp:enumerator:`RotationSequence::YPR` is an alias for `RotationSequence::INTRINSIC_ZYX`.
