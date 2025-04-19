#include "oal/coords/rotations.hpp"

namespace oal {
namespace coords {

Mat3 rotate_x(const double angle_rad) {
  const double s_theta = std::sin(angle_rad);
  const double c_theta = std::cos(angle_rad);
  return (Mat3() << 1, 0, 0, 0, c_theta, s_theta, 0, -s_theta, c_theta)
      .finished();
}

OAL_EXPORT Mat3 rotate_x(const double angle, const units::AngleUnit units) {
  return rotate_x(units::to_radians(angle, units));
}

Mat3 rotate_y(const double angle_rad) {
  const double s_theta = std::sin(angle_rad);
  const double c_theta = std::cos(angle_rad);
  return (Mat3() << c_theta, 0, -s_theta, 0, 1, 0, s_theta, 0, c_theta)
      .finished();
}

OAL_EXPORT Mat3 rotate_y(const double angle, const units::AngleUnit units) {
  return rotate_y(units::to_radians(angle, units));
}

Mat3 rotate_z(const double angle_rad) {
  const double s_theta = std::sin(angle_rad);
  const double c_theta = std::cos(angle_rad);
  return (Mat3() << c_theta, s_theta, 0, -s_theta, c_theta, 0, 0, 0, 1)
      .finished();
}

OAL_EXPORT Mat3 rotate_z(const double angle, const units::AngleUnit units) {
  return rotate_z(units::to_radians(angle, units));
}

}  // namespace coords
}  // namespace oal