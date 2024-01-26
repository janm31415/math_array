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
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] < 0 ? -a[i] : a[i];
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

////////////////////////////////
// operator sqrt
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> sqrt(const std::array<T, dim> a) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = static_cast<T>(sqrt(a[i]));
  return res;
}

template <class T>
std::array<T, 2> sqrt(const std::array<T, 2> a) {
  return { static_cast<T>(sqrt(a[0])), static_cast<T>(sqrt(a[1])) };
}

template <class T>
std::array<T, 3> sqrt(const std::array<T, 3> a) {
  return { static_cast<T>(sqrt(a[0])), static_cast<T>(sqrt(a[1])), static_cast<T>(sqrt(a[2])) };
}

template <class T>
std::array<T, 4> sqrt(const std::array<T, 4> a) {
  return { static_cast<T>(sqrt(a[0])), static_cast<T>(sqrt(a[1])), static_cast<T>(sqrt(a[2])), static_cast<T>(sqrt(a[3])) };
}

////////////////////////////////
// operator dot
////////////////////////////////

template <class T, std::size_t dim>
T dot(const std::array<T, dim> a, const std::array<T, dim> b) {
  T res = static_cast<T>(0);
  for (std::size_t i = 0; i < dim; ++i)
    res = res + static_cast<T>(a[i]*b[i]);
  return res;
}

template <class T>
T dot(const std::array<T, 2> a, const std::array<T, 2> b) {
  return static_cast<T>(a[0]*b[0] + a[1]*b[1]);
}

template <class T>
T dot(const std::array<T, 3> a, const std::array<T, 3> b) {
    return static_cast<T>(a[0]*b[0] + a[1]*b[1] + a[2]*b[2]);
}

template <class T>
T dot(const std::array<T, 4> a, const std::array<T, 4> b) {
  return static_cast<T>(a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3]);
}

////////////////////////////////
// operator length
////////////////////////////////

template <class T, std::size_t dim>
double length(const std::array<T, dim> a) {
  return sqrt(dot(a,a));
}

template <std::size_t dim>
float length(const std::array<float, dim> a) {
  return sqrt(dot(a,a));
}

////////////////////////////////
// operator distance
////////////////////////////////

template <class T, std::size_t dim>
double distance(const std::array<T, dim> a, const std::array<T, dim> b) {
  auto c = a-b;
  return sqrt(dot(c,c));
}

template <std::size_t dim>
float distance(const std::array<float, dim> a, const std::array<float, dim> b) {
  auto c = a-b;
  return sqrt(dot(c,c));
}

////////////////////////////////
// operator distance_sqr
////////////////////////////////

template <class T, std::size_t dim>
T distance_sqr(const std::array<T, dim> a, const std::array<T, dim> b) {
  auto c = a-b;
  return dot(c,c);
}

////////////////////////////////
// operator normalize
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> normalize(const std::array<T, dim> a) {
  T denom = static_cast<T>(sqrt(dot(a, a)));
  return denom != static_cast<T>(0) ? a / denom : a;
}

////////////////////////////////
// operator <
////////////////////////////////

template <class T>
bool operator < (const std::array<T, 2> a, const std::array<T, 2> b) {
  return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
}

template <class T>
bool operator < (const std::array<T, 3> a, const std::array<T, 3> b) {
  return (a[0] == b[0]) ? ((a[1] == b[1]) ? (a[2] < b[2]) : (a[1] < b[1])) : (a[0] < b[0]);
}

template <class T>
bool operator < (const std::array<T, 4> a, const std::array<T, 4> b) {
  return (a[0] == b[0]) ? ((a[1] == b[1]) ? (a[2] == b[2] ? a[3] < b[3] : a[2] < b[2]) : (a[1] < b[1])) : (a[0] < b[0]);
}

////////////////////////////////
// operator >
////////////////////////////////

template <class T>
bool operator > (const std::array<T, 2> a, const std::array<T, 2> b) {
  return (a[0] == b[0]) ? (b[1] < a[1]) : (b[0] < a[0]);
}

template <class T>
bool operator > (const std::array<T, 3> a, const std::array<T, 3> b) {
  return (a[0] == b[0]) ? ((a[1] == b[1]) ? (b[2] < a[2]) : (b[1] < a[1])) : (b[0] < a[0]);
}

template <class T>
bool operator > (const std::array<T, 4> a, const std::array<T, 4> b) {
  return (a[0] == b[0]) ? ((a[1] == b[1]) ? (a[2] == b[2] ? b[3] < a[3] : b[2] < a[2]) : (b[1] < a[1])) : (b[0] < a[0]);
}

////////////////////////////////
// operator ==
////////////////////////////////

template <class T>
bool operator == (const std::array<T, 2> a, const std::array<T, 2> b) {
  return (a[0] == b[0]) && (a[1] == b[1]);
}

template <class T>
bool operator == (const std::array<T, 3> a, const std::array<T, 3> b) {
  return (a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]);
}

template <class T>
bool operator == (const std::array<T, 4> a, const std::array<T, 4> b) {
  return (a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]) && (a[3] == b[3]);
}

////////////////////////////////
// operator !=
////////////////////////////////

template <class T>
bool operator != (const std::array<T, 2> a, const std::array<T, 2> b) {
  return (a[0] != b[0]) || (a[1] != b[1]);
}

template <class T>
bool operator != (const std::array<T, 3> a, const std::array<T, 3> b) {
  return (a[0] != b[0]) || (a[1] != b[1]) || (a[2] != b[2]);
}

template <class T>
bool operator != (const std::array<T, 4> a, const std::array<T, 4> b) {
  return (a[0] != b[0]) || (a[1] != b[1]) || (a[2] != b[2]) || (a[3] != b[3]);
}

////////////////////////////////
// operator <=
////////////////////////////////

template <class T>
bool operator <= (const std::array<T, 2> a, const std::array<T, 2> b) {
  return !(a > b);
}

template <class T>
bool operator <= (const std::array<T, 3> a, const std::array<T, 3> b) {
  return !(a > b);
}

template <class T>
bool operator <= (const std::array<T, 4> a, const std::array<T, 4> b) {
  return !(a > b);
}

////////////////////////////////
// operator >=
////////////////////////////////

template <class T>
bool operator >= (const std::array<T, 2> a, const std::array<T, 2> b) {
  return !(a < b);
}

template <class T>
bool operator >= (const std::array<T, 3> a, const std::array<T, 3> b) {
  return !(a < b);
}

template <class T>
bool operator >= (const std::array<T, 4> a, const std::array<T, 4> b) {
  return !(a < b);
}
