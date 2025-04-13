#ifndef OAL_CORE_HPP_
#define OAL_CORE_HPP_

#include <Eigen/Core>


#include <utility>
// Unreachable macro from https://en.cppreference.com/w/cpp/utility/unreachable
#if defined(__cpp_lib_unreachable)
#define OAL_UNREACHABLE std::unreachable()
#elif defined(_MSC_VER) && !defined(__clang__)
#define OAL_UNREACHABLE __assume(false)
#else
#define OAL_UNREACHABLE __builtin_unreachable()
#endif
namespace oal {
  static constexpr double pi = EIGEN_PI;

  using Vec3 = Eigen::Vector3d;
  using Mat3 = Eigen::Matrix3d;

  void hello();
}

#endif