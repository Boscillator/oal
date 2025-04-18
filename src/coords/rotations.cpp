#include "oal/coords/rotations.hpp"

namespace oal {
namespace coords {

Mat3 rotate_x(const double angle_rad) { 
  const double s_theta = std::sin(angle_rad);
  const double c_theta = std::cos(angle_rad);
  return (Mat3() << 1, 0, 0, 0, c_theta, s_theta, 0, -s_theta, c_theta).finished();
}


// Mat3 rotate_y(const double angle_rad) { return Mat3(); }

// Mat3 rotate_z(const double angle_rad) { return Mat3(); }

// Mat3 dcm_from_eulers(const Vec3Ref eulers_rad) { 
//   return Mat3();
// }

// Mat3 dcm_from_eulers(const Vec3Ref eulers_rad, const units::AngleUnit units) {
//   return Mat3();
// }

}
}  // namespace oal