#pragma once

#include <array>

////////////////////////////////
// operator +
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator + (std::array<T, dim> a, std::array<T, dim> b) {
  std::array<T, dim> res(a);
  for (std::size_t i = 0; i < dim; ++i)
    res[i] += b[i];
  return res;
}

template <class T>
std::array<T, 2> operator + (std::array<T, 2> a, std::array<T, 2> b) {
  return { a[0] + b[0], a[1] + b[1] };
}

template <class T>
std::array<T, 3> operator + (std::array<T, 3> a, std::array<T, 3> b) {
  return { a[0] + b[0], a[1] + b[1], a[2] + b[2] };
}

template <class T>
std::array<T, 4> operator + (std::array<T, 4> a, std::array<T, 4> b) {
  return { a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3] };
}

////////////////////////////////
// operator -
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator - (std::array<T, dim> a, std::array<T, dim> b) {
  std::array<T, dim> res(a);
  for (std::size_t i = 0; i < dim; ++i)
    res[i] -= b[i];
  return res;
}

template <class T>
std::array<T, 2> operator - (std::array<T, 2> a, std::array<T, 2> b) {
  return { a[0] - b[0], a[1] - b[1] };
}

template <class T>
std::array<T, 3> operator - (std::array<T, 3> a, std::array<T, 3> b) {
  return { a[0] - b[0], a[1] - b[1], a[2] - b[2] };
}

template <class T>
std::array<T, 4> operator - (std::array<T, 4> a, std::array<T, 4> b) {
  return { a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3] };
}
