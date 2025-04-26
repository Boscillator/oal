.. _oal.units.to_degrees:

``to_degrees``
==================================

:namespace: ``oal::units``
:header: ``oal/units.hpp``
:brief: Convert an angle to degrees.

.. cpp:namespace-push:: oal::units

.. tabs::
  .. group-tab:: C++
    .. cpp:function:: double to_degrees(const double angle_rad)
    .. cpp:function:: double to_degrees(const double angle, const AngleUnit units)

  .. group-tab:: Python
    .. py:function:: to_degrees(angle, units = oal.units.RADIANS)

Parameters
----------
:double angle:
    Angle to be converted to degrees. Unless ``units`` is specified, this is assumed to be in radians.
:AngleUnit units:
    Units to convert from.

Details
-------
Multiplies the angle by the correct scale factor to convert to degrees. If the resultant angle is outside the range of an IEEE 64 bit float, returns +inf or -inf.

Examples
---------

.. tabs::
  .. group-tab:: C++
    .. code-block:: cpp

      oal::units::to_degrees(oal::pi); // returns 180
      oal::units::to_degrees(oal::pi, oal::units::AngleUnit::DEGREES); // works as a no-op if units is degrees

  .. group-tab:: Python
    .. testsetup::

      import oal
      import numpy as np

    .. doctest::

      # Convert pi radians to degrees
      >>> oal.units.to_degrees(np.pi)
      180.0

      # oal.units.to_radians() supports numpy arrays
      >>> oal.units.to_degrees(np.array([0, np.pi/2, np.pi]))
      array([  0.,  90., 180.])

      # works as a no-op if units is radians
      >>> oal.units.to_degrees(180, oal.units.DEGREES)
      180.0

See Also
--------
:ref:`oal.units.to_radians`, :ref:`oal.units.AngleUnit`
