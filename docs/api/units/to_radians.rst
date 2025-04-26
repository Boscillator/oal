.. _oal.units.to_radians:

``to_radians``
==================================

:namespace: ``oal::units``
:header: ``oal/units.hpp``
:brief: Convert an angle to radians.

.. cpp:namespace-push:: oal::units

.. tabs::
  .. group-tab:: C++
    .. cpp:function:: double to_radians(const double angle_deg)
    .. cpp:function:: double to_radians(const double angle, const AngleUnit units)

  .. group-tab:: Python
    .. py:function:: to_radians(angle, units = oal.units.DEGREES)

Parameters
----------
:double angle:
    Angle to be converted to radians. Unless ``units`` is specified, this is assumed to be in degrees.
:AngleUnit units:
    Units to convert from.

Details
-------
Multiplies the angle by the correct scale factor to convert to radians.

Examples
---------

.. tabs::
  .. group-tab:: C++
    .. code-block:: cpp

      oal::units::to_radians(180); // returns pi
      oal::units::to_radians(oal::pi, oal::units::AngleUnit::RADIANS); // works as a no-op if units is radians

  .. group-tab:: Python
    .. testsetup::

      import oal
      import numpy as np

    .. doctest::

      # Convert 180 degrees to radians
      >>> oal.units.to_radians(180)
      3.141592653589793

      # oal.units.to_radians() supports numpy arrays
      >>> oal.units.to_radians(np.array([0,90,180]))
      array([0.        , 1.57079633, 3.14159265])

      # works as a no-op if units is radians
      >>> oal.units.to_radians(np.pi, oal.units.RADIANS)
      3.141592653589793

See Also
--------
:ref:`oal.units.to_degrees`, :ref:`oal.units.AngleUnit`