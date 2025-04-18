#include <catch2/catch_test_macros.hpp>

#include "oal/coords/rotations.hpp"
#include "../matchers.hpp"

TEST_CASE("Test rotate_x", "[coords]") {
  const oal::Vec3 point = {0, 0, 1};
  
  // Rotate coordinate system by 90 degrees about the x-axis, counter clockwise
  const oal::Vec3 new_point = oal::coords::rotate_x(oal::pi/2) * point; 

  const oal::Vec3 expected_point {0, 1, 0};
  const double tolerance = 1e-12;

  REQUIRE_THAT(new_point, oal::test_support::MatrixWithinAbs(expected_point, tolerance));
}
