#ifndef OAL_COORDS_ROTATIONS_HPP_
#define OAL_COORDS_ROTATIONS_HPP_

#include "oal/core.hpp"
#include "oal/units.hpp"

namespace oal {
namespace coords {

/// @brief Compute a DCM representing a rotations about the x axis.
/// @param angle_rad Angle in radians to rotate by.
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 rotate_x(const double angle_rad);

/// @brief Compute a DCM representing a rotations about the x-axis.
/// @param angle Angle to rotate by.
/// @param units Units `angle` is in.
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 rotate_x(const double angle, const units::AngleUnit units);

/// @brief Compute a DCM representing a rotations about the y-axis.
/// @param angle_rad Angle in radians to rotate by.
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 rotate_y(const double angle_rad);

/// @brief Compute a DCM representing a rotations about the y-axis.
/// @param angle Angle to rotate by.
/// @param units Units `angle` is in.
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 rotate_y(const double angle, const units::AngleUnit units);

/// @brief Compute a DCM representing a rotations about the z-axis.
/// @param angle_rad Angle in radians to rotate by.
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 rotate_z(const double angle_rad);

/// @brief Compute a DCM representing a rotations about the z-axis.
/// @param angle Angle to rotate by.
/// @param units Units `angle` is in.
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 rotate_z(const double angle, const units::AngleUnit units);

/// @brief Order in which euler angle rotations are applied.
enum class RotationSequence {
  INTRINSIC_ZYX = 0,
  INTRINSIC_XZY = 1,
  INTRINSIC_YXZ = 2,
  INTRINSIC_YZX = 3,
  INTRINSIC_XYZ = 4,
  INTRINSIC_ZXY = 5,
  PROPER_XZX = 7,
  PROPER_XYX = 8,
  PROPER_YXY = 9,
  PROPER_YZY = 10,
  PROPER_ZYZ = 11,
  PROPER_ZXZ = 12,
  EXTRINSIC_ZYX = INTRINSIC_XYZ,
  EXTRINSIC_XZY = INTRINSIC_YZX,
  EXTRINSIC_YXZ = INTRINSIC_ZXY,
  EXTRINSIC_YZX = INTRINSIC_YZX,
  EXTRINSIC_XYZ = INTRINSIC_ZYX,
  EXTRINSIC_ZXY = INTRINSIC_ZXY,
  YPR = INTRINSIC_ZYX
};

/// @brief Compute a DCM from euler angles.
/// @param eulers_rad Intrinsic ZYX euler angles in radians.
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers_rad);

/// @brief Compute a DCM from euler angles.
/// @param eulers Intrinsic ZYX euler angles.
/// @param unit  Units `eulers` is in
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers,
                                const units::AngleUnit unit);

/// @brief Compute a DCM from euler angles.
/// @param eulers_rad Euler angles in radians.
/// @param sequence Rotation sequence euler angles are defined in.
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers_rad, 
                                const RotationSequence sequence);

/// @brief Compute a DCM from euler angles.
/// @param eulers Euler angles.
/// @param unit  Units `eulers` is in.
/// @param sequence Rotation sequence euler angles are defined in.
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers,
                                const units::AngleUnit unit,
                                const RotationSequence sequence);

OAL_EXPORT Mat3 dcm_from_eulers(const double yaw, const double pitch, const double roll);
OAL_EXPORT Mat3 dcm_from_eulers(const double yaw, const double pitch, const double roll, const units::AngleUnit unit);

}  // namespace coords
}  // namespace oal

#endif