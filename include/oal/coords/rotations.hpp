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
/// @param units Units `angle` is in
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 rotate_x(const double angle, const units::AngleUnit units);

/// @brief Compute a DCM representing a rotations about the y-axis.
/// @param angle_rad Angle in radians to rotate by.
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 rotate_y(const double angle_rad);

/// @brief Compute a DCM representing a rotations about the y-axis.
/// @param angle Angle to rotate by.
/// @param units Units `angle` is in
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 rotate_y(const double angle, const units::AngleUnit units);

/// @brief Compute a DCM representing a rotations about the z-axis.
/// @param angle_rad Angle in radians to rotate by.
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 rotate_z(const double angle_rad);

/// @brief Compute a DCM representing a rotations about the z-axis.
/// @param angle Angle to rotate by.
/// @param units Units `angle` is in
/// @return DCM. See `Coordinate Systems` manual page for conventions.
OAL_EXPORT Mat3 rotate_z(const double angle, const units::AngleUnit units);

OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers_rad);
OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers,
                                const units::AngleUnit unit);

}  // namespace coords
}  // namespace oal

#endif