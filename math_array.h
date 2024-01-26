#pragma once

#include <array>
#include <cmath>

////////////////////////////////
// operator +
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator + (const std::array<T, dim> a, const std::array<T, dim> b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] + b[i];
  return res;
}

template <class T>
std::array<T, 2> operator + (const std::array<T, 2> a, const std::array<T, 2> b) {
  return { a[0] + b[0], a[1] + b[1] };
}

template <class T>
std::array<T, 3> operator + (const std::array<T, 3> a, const std::array<T, 3> b) {
  return { a[0] + b[0], a[1] + b[1], a[2] + b[2] };
}

template <class T>
std::array<T, 4> operator + (const std::array<T, 4> a, const std::array<T, 4> b) {
  return { a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3] };
}

template <class T, std::size_t dim>
std::array<T, dim> operator + (const std::array<T, dim> a, const T s) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] + s;
  return res;
}

template <class T>
std::array<T, 2> operator + (const std::array<T, 2> a, const T s) {
  return { a[0] + s, a[1] + s };
}

template <class T>
std::array<T, 3> operator + (const std::array<T, 3> a, const T s) {
  return { a[0] + s, a[1] + s, a[2] + s };
}

template <class T>
std::array<T, 4> operator + (const std::array<T, 4> a, const T s) {
  return { a[0] + s, a[1] + s, a[2] + s, a[3] + s };
}


template <class T, std::size_t dim>
std::array<T, dim> operator + (const T s, const std::array<T, dim> b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = s + b[i];
  return res;
}

template <class T>
std::array<T, 2> operator + (const T s, const std::array<T, 2> b) {
  return { s + b[0], s + b[1] };
}

template <class T>
std::array<T, 3> operator + (const T s, const std::array<T, 3> b) {
  return { s + b[0], s + b[1], s + b[2] };
}

template <class T>
std::array<T, 4> operator + (const T s, const std::array<T, 4> b) {
  return { s + b[0], s + b[1], s + b[2], s + b[3] };
}

////////////////////////////////
// operator -
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator - (const std::array<T, dim> a, const std::array<T, dim> b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] - b[i];
  return res;
}

template <class T>
std::array<T, 2> operator - (const std::array<T, 2> a, const std::array<T, 2> b) {
  return { a[0] - b[0], a[1] - b[1] };
}

template <class T>
std::array<T, 3> operator - (const std::array<T, 3> a, const std::array<T, 3> b) {
  return { a[0] - b[0], a[1] - b[1], a[2] - b[2] };
}

template <class T>
std::array<T, 4> operator - (const std::array<T, 4> a, const std::array<T, 4> b) {
  return { a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3] };
}

template <class T, std::size_t dim>
std::array<T, dim> operator - (const std::array<T, dim> a, const T s) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] - s;
  return res;
}

template <class T>
std::array<T, 2> operator - (const std::array<T, 2> a, const T s) {
  return { a[0] - s, a[1] - s };
}

template <class T>
std::array<T, 3> operator - (const std::array<T, 3> a, const T s) {
  return { a[0] - s, a[1] - s, a[2] - s };
}

template <class T>
std::array<T, 4> operator - (const std::array<T, 4> a, const T s) {
  return { a[0] - s, a[1] - s, a[2] - s, a[3] - s };
}


template <class T, std::size_t dim>
std::array<T, dim> operator - (const T s, const std::array<T, dim> b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = s - b[i];
  return res;
}

template <class T>
std::array<T, 2> operator - (const T s, const std::array<T, 2> b) {
  return { s - b[0], s - b[1] };
}

template <class T>
std::array<T, 3> operator - (const T s, const std::array<T, 3> b) {
  return { s - b[0], s - b[1], s - b[2] };
}

template <class T>
std::array<T, 4> operator - (const T s, const std::array<T, 4> b) {
  return { s - b[0], s - b[1], s - b[2], s - b[3] };
}

////////////////////////////////
// operator *
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator * (const std::array<T, dim> a, const std::array<T, dim> b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] * b[i];
  return res;
}

template <class T>
std::array<T, 2> operator * (const std::array<T, 2> a, const std::array<T, 2> b) {
  return { a[0] * b[0], a[1] * b[1] };
}

template <class T>
std::array<T, 3> operator * (const std::array<T, 3> a, const std::array<T, 3> b) {
  return { a[0] * b[0], a[1] * b[1], a[2] * b[2] };
}

template <class T>
std::array<T, 4> operator * (const std::array<T, 4> a, const std::array<T, 4> b) {
  return { a[0] * b[0], a[1] * b[1], a[2] * b[2], a[3] * b[3] };
}

template <class T, std::size_t dim>
std::array<T, dim> operator * (const std::array<T, dim> a, const T s) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] * s;
  return res;
}

template <class T>
std::array<T, 2> operator * (const std::array<T, 2> a, const T s) {
  return { a[0] * s, a[1] * s };
}

template <class T>
std::array<T, 3> operator * (const std::array<T, 3> a, const T s) {
  return { a[0] * s, a[1] * s, a[2] * s };
}

template <class T>
std::array<T, 4> operator * (const std::array<T, 4> a, const T s) {
  return { a[0] * s, a[1] * s, a[2] * s, a[3] * s };
}


template <class T, std::size_t dim>
std::array<T, dim> operator * (const T s, const std::array<T, dim> b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = s * b[i];
  return res;
}

template <class T>
std::array<T, 2> operator * (const T s, const std::array<T, 2> b) {
  return { s * b[0], s * b[1] };
}

template <class T>
std::array<T, 3> operator * (const T s, const std::array<T, 3> b) {
  return { s * b[0], s * b[1], s * b[2] };
}

template <class T>
std::array<T, 4> operator * (const T s, const std::array<T, 4> b) {
  return { s * b[0], s * b[1], s * b[2], s * b[3] };
}

////////////////////////////////
// operator /
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator / (const std::array<T, dim> a, const std::array<T, dim> b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] / b[i];
  return res;
}

template <class T>
std::array<T, 2> operator / (const std::array<T, 2> a, const std::array<T, 2> b) {
  return { a[0] / b[0], a[1] / b[1] };
}

template <class T>
std::array<T, 3> operator / (const std::array<T, 3> a, const std::array<T, 3> b) {
  return { a[0] / b[0], a[1] / b[1], a[2] / b[2] };
}

template <class T>
std::array<T, 4> operator / (const std::array<T, 4> a, const std::array<T, 4> b) {
  return { a[0] / b[0], a[1] / b[1], a[2] / b[2], a[3] / b[3] };
}

template <class T, std::size_t dim>
std::array<T, dim> operator / (const std::array<T, dim> a, const T s) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] / s;
  return res;
}

template <class T>
std::array<T, 2> operator / (const std::array<T, 2> a, const T s) {
  return { a[0] / s, a[1] / s };
}

template <class T>
std::array<T, 3> operator / (const std::array<T, 3> a, const T s) {
  return { a[0] / s, a[1] / s, a[2] / s };
}

template <class T>
std::array<T, 4> operator / (const std::array<T, 4> a, const T s) {
  return { a[0] / s, a[1] / s, a[2] / s, a[3] / s };
}


template <class T, std::size_t dim>
std::array<T, dim> operator / (const T s, const std::array<T, dim> b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = s / b[i];
  return res;
}

template <class T>
std::array<T, 2> operator / (const T s, const std::array<T, 2> b) {
  return { s / b[0], s / b[1] };
}

template <class T>
std::array<T, 3> operator / (const T s, const std::array<T, 3> b) {
  return { s / b[0], s / b[1], s / b[2] };
}

template <class T>
std::array<T, 4> operator / (const T s, const std::array<T, 4> b) {
  return { s / b[0], s / b[1], s / b[2], s / b[3] };
}

////////////////////////////////
// operator min
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> min(const std::array<T, dim> a, const std::array<T, dim> b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] < b[i] ? a[i] : b[i];
  return res;
}

template <class T>
std::array<T, 2> min(const std::array<T, 2> a, const std::array<T, 2> b) {
  return { a[0] < b[0] ? a[0] : b[0], a[1] < b[1] ? a[1] : b[1] };
}

template <class T>
std::array<T, 3> min(const std::array<T, 3> a, const std::array<T, 3> b) {
  return { a[0] < b[0] ? a[0] : b[0], a[1] < b[1] ? a[1] : b[1], a[2] < b[2] ? a[2] : b[2] };
}

template <class T>
std::array<T, 4> min(const std::array<T, 4> a, const std::array<T, 4> b) {
  return { a[0] < b[0] ? a[0] : b[0], a[1] < b[1] ? a[1] : b[1], a[2] < b[2] ? a[2] : b[2], a[3] < b[3] ? a[3] : b[3] };
}

////////////////////////////////
// operator max
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> max(const std::array<T, dim> a, const std::array<T, dim> b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] < b[i] ? b[i] : a[i];
  return res;
}

template <class T>
std::array<T, 2> max(const std::array<T, 2> a, const std::array<T, 2> b) {
  return { a[0] < b[0] ? b[0] : a[0], a[1] < b[1] ? b[1] : a[1] };
}

template <class T>
std::array<T, 3> max(const std::array<T, 3> a, const std::array<T, 3> b) {
  return { a[0] < b[0] ? b[0] : a[0], a[1] < b[1] ? b[1] : a[1], a[2] < b[2] ? b[2] : a[2] };
}

template <class T>
std::array<T, 4> max(const std::array<T, 4> a, const std::array<T, 4> b) {
  return { a[0] < b[0] ? b[0] : a[0], a[1] < b[1] ? b[1] : a[1], a[2] < b[2] ? b[2] : a[2], a[3] < b[3] ? b[3] : a[3] };
}

////////////////////////////////
// operator abs
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> abs(const std::array<T, dim> a) {
  std::array<T, dim> res(a);
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = res[i] < 0 ? -res[i] : res[i];
  return res;
}

template <class T>
std::array<T, 2> abs(const std::array<T, 2> a) {
  return { a[0] < 0 ? -a[0] : a[0], a[1] < 0 ? -a[1] : a[1]};
}

template <class T>
std::array<T, 3> abs(const std::array<T, 3> a) {
  return { a[0] < 0 ? -a[0] : a[0], a[1] < 0 ? -a[1] : a[1], a[2] < 0 ? -a[2] : a[2]};
}

template <class T>
std::array<T, 4> abs(const std::array<T, 4> a) {
  return { a[0] < 0 ? -a[0] : a[0], a[1] < 0 ? -a[1] : a[1], a[2] < 0 ? -a[2] : a[2], a[3] < 0 ? -a[3] : a[3]};
}

template <std::size_t dim>
std::array<float, dim> abs(const std::array<float, dim> a) {
  std::array<float, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = fabs(a[i]);
  return res;
}

inline std::array<float, 2> abs(const std::array<float, 2> a) {
  return { fabs(a[0]), fabs(a[1])};
}

inline std::array<float, 3> abs(const std::array<float, 3> a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2])};
}

inline std::array<float, 4> abs(const std::array<float, 4> a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2]), fabs(a[3])};
}

template <std::size_t dim>
std::array<double, dim> abs(const std::array<double, dim> a) {
  std::array<double, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = fabs(a[i]);
  return res;
}

inline std::array<double, 2> abs(const std::array<double, 2> a) {
  return { fabs(a[0]), fabs(a[1])};
}

inline std::array<double, 3> abs(const std::array<double, 3> a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2])};
}

inline std::array<double, 4> abs(const std::array<double, 4> a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2]), fabs(a[3])};
}

template <std::size_t dim>
std::array<long double, dim> abs(const std::array<long double, dim> a) {
  std::array<long double, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = fabs(a[i]);
  return res;
}

inline std::array<long double, 2> abs(const std::array<long double, 2> a) {
  return { fabs(a[0]), fabs(a[1])};
}

inline std::array<long double, 3> abs(const std::array<long double, 3> a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2])};
}

inline std::array<long double, 4> abs(const std::array<long double, 4> a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2]), fabs(a[3])};
}
