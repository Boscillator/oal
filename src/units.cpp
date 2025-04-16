#include "oal/units.hpp"

#include "oal/core.hpp"

namespace oal {
namespace units {

static constexpr double RADIANS_PER_DEGREE = pi / 180;
static constexpr double DEGREES_PER_RADIAN = 1.0 / RADIANS_PER_DEGREE;

double to_radians(const double angle_deg) {
  return RADIANS_PER_DEGREE * angle_deg;
}

double to_radians(const double angle, const AngleUnit units) {
  switch (units) {
    case DEGREES:
      return RADIANS_PER_DEGREE * angle;
    case RADIANS:
      return angle;
    default:
      OAL_UNREACHABLE;
  }
}

double to_degrees(const double angle_radians) {
  return DEGREES_PER_RADIAN * angle_radians;
}

double to_degrees(const double angle, const AngleUnit units) {
  switch (units) {
    case DEGREES:
      return angle;
    case RADIANS:
      return DEGREES_PER_RADIAN * angle;
    default:
      OAL_UNREACHABLE;
  }
}

}  // namespace units
}  // namespace oal
