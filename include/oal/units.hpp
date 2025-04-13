#ifndef OAL_UNITS_HPP_
#define OAL_UNITS_HPP_

#include "oal/core.hpp"

namespace oal {
namespace units {

enum AngleUnit {
  DEGREES,
  RADIANS
};

double to_radians(const double angle_deg);
double to_radians(const double angle, const AngleUnit units);
double to_degrees(const double angle_radians);
double to_degrees(const double angle, const AngleUnit units);

}
}

#endif