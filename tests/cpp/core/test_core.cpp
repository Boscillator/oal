#include <catch2/catch_test_macros.hpp>
#include "oal/core.hpp"

TEST_CASE("Sanity Check", "") {
  oal::hello();
  REQUIRE(true);
}
