#ifndef OAL_CORE_HPP_
#define OAL_CORE_HPP_

#include <Eigen/Core>
#include <utility>


#include "oal/export.h"

// Unreachable macro from https://en.cppreference.com/w/cpp/utility/unreachable
#if defined(__cpp_lib_unreachable)
#define OAL_UNREACHABLE std::unreachable()
#elif defined(_MSC_VER) && !defined(__clang__)
#define OAL_UNREACHABLE __assume(false)
#else
#define OAL_UNREACHABLE __builtin_unreachable()
#endif
namespace oal {


#if defined(__cpp_lib_math_constants)
#include <numbers>
static constexpr double pi = std::numbers::pi;
#else
// Avoid defining _USE_MATH_DEFINES
static constexpr double pi = 3.14159265358979323846;
#endif

#if defined(OAL_PYTHON)
template<typename T>
using Ref = Eigen::Ref<T, 0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>>;
#else
template<typename T>
using Ref = Eigen::Ref<T>;
#endif

using Vec3 = Eigen::Vector3d;
using Vec3Ref = Ref<Vec3>;
using Mat3 = Eigen::Matrix3d;

OAL_EXPORT void hello();
}  // namespace oal

#endif