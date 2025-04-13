#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <limits>

#include "oal/units.hpp"


TEST_CASE("Degrees to radians for known values", "[units]") {
  using namespace oal;
  using Catch::Matchers::WithinULP;
  using Catch::Matchers::IsNaN;

  // Because unit conversion is just multiplication is should be within 1 ULP of the correct value

  // Check for all values at quarter turns
  REQUIRE_THAT(units::to_radians(0.0), WithinULP(0.0, 1));
  REQUIRE_THAT(units::to_radians(90.0), WithinULP(0.5 * pi, 1));
  REQUIRE_THAT(units::to_radians(180.0), WithinULP(pi, 1));
  REQUIRE_THAT(units::to_radians(270), WithinULP(1.5 * pi, 1));
  REQUIRE_THAT(units::to_radians(360.0), WithinULP(2 * pi, 1));

  // Ensure that angles greater than 360 degrees are supported
  REQUIRE_THAT(units::to_radians(360 + 90), WithinULP(2.5 * pi, 1));

  // Ensure negative angles are supported
  REQUIRE_THAT(units::to_radians(-90), WithinULP(-0.5 * pi, 1));

  // NaN should propagate
  REQUIRE_THAT(units::to_radians(std::numeric_limits<double>::quiet_NaN()), IsNaN());
}

TEST_CASE("Check to radians for a selection of units", "[units]") {
  using namespace oal;
  using Catch::Matchers::WithinULP;
  using Catch::Matchers::IsNaN;


  // Because unit conversion is just multiplication is should be within 1 ULP of the correct value
  REQUIRE_THAT(units::to_radians(90.0, units::DEGREES), WithinULP(0.5 * pi, 1));
  REQUIRE_THAT(units::to_radians(pi, units::RADIANS), WithinULP(pi, 1));
}

TEST_CASE("Radians to degrees for known values", "[units]") {
  using namespace oal;
  using Catch::Matchers::WithinULP;
  using Catch::Matchers::IsNaN;

  // Because unit conversion is just multiplication is should be within 1 ULP of the correct value

  // Check for all values at quarter turns
  REQUIRE_THAT(units::to_degrees(0.0), WithinULP(0.0, 1));
  REQUIRE_THAT(units::to_degrees(0.5 * pi), WithinULP(90.0, 1));
  REQUIRE_THAT(units::to_degrees(pi), WithinULP(180.0, 1));
  REQUIRE_THAT(units::to_degrees(1.5 * pi), WithinULP(270.0, 1));
  REQUIRE_THAT(units::to_degrees(2 * pi), WithinULP(360.0, 1));

  // Ensure that angles greater than 360 degrees are supported
  REQUIRE_THAT(units::to_degrees(2.5 * pi), WithinULP(360.0 + 90.0, 1));

  // Ensure negative angles are supported
  REQUIRE_THAT(units::to_degrees(-0.5 * pi), WithinULP(-90.0, 1));

  // NaN should propagate
  REQUIRE_THAT(units::to_degrees(std::numeric_limits<double>::quiet_NaN()), IsNaN());
}
