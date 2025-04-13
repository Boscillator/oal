#ifndef OAL_UNITS_HPP_
#define OAL_UNITS_HPP_

#include "oal/core.hpp"

namespace oal {
namespace units {

enum AngleUnit {
  DEGREES,
  RADIANS
};

OAL_EXPORT double to_radians(const double angle_deg);
OAL_EXPORT double to_radians(const double angle, const AngleUnit units);
OAL_EXPORT double to_degrees(const double angle_radians);
OAL_EXPORT double to_degrees(const double angle, const AngleUnit units);

}
}

#endif