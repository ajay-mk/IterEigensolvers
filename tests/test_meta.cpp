#define CATCH_CONFIG_MAIN
#include <itersolvers/meta.h>
#include <catch2/catch_test_macros.hpp>

#include <complex>
#include <type_traits>

using namespace itersolvers::meta;

#define STATIC_ASSERT_AND_CHECK(X) \
  static_assert(X);                \
  CHECK(X);

TEST_CASE("meta", "[meta]") {
  SECTION("Numerics") {
    STATIC_ASSERT_AND_CHECK(is_complex_v<std::complex<double>>);
    STATIC_ASSERT_AND_CHECK(is_complex_v<std::complex<float>>);
    STATIC_ASSERT_AND_CHECK(is_scalar_v<int>);
    STATIC_ASSERT_AND_CHECK(is_scalar_v<float>);
    STATIC_ASSERT_AND_CHECK(is_numeric_v<int>)
    STATIC_ASSERT_AND_CHECK(is_numeric_v<double>);
    STATIC_ASSERT_AND_CHECK(is_numeric_v<std::complex<double>>);
  }
}
