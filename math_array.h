#pragma once

#include <array>
#include <cmath>

////////////////////////////////
// operator +
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator + (const std::array<T, dim>& a, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] + b[i];
  return res;
}

template <class T>
std::array<T, 2> operator + (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return { a[0] + b[0], a[1] + b[1] };
}

template <class T>
std::array<T, 3> operator + (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return { a[0] + b[0], a[1] + b[1], a[2] + b[2] };
}

template <class T>
std::array<T, 4> operator + (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return { a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3] };
}

template <class T, std::size_t dim>
std::array<T, dim> operator + (const std::array<T, dim>& a, const T s) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] + s;
  return res;
}

template <class T>
std::array<T, 2> operator + (const std::array<T, 2>& a, const T s) {
  return { a[0] + s, a[1] + s };
}

template <class T>
std::array<T, 3> operator + (const std::array<T, 3>& a, const T s) {
  return { a[0] + s, a[1] + s, a[2] + s };
}

template <class T>
std::array<T, 4> operator + (const std::array<T, 4>& a, const T s) {
  return { a[0] + s, a[1] + s, a[2] + s, a[3] + s };
}


template <class T, std::size_t dim>
std::array<T, dim> operator + (const T s, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = s + b[i];
  return res;
}

template <class T>
std::array<T, 2> operator + (const T s, const std::array<T, 2>& b) {
  return { s + b[0], s + b[1] };
}

template <class T>
std::array<T, 3> operator + (const T s, const std::array<T, 3>& b) {
  return { s + b[0], s + b[1], s + b[2] };
}

template <class T>
std::array<T, 4> operator + (const T s, const std::array<T, 4>& b) {
  return { s + b[0], s + b[1], s + b[2], s + b[3] };
}

////////////////////////////////
// operator -
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator - (const std::array<T, dim>& a, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] - b[i];
  return res;
}

template <class T>
std::array<T, 2> operator - (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return { a[0] - b[0], a[1] - b[1] };
}

template <class T>
std::array<T, 3> operator - (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return { a[0] - b[0], a[1] - b[1], a[2] - b[2] };
}

template <class T>
std::array<T, 4> operator - (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return { a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3] };
}

template <class T, std::size_t dim>
std::array<T, dim> operator - (const std::array<T, dim>& a, const T s) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] - s;
  return res;
}

template <class T>
std::array<T, 2> operator - (const std::array<T, 2>& a, const T s) {
  return { a[0] - s, a[1] - s };
}

template <class T>
std::array<T, 3> operator - (const std::array<T, 3>& a, const T s) {
  return { a[0] - s, a[1] - s, a[2] - s };
}

template <class T>
std::array<T, 4> operator - (const std::array<T, 4>& a, const T s) {
  return { a[0] - s, a[1] - s, a[2] - s, a[3] - s };
}


template <class T, std::size_t dim>
std::array<T, dim> operator - (const T s, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = s - b[i];
  return res;
}

template <class T>
std::array<T, 2> operator - (const T s, const std::array<T, 2>& b) {
  return { s - b[0], s - b[1] };
}

template <class T>
std::array<T, 3> operator - (const T s, const std::array<T, 3>& b) {
  return { s - b[0], s - b[1], s - b[2] };
}

template <class T>
std::array<T, 4> operator - (const T s, const std::array<T, 4>& b) {
  return { s - b[0], s - b[1], s - b[2], s - b[3] };
}

////////////////////////////////
// operator *
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator * (const std::array<T, dim>& a, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] * b[i];
  return res;
}

template <class T>
std::array<T, 2> operator * (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return { a[0] * b[0], a[1] * b[1] };
}

template <class T>
std::array<T, 3> operator * (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return { a[0] * b[0], a[1] * b[1], a[2] * b[2] };
}

template <class T>
std::array<T, 4> operator * (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return { a[0] * b[0], a[1] * b[1], a[2] * b[2], a[3] * b[3] };
}

template <class T, std::size_t dim>
std::array<T, dim> operator * (const std::array<T, dim>& a, const T s) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] * s;
  return res;
}

template <class T>
std::array<T, 2> operator * (const std::array<T, 2>& a, const T s) {
  return { a[0] * s, a[1] * s };
}

template <class T>
std::array<T, 3> operator * (const std::array<T, 3>& a, const T s) {
  return { a[0] * s, a[1] * s, a[2] * s };
}

template <class T>
std::array<T, 4> operator * (const std::array<T, 4>& a, const T s) {
  return { a[0] * s, a[1] * s, a[2] * s, a[3] * s };
}


template <class T, std::size_t dim>
std::array<T, dim> operator * (const T s, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = s * b[i];
  return res;
}

template <class T>
std::array<T, 2> operator * (const T s, const std::array<T, 2>& b) {
  return { s * b[0], s * b[1] };
}

template <class T>
std::array<T, 3> operator * (const T s, const std::array<T, 3>& b) {
  return { s * b[0], s * b[1], s * b[2] };
}

template <class T>
std::array<T, 4> operator * (const T s, const std::array<T, 4>& b) {
  return { s * b[0], s * b[1], s * b[2], s * b[3] };
}

////////////////////////////////
// operator /
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator / (const std::array<T, dim>& a, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] / b[i];
  return res;
}

template <class T>
std::array<T, 2> operator / (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return { a[0] / b[0], a[1] / b[1] };
}

template <class T>
std::array<T, 3> operator / (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return { a[0] / b[0], a[1] / b[1], a[2] / b[2] };
}

template <class T>
std::array<T, 4> operator / (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return { a[0] / b[0], a[1] / b[1], a[2] / b[2], a[3] / b[3] };
}

template <class T, std::size_t dim>
std::array<T, dim> operator / (const std::array<T, dim>& a, const T s) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] / s;
  return res;
}

template <class T>
std::array<T, 2> operator / (const std::array<T, 2>& a, const T s) {
  return { a[0] / s, a[1] / s };
}

template <class T>
std::array<T, 3> operator / (const std::array<T, 3>& a, const T s) {
  return { a[0] / s, a[1] / s, a[2] / s };
}

template <class T>
std::array<T, 4> operator / (const std::array<T, 4>& a, const T s) {
  return { a[0] / s, a[1] / s, a[2] / s, a[3] / s };
}


template <class T, std::size_t dim>
std::array<T, dim> operator / (const T s, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = s / b[i];
  return res;
}

template <class T>
std::array<T, 2> operator / (const T s, const std::array<T, 2>& b) {
  return { s / b[0], s / b[1] };
}

template <class T>
std::array<T, 3> operator / (const T s, const std::array<T, 3>& b) {
  return { s / b[0], s / b[1], s / b[2] };
}

template <class T>
std::array<T, 4> operator / (const T s, const std::array<T, 4>& b) {
  return { s / b[0], s / b[1], s / b[2], s / b[3] };
}

////////////////////////////////
// operator min
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> min(const std::array<T, dim>& a, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] < b[i] ? a[i] : b[i];
  return res;
}

template <class T>
std::array<T, 2> min(const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return { a[0] < b[0] ? a[0] : b[0], a[1] < b[1] ? a[1] : b[1] };
}

template <class T>
std::array<T, 3> min(const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return { a[0] < b[0] ? a[0] : b[0], a[1] < b[1] ? a[1] : b[1], a[2] < b[2] ? a[2] : b[2] };
}

template <class T>
std::array<T, 4> min(const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return { a[0] < b[0] ? a[0] : b[0], a[1] < b[1] ? a[1] : b[1], a[2] < b[2] ? a[2] : b[2], a[3] < b[3] ? a[3] : b[3] };
}

////////////////////////////////
// operator max
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> max(const std::array<T, dim>& a, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] < b[i] ? b[i] : a[i];
  return res;
}

template <class T>
std::array<T, 2> max(const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return { a[0] < b[0] ? b[0] : a[0], a[1] < b[1] ? b[1] : a[1] };
}

template <class T>
std::array<T, 3> max(const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return { a[0] < b[0] ? b[0] : a[0], a[1] < b[1] ? b[1] : a[1], a[2] < b[2] ? b[2] : a[2] };
}

template <class T>
std::array<T, 4> max(const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return { a[0] < b[0] ? b[0] : a[0], a[1] < b[1] ? b[1] : a[1], a[2] < b[2] ? b[2] : a[2], a[3] < b[3] ? b[3] : a[3] };
}

////////////////////////////////
// operator abs
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> abs(const std::array<T, dim>& a) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] < 0 ? -a[i] : a[i];
  return res;
}

template <class T>
std::array<T, 2> abs(const std::array<T, 2>& a) {
  return { a[0] < 0 ? -a[0] : a[0], a[1] < 0 ? -a[1] : a[1]};
}

template <class T>
std::array<T, 3> abs(const std::array<T, 3>& a) {
  return { a[0] < 0 ? -a[0] : a[0], a[1] < 0 ? -a[1] : a[1], a[2] < 0 ? -a[2] : a[2]};
}

template <class T>
std::array<T, 4> abs(const std::array<T, 4>& a) {
  return { a[0] < 0 ? -a[0] : a[0], a[1] < 0 ? -a[1] : a[1], a[2] < 0 ? -a[2] : a[2], a[3] < 0 ? -a[3] : a[3]};
}

template <std::size_t dim>
std::array<float, dim> abs(const std::array<float, dim>& a) {
  std::array<float, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = fabs(a[i]);
  return res;
}

inline std::array<float, 2> abs(const std::array<float, 2>& a) {
  return { fabs(a[0]), fabs(a[1])};
}

inline std::array<float, 3> abs(const std::array<float, 3>& a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2])};
}

inline std::array<float, 4> abs(const std::array<float, 4>& a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2]), fabs(a[3])};
}

template <std::size_t dim>
std::array<double, dim> abs(const std::array<double, dim>& a) {
  std::array<double, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = fabs(a[i]);
  return res;
}

inline std::array<double, 2> abs(const std::array<double, 2>& a) {
  return { fabs(a[0]), fabs(a[1])};
}

inline std::array<double, 3> abs(const std::array<double, 3>& a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2])};
}

inline std::array<double, 4> abs(const std::array<double, 4>& a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2]), fabs(a[3])};
}

template <std::size_t dim>
std::array<long double, dim> abs(const std::array<long double, dim>& a) {
  std::array<long double, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = fabs(a[i]);
  return res;
}

inline std::array<long double, 2> abs(const std::array<long double, 2>& a) {
  return { fabs(a[0]), fabs(a[1])};
}

inline std::array<long double, 3> abs(const std::array<long double, 3>& a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2])};
}

inline std::array<long double, 4> abs(const std::array<long double, 4>& a) {
  return { fabs(a[0]), fabs(a[1]), fabs(a[2]), fabs(a[3])};
}

////////////////////////////////
// operator sqrt
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> sqrt(const std::array<T, dim>& a) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = static_cast<T>(sqrt(a[i]));
  return res;
}

template <class T>
std::array<T, 2> sqrt(const std::array<T, 2>& a) {
  return { static_cast<T>(sqrt(a[0])), static_cast<T>(sqrt(a[1])) };
}

template <class T>
std::array<T, 3> sqrt(const std::array<T, 3>& a) {
  return { static_cast<T>(sqrt(a[0])), static_cast<T>(sqrt(a[1])), static_cast<T>(sqrt(a[2])) };
}

template <class T>
std::array<T, 4> sqrt(const std::array<T, 4>& a) {
  return { static_cast<T>(sqrt(a[0])), static_cast<T>(sqrt(a[1])), static_cast<T>(sqrt(a[2])), static_cast<T>(sqrt(a[3])) };
}

////////////////////////////////
// operator dot
////////////////////////////////

template <class T, std::size_t dim>
T dot(const std::array<T, dim>& a, const std::array<T, dim>& b) {
  T res = static_cast<T>(0);
  for (std::size_t i = 0; i < dim; ++i)
    res = res + static_cast<T>(a[i]*b[i]);
  return res;
}

template <class T>
T dot(const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return static_cast<T>(a[0]*b[0] + a[1]*b[1]);
}

template <class T>
T dot(const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return static_cast<T>(a[0]*b[0] + a[1]*b[1] + a[2]*b[2]);
}

template <class T>
T dot(const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return static_cast<T>(a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3]);
}

////////////////////////////////
// operator length
////////////////////////////////

template <class T, std::size_t dim>
double length(const std::array<T, dim>& a) {
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
double distance(const std::array<T, dim>& a, const std::array<T, dim>& b) {
  auto c = a-b;
  return sqrt(dot(c,c));
}

template <std::size_t dim>
float distance(const std::array<float, dim>& a, const std::array<float, dim>& b) {
  auto c = a-b;
  return sqrt(dot(c,c));
}

////////////////////////////////
// operator distance_sqr
////////////////////////////////

template <class T, std::size_t dim>
T distance_sqr(const std::array<T, dim>& a, const std::array<T, dim>& b) {
  auto c = a-b;
  return dot(c,c);
}

////////////////////////////////
// operator normalize
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> normalize(const std::array<T, dim>& a) {
  T denom = static_cast<T>(sqrt(dot(a, a)));
  return !(denom == static_cast<T>(0)) ? a / denom : a;
}

////////////////////////////////
// operator <
////////////////////////////////

template <class T>
bool operator < (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
}

template <class T>
bool operator < (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return (a[0] == b[0]) ? ((a[1] == b[1]) ? (a[2] < b[2]) : (a[1] < b[1])) : (a[0] < b[0]);
}

template <class T>
bool operator < (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return (a[0] == b[0]) ? ((a[1] == b[1]) ? (a[2] == b[2] ? a[3] < b[3] : a[2] < b[2]) : (a[1] < b[1])) : (a[0] < b[0]);
}

////////////////////////////////
// operator >
////////////////////////////////

template <class T>
bool operator > (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return (a[0] == b[0]) ? (b[1] < a[1]) : (b[0] < a[0]);
}

template <class T>
bool operator > (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return (a[0] == b[0]) ? ((a[1] == b[1]) ? (b[2] < a[2]) : (b[1] < a[1])) : (b[0] < a[0]);
}

template <class T>
bool operator > (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return (a[0] == b[0]) ? ((a[1] == b[1]) ? (a[2] == b[2] ? b[3] < a[3] : b[2] < a[2]) : (b[1] < a[1])) : (b[0] < a[0]);
}

////////////////////////////////
// operator ==
////////////////////////////////

template <class T>
bool operator == (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return (a[0] == b[0]) && (a[1] == b[1]);
}

template <class T>
bool operator == (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return (a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]);
}

template <class T>
bool operator == (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return (a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]) && (a[3] == b[3]);
}

////////////////////////////////
// operator !=
////////////////////////////////

template <class T>
bool operator != (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return (a[0] != b[0]) || (a[1] != b[1]);
}

template <class T>
bool operator != (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return (a[0] != b[0]) || (a[1] != b[1]) || (a[2] != b[2]);
}

template <class T>
bool operator != (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return (a[0] != b[0]) || (a[1] != b[1]) || (a[2] != b[2]) || (a[3] != b[3]);
}

////////////////////////////////
// operator <=
////////////////////////////////

template <class T>
bool operator <= (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return !(a > b);
}

template <class T>
bool operator <= (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return !(a > b);
}

template <class T>
bool operator <= (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return !(a > b);
}

////////////////////////////////
// operator >=
////////////////////////////////

template <class T>
bool operator >= (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return !(a < b);
}

template <class T>
bool operator >= (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return !(a < b);
}

template <class T>
bool operator >= (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return !(a < b);
}

////////////////////////////////
// operator cross
////////////////////////////////

template <class T>
std::array<T, 3> cross(const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return {a[1]*b[2] - a[2]*b[1], a[2]*b[0] - a[0]*b[2], a[0]*b[1] - a[1]*b[0]};
}

template <class T>
std::array<T, 4> cross(const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return {a[1]*b[2] - a[2]*b[1], a[2]*b[0] - a[0]*b[2], a[0]*b[1] - a[1]*b[0], static_cast<T>(0)};
}

////////////////////////////////
// unary operator +
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator + (const std::array<T, dim>& a) {
  return a;
}

////////////////////////////////
// unary operator -
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator - (const std::array<T, dim>& a) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = -a[i];
  return res;
}

template <class T>
std::array<T, 2> operator - (const std::array<T, 2>& a) {
  return { -a[0], -a[1]};
}

template <class T>
std::array<T, 3> operator - (const std::array<T, 3>& a) {
  return { -a[0], -a[1], -a[2]};
}

template <class T>
std::array<T, 4> operator - (const std::array<T, 4>& a) {
  return { -a[0], -a[1], -a[2], -a[3]};
}

////////////////////////////////
// min_horizontal
////////////////////////////////

template <class T, std::size_t dim>
T min_horizontal(const std::array<T, dim>& a) {
  if (a.empty())
    return static_cast<T>(0);
  T res = a[0];
  for (std::size_t i = 1; i < dim; ++i)
    res = a[i] < res ? a[i] : res;
  return res;
}

template <class T>
T min_horizontal(const std::array<T, 2>& a) {
  return a[0] < a[1] ? a[0] : a[1];
}

template <class T>
T min_horizontal(const std::array<T, 3>& a) {
  return a[0] < a[1] ? (a[0] < a[2] ? a[0] : a[2]) : (a[1] < a[2] ? a[1] : a[2]);
}

template <class T>
T min_horizontal(const std::array<T, 4>& a) {
  return a[0] < a[1] ? (a[0] < a[2] ? (a[0] < a[3] ? a[0] : a[3]) : (a[2] < a[3] ? a[2] : a[3])) : (a[1] < a[2] ? (a[1] < a[3] ? a[1] : a[3]) : (a[2] < a[3] ? a[2] : a[3]));
}

////////////////////////////////
// max_horizontal
////////////////////////////////

template <class T, std::size_t dim>
T max_horizontal(const std::array<T, dim>& a) {
  if (a.empty())
    return static_cast<T>(0);
  T res = a[0];
  for (std::size_t i = 1; i < dim; ++i)
    res = res < a[i] ? a[i] : res;
  return res;
}

template <class T>
T max_horizontal(const std::array<T, 2>& a) {
  return a[0] < a[1] ? a[1] : a[0];
}

template <class T>
T max_horizontal(const std::array<T, 3>& a) {
  return a[0] < a[1] ? (a[1] < a[2] ? a[2] : a[1]) : (a[0] < a[2] ? a[2] : a[0]);
}

template <class T>
T max_horizontal(const std::array<T, 4>& a) {
  return a[0] < a[1] ? (a[1] < a[2] ? (a[2] < a[3] ? a[3] : a[2]) : (a[1] < a[3] ? a[3] : a[1])) : (a[0] < a[2] ? (a[2] < a[3] ? a[3] : a[2]) : (a[0] < a[3] ? a[3] : a[0]));
}

////////////////////////////////
// operator unpacklo
////////////////////////////////

template <class T>
std::array<T, 4> unpacklo(const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return {a[0], b[0], a[1], b[1]};
}

////////////////////////////////
// operator unpackhi
////////////////////////////////

template <class T>
std::array<T, 4> unpackhi(const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return {a[2], b[2], a[3], b[3]};
}

////////////////////////////////
// operator transpose
////////////////////////////////

template <class T>
void transpose(std::array<T, 4>& r0, std::array<T, 4>& r1, std::array<T, 4>& r2, std::array<T, 4>& r3, const std::array<T, 4>& c0, const std::array<T, 4>& c1, const std::array<T, 4>& c2, const std::array<T, 4>& c3) {
  std::array<T, 4> l02 = unpacklo(c0, c2);
  std::array<T, 4> h02 = unpackhi(c0, c2);
  std::array<T, 4> l13 = unpacklo(c1, c3);
  std::array<T, 4> h13 = unpackhi(c1, c3);
  r0 = unpacklo(l02, l13);
  r1 = unpackhi(l02, l13);
  r2 = unpacklo(h02, h13);
  r3 = unpackhi(h02, h13);
}

////////////////////////////////
// array4x4
////////////////////////////////

template <class T>
struct array4x4
{
  union
  {
    std::array<T, 4> col[4];
    std::array<T, 16> f;
  };
  
  template <typename T1>
  T& operator [] (T1 i)
  {
    return f[i];
  }
  
  template <typename T1>
  T operator [] (T1 i) const
  {
    return f[i];
  }
  
  array4x4() {}
  array4x4(const std::array<T, 4>& col0, const std::array<T, 4>& col1, const std::array<T, 4>& col2, const std::array<T, 4>& col3) : col { col0, col1, col2, col3 } {}
  array4x4(const std::array<T, 16>& m) : f(m) {}
  array4x4(const T* m)
  {
    for (int i = 0; i < 16; ++i)
      f[i] = m[i];
  }
};

template <class T>
array4x4<T> get_identity()
{
  array4x4<T> m({{static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)}}, {{static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)}}, {{static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)}}, {{static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)}});
  return m;
}

template <class T>
array4x4<T> make_translation(const T x, const T y, const T z)
{
  array4x4<T> m({{static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)}}, {{static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)}}, {{static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)}}, {{static_cast<T>(x), static_cast<T>(y), static_cast<T>(z), static_cast<T>(1)}});
  return m;
}

template <class T>
array4x4<T> invert(const array4x4<T>& m)
{
  array4x4<T> out;
  T det;
  int i;
  
  out[0] = m[5] * m[10] * m[15] -
  m[5] * m[11] * m[14] -
  m[9] * m[6] * m[15] +
  m[9] * m[7] * m[14] +
  m[13] * m[6] * m[11] -
  m[13] * m[7] * m[10];
  
  out[4] = -m[4] * m[10] * m[15] +
  m[4] * m[11] * m[14] +
  m[8] * m[6] * m[15] -
  m[8] * m[7] * m[14] -
  m[12] * m[6] * m[11] +
  m[12] * m[7] * m[10];
  
  out[8] = m[4] * m[9] * m[15] -
  m[4] * m[11] * m[13] -
  m[8] * m[5] * m[15] +
  m[8] * m[7] * m[13] +
  m[12] * m[5] * m[11] -
  m[12] * m[7] * m[9];
  
  out[12] = -m[4] * m[9] * m[14] +
  m[4] * m[10] * m[13] +
  m[8] * m[5] * m[14] -
  m[8] * m[6] * m[13] -
  m[12] * m[5] * m[10] +
  m[12] * m[6] * m[9];
  
  out[1] = -m[1] * m[10] * m[15] +
  m[1] * m[11] * m[14] +
  m[9] * m[2] * m[15] -
  m[9] * m[3] * m[14] -
  m[13] * m[2] * m[11] +
  m[13] * m[3] * m[10];
  
  out[5] = m[0] * m[10] * m[15] -
  m[0] * m[11] * m[14] -
  m[8] * m[2] * m[15] +
  m[8] * m[3] * m[14] +
  m[12] * m[2] * m[11] -
  m[12] * m[3] * m[10];
  
  out[9] = -m[0] * m[9] * m[15] +
  m[0] * m[11] * m[13] +
  m[8] * m[1] * m[15] -
  m[8] * m[3] * m[13] -
  m[12] * m[1] * m[11] +
  m[12] * m[3] * m[9];
  
  out[13] = m[0] * m[9] * m[14] -
  m[0] * m[10] * m[13] -
  m[8] * m[1] * m[14] +
  m[8] * m[2] * m[13] +
  m[12] * m[1] * m[10] -
  m[12] * m[2] * m[9];
  
  out[2] = m[1] * m[6] * m[15] -
  m[1] * m[7] * m[14] -
  m[5] * m[2] * m[15] +
  m[5] * m[3] * m[14] +
  m[13] * m[2] * m[7] -
  m[13] * m[3] * m[6];
  
  out[6] = -m[0] * m[6] * m[15] +
  m[0] * m[7] * m[14] +
  m[4] * m[2] * m[15] -
  m[4] * m[3] * m[14] -
  m[12] * m[2] * m[7] +
  m[12] * m[3] * m[6];
  
  out[10] = m[0] * m[5] * m[15] -
  m[0] * m[7] * m[13] -
  m[4] * m[1] * m[15] +
  m[4] * m[3] * m[13] +
  m[12] * m[1] * m[7] -
  m[12] * m[3] * m[5];
  
  out[14] = -m[0] * m[5] * m[14] +
  m[0] * m[6] * m[13] +
  m[4] * m[1] * m[14] -
  m[4] * m[2] * m[13] -
  m[12] * m[1] * m[6] +
  m[12] * m[2] * m[5];
  
  out[3] = -m[1] * m[6] * m[11] +
  m[1] * m[7] * m[10] +
  m[5] * m[2] * m[11] -
  m[5] * m[3] * m[10] -
  m[9] * m[2] * m[7] +
  m[9] * m[3] * m[6];
  
  out[7] = m[0] * m[6] * m[11] -
  m[0] * m[7] * m[10] -
  m[4] * m[2] * m[11] +
  m[4] * m[3] * m[10] +
  m[8] * m[2] * m[7] -
  m[8] * m[3] * m[6];
  
  out[11] = -m[0] * m[5] * m[11] +
  m[0] * m[7] * m[9] +
  m[4] * m[1] * m[11] -
  m[4] * m[3] * m[9] -
  m[8] * m[1] * m[7] +
  m[8] * m[3] * m[5];
  
  out[15] = m[0] * m[5] * m[10] -
  m[0] * m[6] * m[9] -
  m[4] * m[1] * m[10] +
  m[4] * m[2] * m[9] +
  m[8] * m[1] * m[6] -
  m[8] * m[2] * m[5];
  
  det = m[0] * out[0] + m[1] * out[4] + m[2] * out[8] + m[3] * out[12];
  
  for (i = 0; i < 16; ++i)
    out[i] = out[i] / det;
  return out;
}

template <class T>
array4x4<T> matrix_matrix_multiply(const array4x4<T>& left, const array4x4<T>& right)
{
  array4x4<T> out;
  std::array<T, 4> r[4];
  transpose(r[0], r[1], r[2], r[3], left.col[0], left.col[1], left.col[2], left.col[3]);
  
  out[0] = dot(r[0], right.col[0]);
  out[1] = dot(r[1], right.col[0]);
  out[2] = dot(r[2], right.col[0]);
  out[3] = dot(r[3], right.col[0]);
  out[4] = dot(r[0], right.col[1]);
  out[5] = dot(r[1], right.col[1]);
  out[6] = dot(r[2], right.col[1]);
  out[7] = dot(r[3], right.col[1]);
  out[8] = dot(r[0], right.col[2]);
  out[9] = dot(r[1], right.col[2]);
  out[10] = dot(r[2], right.col[2]);
  out[11] = dot(r[3], right.col[2]);
  out[12] = dot(r[0], right.col[3]);
  out[13] = dot(r[1], right.col[3]);
  out[14] = dot(r[2], right.col[3]);
  out[15] = dot(r[3], right.col[3]);
  return out;
}

template <class T>
array4x4<T> frustum(T left, T right, T bottom, T top, T near_plane, T far_plane)
{
  array4x4<T> out(std::array<T, 4>(static_cast<T>(2) * near_plane / (right - left), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)),
                  std::array<T, 4>(static_cast<T>(0), static_cast<T>(-2) * near_plane / (top - bottom), static_cast<T>(0), static_cast<T>(0)),
                  std::array<T, 4>((right + left) / (right - left), -(top + bottom) / (top - bottom), -(far_plane + near_plane) / (far_plane - near_plane), -1.f),
                  std::array<T, 4>(static_cast<T>(0), static_cast<T>(0), -(static_cast<T>(2) * far_plane * near_plane) / (far_plane - near_plane), static_cast<T>(0)));
  return out;
}

template <class T>
array4x4<T> orthographic(T left, T right, T bottom, T top, T near_plane, T far_plane)
{
  array4x4<T> out(std::array<T, 4>(static_cast<T>(2) / (right - left), static_cast<T>(0), static_cast<T>(0), -(right + left) / (right - left)),
                  std::array<T, 4>(static_cast<T>(0), static_cast<T>(2) / (top - bottom), static_cast<T>(0), -(top + bottom) / (top - bottom)),
                  std::array<T, 4>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(-2) / (far_plane - near_plane), -(far_plane + near_plane) / (far_plane - near_plane)),
                  std::array<T, 4>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)));
  return out;
}
