.. _oal.units.AngleUnit:

``oal.units.AngleUnit``
=======================

:namespace: ``oal::units``
:header: ``oal/units.hpp``
:brief: Unit of measure representing an angle.

.. cpp:namespace-push:: oal::units

.. tabs::
  .. group-tab:: C++
    .. cpp:enum:: AngleUnit

      .. cpp:enumerator:: DEGREES

        Angle in degrees (360 degrees per circle).

      .. cpp:enumerator:: RADIANS

        Angle in radians (:math:`2\pi` radians per circle).

  .. group-tab:: Python
    .. py:class:: AngleUnit

      .. py:attribute:: DEGREES

        Angle in degrees (360 degrees per circle).

      .. py:attribute:: RADIANS

        Angle in radians (:math:`2\pi` radians per circle).


See Also
--------
:ref:`oal.units.to_degrees`, :ref:`oal.units.to_radians`