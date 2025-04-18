#include <Eigen/Eigen>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <catch2/matchers/catch_matchers_templated.hpp>
#include <sstream>

namespace oal {
namespace test_support {

template <typename T>
struct MatrixWithinAbsMatcher : public Catch::Matchers::MatcherGenericBase {
 public:
  MatrixWithinAbsMatcher(const T& target, double tolerance)
      : target_(target), tolerance_(tolerance) {}

  bool match(const Eigen::Ref<const Eigen::MatrixXd> other) const {
    if (other.rows() != target_.rows()) return false;
    if (other.cols() != target_.cols()) return false;

    for (int row = 0; row < target_.rows(); row++) {
      for (int col = 0; col < target_.cols(); col++) {
        if (std::abs(target_(row, col) - other(row, col)) > tolerance_) {
          return false;
        }
      }
    }

    return true;
  }

  std::string describe() const override {
    std::stringstream ss;
    ss << "ApproxEquals: " << target_;
    return ss.str();
  }

 private:
  T target_;
  double tolerance_;
};

template <typename T>
auto MatrixWithinAbs(const T& target, const double tolerance)
    -> MatrixWithinAbsMatcher<T> {
  return MatrixWithinAbsMatcher(target, tolerance);
}

}  // namespace test_support
}  // namespace oal
