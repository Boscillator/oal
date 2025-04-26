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

OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers_rad) {
  return rotate_x(eulers_rad[2]) * rotate_y(eulers_rad[1]) *
         rotate_z(eulers_rad[0]);
}

OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers,
                                const units::AngleUnit units) {
  Vec3 eulers_rad = eulers * units::to_radians(1, units);
  return dcm_from_eulers(eulers_rad);
}

OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers_rad,
                                const RotationSequence sequence) {
  switch (sequence) {
    case RotationSequence::INTRINSIC_ZYX:
      return rotate_x(eulers_rad[2]) * rotate_y(eulers_rad[1]) *
             rotate_z(eulers_rad[0]);
    case RotationSequence::INTRINSIC_XZY:
      return rotate_y(eulers_rad[2]) * rotate_z(eulers_rad[1]) *
             rotate_x(eulers_rad[0]);
    case RotationSequence::INTRINSIC_YXZ:
      return rotate_z(eulers_rad[2]) * rotate_x(eulers_rad[1]) *
             rotate_y(eulers_rad[0]);
    case RotationSequence::INTRINSIC_YZX:
      return rotate_x(eulers_rad[2]) * rotate_z(eulers_rad[1]) *
             rotate_y(eulers_rad[0]);
    case RotationSequence::INTRINSIC_XYZ:
      return rotate_z(eulers_rad[2]) * rotate_y(eulers_rad[1]) *
             rotate_x(eulers_rad[0]);
    case RotationSequence::INTRINSIC_ZXY:
      return rotate_y(eulers_rad[2]) * rotate_x(eulers_rad[1]) *
             rotate_z(eulers_rad[0]);
    case RotationSequence::PROPER_XZX:
      return rotate_x(eulers_rad[2]) * rotate_z(eulers_rad[1]) *
             rotate_x(eulers_rad[0]);
    case RotationSequence::PROPER_XYX:
      return rotate_x(eulers_rad[2]) * rotate_y(eulers_rad[1]) *
             rotate_x(eulers_rad[0]);
    case RotationSequence::PROPER_YXY:
      return rotate_y(eulers_rad[2]) * rotate_x(eulers_rad[1]) *
             rotate_y(eulers_rad[0]);
    case RotationSequence::PROPER_YZY:
      return rotate_y(eulers_rad[2]) * rotate_z(eulers_rad[1]) *
             rotate_y(eulers_rad[0]);
    case RotationSequence::PROPER_ZYZ:
      return rotate_z(eulers_rad[2]) * rotate_y(eulers_rad[1]) *
             rotate_z(eulers_rad[0]);
    case RotationSequence::PROPER_ZXZ:
      return rotate_z(eulers_rad[2]) * rotate_x(eulers_rad[1]) *
             rotate_z(eulers_rad[0]);
    default:
      OAL_UNREACHABLE;
  }
}

OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers,
                                const units::AngleUnit units,
                                const RotationSequence sequence) {
  const Vec3 eulers_rad = eulers * units::to_radians(1, units);
  return dcm_from_eulers(eulers_rad, sequence);
}

OAL_EXPORT Mat3 dcm_from_eulers(const double yaw,
                                const double pitch,
                                const double roll) {
  const Vec3 eulers = {yaw, pitch, roll};

  // Defaults to intrinsic ZYX, radians
  return dcm_from_eulers(eulers);
}

OAL_EXPORT Mat3 dcm_from_eulers(const double yaw,
                                const double pitch,
                                const double roll,
                                const units::AngleUnit units) {
  const Vec3 eulers = {yaw, pitch, roll};

  // Defaults to intrinsic ZYX
  return dcm_from_eulers(eulers, units);
}

}  // namespace coords
}  // namespace oal