//
// Created by Ajay Melekamburath on 11/22/24.
//

#ifndef META_H
#define META_H

#include <complex>
#include <concepts>
#include <type_traits>

namespace itersolvers::meta {
namespace detail {
/// @brief helper to implement other metafunctions
template <typename T>
concept is_type = true;

/// an alias for is_type<T>::value
template <typename T>
constexpr bool is_type_v = is_type<T>;
}  // namespace detail

/// @brief Concept that checks if a type is a specialization of std::complex
/// @tparam T a type
template <typename T>
concept is_complex = requires(T t) { std::complex<T>{}; };
/// an alias for is_complex<T>::value
template <typename T>
constexpr bool is_complex_v = is_complex<T>;

/// @brief Concept that checks if @tparam T is a floating point type
template <typename T>
concept is_floating_point = std::is_floating_point_v<T>;
/// an alias for is_floating_point<T>::value
template <typename T>
constexpr bool is_floating_point_v = is_floating_point<T>;

/// @brief Concept that checks if a type is numeric (arithmetic or complex
/// numbers).
/// @tparam T a type
template <typename T>
concept is_numeric = std::is_arithmetic_v<T> || requires(T t) {
  { std::complex<T>{} };
};
/// an alias for is_numeric<T>::value
template <typename T>
constexpr bool is_numeric_v = is_numeric<T>;

/// @brief Concept to check if T is a numeric but not a complex type.
/// @tparam T a type
template <typename T>
concept is_scalar =
    std::is_arithmetic_v<T> &&
    !std::is_same_v<std::remove_cv_t<T>, std::complex<std::remove_cv_t<T>>>;

/// an alias for is_scalar<T>::value
template <typename T>
constexpr bool is_scalar_v = is_scalar<T>;

/// @brief Concept to enable function overloads or templates when T is numeric.
template <typename T, typename U = void>
using enable_if_numeric_t = std::enable_if_t<is_numeric<T>, U>;
}  // namespace itersolvers::meta

#endif  // META_H
