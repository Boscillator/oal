#ifndef OAL_COORDS_ROTATIONS_HPP_
#define OAL_COORDS_ROTATIONS_HPP_

#include "oal/core.hpp"
#include "oal/units.hpp"

namespace oal {
namespace coords {

OAL_EXPORT Mat3 rotate_x(const double angle_rad);
OAL_EXPORT Mat3 rotate_y(const double angle_rad);
OAL_EXPORT Mat3 rotate_z(const double angle_rad);

OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers_rad);
OAL_EXPORT Mat3 dcm_from_eulers(const Vec3Ref eulers,
                                const units::AngleUnit unit);

}  // namespace coords
}  // namespace oal

#endif