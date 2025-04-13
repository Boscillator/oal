#ifndef OAL_UNITS_HPP_
#define OAL_UNITS_HPP_

#include "oal/core.hpp"

namespace oal {
namespace units {

// @brief Unit of measure representing an angle.
enum AngleUnit {
  // @brief Angle in degrees (360 degrees per circle).
  DEGREES,
  // @brief Angle in radians (2 * pi radians per circle).
  RADIANS
};

// @brief Convert an angle to radians.
// @param angle_deg Angle in degrees.
// @return Angle in radians.
OAL_EXPORT double to_radians(const double angle_deg);

// @brief Convert an angle to radians.
// @param angle Angle to convert in `units`.
// @param units Units to convert from.
// @return Angle in radians.
OAL_EXPORT double to_radians(const double angle, const AngleUnit units);

// @brief Convert an angle to degrees.
// @param angle_radians Angle in radians.
// @return Angle in degrees.
OAL_EXPORT double to_degrees(const double angle_radians);

// @brief Convert an angle to degrees.
// @param angle Angle to convert in `units`.
// @param units Units to convert from.
// @return Angle in degrees.
OAL_EXPORT double to_degrees(const double angle, const AngleUnit units);

}
}

#endif