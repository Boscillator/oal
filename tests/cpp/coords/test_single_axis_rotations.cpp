#include <catch2/catch_test_macros.hpp>

#include "../matchers.hpp"
#include "oal/coords/rotations.hpp"

TEST_CASE("Test rotate_{axis} family functions", "[coords]") {
  SECTION("rotate_x") {
    // Rotate coordinate system by 90 degrees about the x-axis, counter
    // clockwise
    const oal::Vec3 point = {0, 0, 1};

    const oal::Vec3 new_point = oal::coords::rotate_x(90, oal::units::DEGREES) * point;

    const oal::Vec3 expected_point{0, 1, 0};
    const double tolerance = 1e-12;

    REQUIRE_THAT(new_point,
                 oal::test_support::MatrixWithinAbs(expected_point, tolerance));
  }

  SECTION("rotate_y") {
    // Rotate coordinate system by 90 degrees counter clockwise about the y-axis
    const oal::Vec3 point = {0, 0, 1};

    const oal::Vec3 new_point = oal::coords::rotate_y(90, oal::units::DEGREES) * point;

    const oal::Vec3 expected_point{-1, 0, 0};
    const double tolerance = 1e-12;

    REQUIRE_THAT(new_point,
                 oal::test_support::MatrixWithinAbs(expected_point, tolerance));
  }

  SECTION("rotate_z") {
    // Rotating a point on the z-axis about the z-axis should result in the
    // identity matrix
    const oal::Vec3 point = {0, 0, 1};

    const oal::Vec3 new_point = oal::coords::rotate_z(90, oal::units::DEGREES) * point;

    const oal::Vec3 expected_point{0, 0, 1};
    const double tolerance = 1e-12;

    REQUIRE_THAT(new_point,
                 oal::test_support::MatrixWithinAbs(expected_point, tolerance));
  }
}
