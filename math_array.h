/*
 MIT License
 
 Copyright (c) 2024 Jan Maes
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */
#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <vector>

////////////////////////////////
// INTERFACE
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator + (const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> operator + (const std::array<T, dim>& a, const T s);

template <class T, std::size_t dim>
std::array<T, dim> operator + (const T s, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> operator - (const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> operator - (const std::array<T, dim>& a, const T s);

template <class T, std::size_t dim>
std::array<T, dim> operator - (const T s, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> operator * (const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> operator * (const std::array<T, dim>& a, const T s);

template <class T, std::size_t dim>
std::array<T, dim> operator * (const T s, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> operator / (const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> operator / (const std::array<T, dim>& a, const T s);

template <class T, std::size_t dim>
std::array<T, dim> operator / (const T s, const std::array<T, dim>& b) ;

template <class T, std::size_t dim>
std::array<T, dim> operator + (const std::array<T, dim>& a);

template <class T, std::size_t dim>
std::array<T, dim> operator - (const std::array<T, dim>& a);

template <class T, std::size_t dim>
std::array<T, dim> operator & (const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> operator & (const std::array<T, dim>& a, const T s);

template <class T, std::size_t dim>
std::array<T, dim> operator & (const T s, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> operator | (const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> operator | (const std::array<T, dim>& a, const T s);

template <class T, std::size_t dim>
std::array<T, dim> operator | (const T s, const std::array<T, dim>& b);

namespace ma
{
template <class T, std::size_t dim>
std::array<T, dim> min(const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> max(const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> abs(const std::array<T, dim>& a);

template <class T, std::size_t dim>
std::array<T, dim> sqrt(const std::array<T, dim>& a);

template <class T, std::size_t dim>
std::array<int, dim> less(const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<int, dim> leq(const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<int, dim> greater(const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<int, dim> geq(const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<int, dim> eq(const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<int, dim> neq(const std::array<T, dim>& a, const std::array<T, dim>& b);

template <std::size_t dim>
int any(const std::array<int, dim>& b);

template <std::size_t dim>
int none(const std::array<int, dim>& b);

template <class T, std::size_t dim>
T dot(const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
double length(const std::array<T, dim>& a);

template <std::size_t dim>
float length(const std::array<float, dim> a);

template <class T, std::size_t dim>
double distance(const std::array<T, dim>& a, const std::array<T, dim>& b);

template <std::size_t dim>
float distance(const std::array<float, dim>& a, const std::array<float, dim>& b);

template <class T, std::size_t dim>
T distance_sqr(const std::array<T, dim>& a, const std::array<T, dim>& b);

template <class T, std::size_t dim>
std::array<T, dim> normalize(const std::array<T, dim>& a);

template <class T>
std::array<T, 3> cross(const std::array<T, 3>& a, const std::array<T, 3>& b);

template <class T>
std::array<T, 4> cross(const std::array<T, 4>& a, const std::array<T, 4>& b);

template <class T, std::size_t dim>
T min_horizontal(const std::array<T, dim>& a);

template <class T, std::size_t dim>
T max_horizontal(const std::array<T, dim>& a);

template <class T>
std::array<T, 4> unpacklo(const std::array<T, 4>& a, const std::array<T, 4>& b);

template <class T>
std::array<T, 4> unpackhi(const std::array<T, 4>& a, const std::array<T, 4>& b) ;

template <class T>
void transpose(std::array<T, 4>& r0, std::array<T, 4>& r1, std::array<T, 4>& r2, std::array<T, 4>& r3, const std::array<T, 4>& c0, const std::array<T, 4>& c1, const std::array<T, 4>& c2, const std::array<T, 4>& c3);

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
array4x4<T> get_identity();

template <class T>
array4x4<T> make_translation(const T x, const T y, const T z);

template <class T>
array4x4<T> invert(const array4x4<T>& m);

template <class T>
array4x4<T> matrix_matrix_multiply(const array4x4<T>& left, const array4x4<T>& right);

template <class T>
array4x4<T> frustum(T left, T right, T bottom, T top, T near_plane, T far_plane);

template <class T>
array4x4<T> orthographic(T left, T right, T bottom, T top, T near_plane, T far_plane);

template <class T>
void solve_roll_pitch_yaw_transformation(T& rx, T& ry, T& rz, T& tx, T& ty, T& tz, const array4x4<T>& m);

template <class T>
array4x4<T> compute_from_roll_pitch_yaw_transformation(T rx, T ry, T rz, T tx, T ty, T tz);

template <class T>
array4x4<T> quaternion_to_rotation(const std::array<T, 4>& quaternion);

template <class T>
std::array<T, 4> quaternion_multiply(const std::array<T, 4>& q1, const std::array<T, 4>& q2);

template <class T>
std::array<T, 4> quaternion_axis(const std::array<T, 4>& q);

template <class T>
float quaternion_angle(const std::array<T, 4>& q);

template <class T>
std::array<T, 4> quaternion_conjugate(const std::array<T, 4>& quaternion);

template <class T>
std::array<T, 4> quaternion_inverse(const std::array<T, 4>& quaternion);

template <class T>
std::array<T, 4> quaternion_normalize(const std::array<T, 4>& quaternion);

template <class T>
array4x4<T> look_at(const std::array<T, 4>& eye, const std::array<T, 4>& center, const std::array<T, 4>& up);

template <class T>
array4x4<T> look_at(const std::array<T, 3>& eye, const std::array<T, 3>& center, const std::array<T, 3>& up);

template <class T>
void get_eye_center_up(std::array<T, 3>& eye, std::array<T, 3>& center, std::array<T, 3>& up, const array4x4<T>& transform);

template <class T>
void get_eye_center_up(std::array<T, 4>& eye, std::array<T, 4>& center, std::array<T, 4>& up, const array4x4<T>& transform);

template <class T>
std::array<T, 4> roll_pitch_yaw_to_quaternion(T rx, T ry, T rz);

template <class T>
std::array<T, 4> rotation_to_quaternion(const array4x4<T>& m);

template <class T>
array4x4<T> transpose(const array4x4<T>& m);

template <class T>
array4x4<T> invert_orthonormal(const array4x4<T>& m);

template <class T>
std::array<T, 4> matrix_vector_multiply(const array4x4<T>& m, const std::array<T, 4>& v);

template <class T>
array4x4<T> operator + (const array4x4<T>& left, const array4x4<T>& right);

template <class T>
array4x4<T> operator - (const array4x4<T>& left, const array4x4<T>& right);

template <class T>
array4x4<T> operator + (const array4x4<T>& a);

template <class T>
array4x4<T> operator - (const array4x4<T>& a);

template <class T>
array4x4<T> operator / (const array4x4<T>& left, const T value);

template <class T>
array4x4<T> operator / (const T value, const array4x4<T>& right);

template <class T>
array4x4<T> operator * (const array4x4<T>& left, const T value);

template <class T>
array4x4<T> operator * (const T value, const array4x4<T>& right);

template <class T>
array4x4<T> make_identity();

template <class T>
array4x4<T> make_transformation(const std::array<T, 4>& origin, const std::array<T, 4>& x_axis, const std::array<T, 4>& y_axis, const std::array<T, 4>& z_axis);

template <class T>
array4x4<T> make_rotation(const std::array<T, 4>& position, const std::array<T, 4>& dir, T angle_radians);

template <class T>
array4x4<T> make_scale3d(T scale_x, T scale_y, T scale_z);

template <class T>
array4x4<T> make_translation(const std::array<T, 3>& translation);

template <class T>
array4x4<T> make_translation(const std::array<T, 4>& translation);

template <class T>
std::array<T, 4> get_translation(const array4x4<T>& matrix);

template <class T>
void set_x_axis(array4x4<T>& matrix, const std::array<T, 4>& x);

template <class T>
void set_y_axis(array4x4<T>& matrix, const std::array<T, 4>& y);

template <class T>
void set_z_axis(array4x4<T>& matrix, const std::array<T, 4>& z);

template <class T>
void set_translation(array4x4<T>& matrix, const std::array<T, 4>& t);

template <class T>
std::array<T, 4> get_x_axis(const array4x4<T>& matrix);

template <class T>
std::array<T, 4> get_y_axis(const array4x4<T>& matrix);

template <class T>
std::array<T, 4> get_z_axis(const array4x4<T>& matrix);

template <class T>
std::array<T, 3> transform_point(const array4x4<T>& matrix, const std::array<T, 3>& point);

template <class T>
std::array<T, 3> transform_direction(const array4x4<T>& matrix, const std::array<T, 3>& dir);

template <class T, std::size_t dim>
class array_tree
{
public:
  array_tree();
  uint64_t find_nearest(T& distance_sqr, const std::array<T, dim>& pt) const;
  
  template <class Iter>
  void build_tree(Iter first, Iter last);
  
  bool empty() const;
  
private:
  struct aabb_node
  {
    aabb_node();
    aabb_node(const aabb_node& left, const aabb_node& right) ;
    T distance_sqr(const std::array<T, dim>& pt) const;
    
    std::array<T, dim> _min, _max;
    uint64_t _tag;
  };
  
  struct array_tree_node
  {
    aabb_node _node;
    uint64_t _child_1, _child_2;
  };
  
  struct leaf
  {
    std::array<T, dim> pt;
    uint64_t index;
  };
  
  uint64_t _optimise(typename std::vector<leaf>::iterator first, typename std::vector<leaf>::iterator last, uint32_t level);
  
  std::vector<array_tree_node> _nodes;
};

// Web-Scale K-Means Clustering. D. Sculley
// Returns a cluster of size k
template <class T, std::size_t dim>
std::vector<std::array<T, dim>> k_means(const std::array<T, dim>* X, std::size_t Xsize, std::size_t k, std::size_t batch_size, uint32_t iterations, uint64_t seed = 7967805708226634297);

} // namespace ma

////////////////////////////////
// IMPLEMENTATION
////////////////////////////////


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
// operator &
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator & (const std::array<T, dim>& a, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] & b[i];
  return res;
}

template <class T>
std::array<T, 2> operator & (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return { a[0] & b[0], a[1] & b[1] };
}

template <class T>
std::array<T, 3> operator & (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return { a[0] & b[0], a[1] & b[1], a[2] & b[2] };
}

template <class T>
std::array<T, 4> operator & (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return { a[0] & b[0], a[1] & b[1], a[2] & b[2], a[3] & b[3] };
}

template <class T, std::size_t dim>
std::array<T, dim> operator & (const std::array<T, dim>& a, const T s) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] & s;
  return res;
}

template <class T>
std::array<T, 2> operator & (const std::array<T, 2>& a, const T s) {
  return { a[0] & s, a[1] & s };
}

template <class T>
std::array<T, 3> operator & (const std::array<T, 3>& a, const T s) {
  return { a[0] & s, a[1] & s, a[2] & s };
}

template <class T>
std::array<T, 4> operator & (const std::array<T, 4>& a, const T s) {
  return { a[0] & s, a[1] & s, a[2] & s, a[3] & s };
}


template <class T, std::size_t dim>
std::array<T, dim> operator & (const T s, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = s & b[i];
  return res;
}

template <class T>
std::array<T, 2> operator & (const T s, const std::array<T, 2>& b) {
  return { s & b[0], s & b[1] };
}

template <class T>
std::array<T, 3> operator & (const T s, const std::array<T, 3>& b) {
  return { s & b[0], s & b[1], s & b[2] };
}

template <class T>
std::array<T, 4> operator & (const T s, const std::array<T, 4>& b) {
  return { s & b[0], s & b[1], s & b[2], s & b[3] };
}

////////////////////////////////
// operator |
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> operator | (const std::array<T, dim>& a, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] | b[i];
  return res;
}

template <class T>
std::array<T, 2> operator | (const std::array<T, 2>& a, const std::array<T, 2>& b) {
  return { a[0] | b[0], a[1] | b[1] };
}

template <class T>
std::array<T, 3> operator | (const std::array<T, 3>& a, const std::array<T, 3>& b) {
  return { a[0] | b[0], a[1] | b[1], a[2] | b[2] };
}

template <class T>
std::array<T, 4> operator | (const std::array<T, 4>& a, const std::array<T, 4>& b) {
  return { a[0] | b[0], a[1] | b[1], a[2] | b[2], a[3] | b[3] };
}

template <class T, std::size_t dim>
std::array<T, dim> operator | (const std::array<T, dim>& a, const T s) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] | s;
  return res;
}

template <class T>
std::array<T, 2> operator | (const std::array<T, 2>& a, const T s) {
  return { a[0] | s, a[1] | s };
}

template <class T>
std::array<T, 3> operator | (const std::array<T, 3>& a, const T s) {
  return { a[0] | s, a[1] | s, a[2] | s };
}

template <class T>
std::array<T, 4> operator | (const std::array<T, 4>& a, const T s) {
  return { a[0] | s, a[1] | s, a[2] | s, a[3] | s };
}


template <class T, std::size_t dim>
std::array<T, dim> operator | (const T s, const std::array<T, dim>& b) {
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = s | b[i];
  return res;
}

template <class T>
std::array<T, 2> operator | (const T s, const std::array<T, 2>& b) {
  return { s | b[0], s | b[1] };
}

template <class T>
std::array<T, 3> operator | (const T s, const std::array<T, 3>& b) {
  return { s | b[0], s | b[1], s | b[2] };
}

template <class T>
std::array<T, 4> operator | (const T s, const std::array<T, 4>& b) {
  return { s | b[0], s | b[1], s | b[2], s | b[3] };
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

namespace ma
{
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
  using ::sqrt;
  std::array<T, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = static_cast<T>(sqrt(a[i]));
  return res;
}

template <class T>
std::array<T, 2> sqrt(const std::array<T, 2>& a) {
  using ::sqrt;
  return { static_cast<T>(sqrt(a[0])), static_cast<T>(sqrt(a[1])) };
}

template <class T>
std::array<T, 3> sqrt(const std::array<T, 3>& a) {
  using ::sqrt;
  return { static_cast<T>(sqrt(a[0])), static_cast<T>(sqrt(a[1])), static_cast<T>(sqrt(a[2])) };
}

template <class T>
std::array<T, 4> sqrt(const std::array<T, 4>& a) {
  using ::sqrt;
  return { static_cast<T>(sqrt(a[0])), static_cast<T>(sqrt(a[1])), static_cast<T>(sqrt(a[2])), static_cast<T>(sqrt(a[3])) };
}

////////////////////////////////
// operator less
////////////////////////////////

template <class T>
std::array<int, 2> less(const std::array<T, 2>& a, const std::array<T, 2>& b)
{
  return {{a[0] < b[0] ? -1 : 0, a[1] < b[1] ? -1 : 0}};
}

template <class T>
std::array<int, 3> less(const std::array<T, 3>& a, const std::array<T, 3>& b)
{
  return {{a[0] < b[0] ? -1 : 0, a[1] < b[1] ? -1 : 0, a[2] < b[2] ? -1 : 0}};
}

template <class T>
std::array<int, 4> less(const std::array<T, 4>& a, const std::array<T, 4>& b)
{
  return {{a[0] < b[0] ? -1 : 0, a[1] < b[1] ? -1 : 0, a[2] < b[2] ? -1 : 0, a[3] < b[3] ? -1 : 0}};
}

template <class T, std::size_t dim>
std::array<int, dim> less(const std::array<T, dim>& a, const std::array<T, dim>& b)
{
  std::array<int, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] < b[i] ? -1 : 0;
  return res;
}

////////////////////////////////
// operator leq
////////////////////////////////

template <class T>
std::array<int, 2> leq(const std::array<T, 2>& a, const std::array<T, 2>& b)
{
  return {{!(b[0] < a[0]) ? -1 : 0, !(b[1] < a[1]) ? -1 : 0}};
}

template <class T>
std::array<int, 3> leq(const std::array<T, 3>& a, const std::array<T, 3>& b)
{
  return {{!(b[0] < a[0]) ? -1 : 0, !(b[1] < a[1]) ? -1 : 0, !(b[2] < a[2]) ? -1 : 0}};
}

template <class T>
std::array<int, 4> leq(const std::array<T, 4>& a, const std::array<T, 4>& b)
{
  return {{!(b[0] < a[0]) ? -1 : 0, !(b[1] < a[1]) ? -1 : 0, !(b[2] < a[2]) ? -1 : 0, !(b[3] < a[3]) ? -1 : 0}};
}

template <class T, std::size_t dim>
std::array<int, dim> leq(const std::array<T, dim>& a, const std::array<T, dim>& b)
{
  std::array<int, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = !(b[i] < a[i]) ? -1 : 0;
  return res;
}

////////////////////////////////
// operator greater
////////////////////////////////


template <class T>
std::array<int, 2> greater(const std::array<T, 2>& a, const std::array<T, 2>& b)
{
  return {{b[0] < a[0] ? -1 : 0, b[1] < a[1] ? -1 : 0}};
}

template <class T>
std::array<int, 3> greater(const std::array<T, 3>& a, const std::array<T, 3>& b)
{
  return {{b[0] < a[0] ? -1 : 0, b[1] < a[1] ? -1 : 0, b[2] < a[2] ? -1 : 0}};
}

template <class T>
std::array<int, 4> greater(const std::array<T, 4>& a, const std::array<T, 4>& b)
{
  return {{b[0] < a[0] ? -1 : 0, b[1] < a[1] ? -1 : 0, b[2] < a[2] ? -1 : 0, b[3] < a[3] ? -1 : 0}};
}

template <class T, std::size_t dim>
std::array<int, dim> greater(const std::array<T, dim>& a, const std::array<T, dim>& b)
{
  std::array<int, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = b[i] < a[i] ? -1 : 0;
  return res;
}

////////////////////////////////
// operator geq
////////////////////////////////

template <class T>
std::array<int, 2> geq(const std::array<T, 2>& a, const std::array<T, 2>& b)
{
  return {{!(a[0] < b[0]) ? -1 : 0, !(a[1] < b[1]) ? -1 : 0}};
}

template <class T>
std::array<int, 3> geq(const std::array<T, 3>& a, const std::array<T, 3>& b)
{
  return {{!(a[0] < b[0]) ? -1 : 0, !(a[1] < b[1]) ? -1 : 0, !(a[2] < b[2]) ? -1 : 0}};
}

template <class T>
std::array<int, 4> geq(const std::array<T, 4>& a, const std::array<T, 4>& b)
{
  return {{!(a[0] < b[0]) ? -1 : 0, !(a[1] < b[1]) ? -1 : 0, !(a[2] < b[2]) ? -1 : 0, !(a[3] < b[3]) ? -1 : 0}};
}

template <class T, std::size_t dim>
std::array<int, dim> geq(const std::array<T, dim>& a, const std::array<T, dim>& b)
{
  std::array<int, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = !(a[i] < b[i]) ? -1 : 0;
  return res;
}

////////////////////////////////
// operator eq
////////////////////////////////

template <class T>
std::array<int, 2> eq(const std::array<T, 2>& a, const std::array<T, 2>& b)
{
  return {{a[0] == b[0] ? -1 : 0, a[1] == b[1] ? -1 : 0}};
}

template <class T>
std::array<int, 3> eq(const std::array<T, 3>& a, const std::array<T, 3>& b)
{
  return {{a[0] == b[0] ? -1 : 0, a[1] == b[1] ? -1 : 0, a[2] == b[2] ? -1 : 0}};
}

template <class T>
std::array<int, 4> eq(const std::array<T, 4>& a, const std::array<T, 4>& b)
{
  return {{a[0] == b[0] ? -1 : 0, a[1] == b[1] ? -1 : 0, a[2] == b[2] ? -1 : 0, a[3] == b[3] ? -1 : 0}};
}

template <class T, std::size_t dim>
std::array<int, dim> eq(const std::array<T, dim>& a, const std::array<T, dim>& b)
{
  std::array<int, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = a[i] == b[i] ? -1 : 0;
  return res;
}

////////////////////////////////
// operator neq
////////////////////////////////

template <class T>
std::array<int, 2> neq(const std::array<T, 2>& a, const std::array<T, 2>& b)
{
  return {{!(a[0] == b[0]) ? -1 : 0, !(a[1] == b[1]) ? -1 : 0}};
}

template <class T>
std::array<int, 3> neq(const std::array<T, 3>& a, const std::array<T, 3>& b)
{
  return {{!(a[0] == b[0]) ? -1 : 0, !(a[1] == b[1]) ? -1 : 0, !(a[2] == b[2]) ? -1 : 0}};
}

template <class T>
std::array<int, 4> neq(const std::array<T, 4>& a, const std::array<T, 4>& b)
{
  return {{!(a[0] == b[0]) ? -1 : 0, !(a[1] == b[1]) ? -1 : 0, !(a[2] == b[2]) ? -1 : 0, !(a[3] == b[3]) ? -1 : 0}};
}

template <class T, std::size_t dim>
std::array<int, dim> neq(const std::array<T, dim>& a, const std::array<T, dim>& b)
{
  std::array<int, dim> res;
  for (std::size_t i = 0; i < dim; ++i)
    res[i] = !(a[i] == b[i]) ? -1 : 0;
  return res;
}

////////////////////////////////
// operator any
////////////////////////////////

template <>
inline int any(const std::array<int, 2>& b)
  {
  return b[0] | b[1];
  }
  
template <>
inline  int any(const std::array<int, 3>& b)
  {
  return b[0] | b[1] | b[2];
  }
  
template <>
inline int any(const std::array<int, 4>& b)
  {
  return b[0] | b[1] | b[2] | b[3];
  }

template <std::size_t dim>
int any(const std::array<int, dim>& b)
  {
  int res = 0;
  for (std::size_t i = 0; i < dim; ++i)
    res |= b[i];
  return res;
  }

////////////////////////////////
// operator none
////////////////////////////////

template <std::size_t dim>
int none(const std::array<int, dim>& b)
  {
  return !(any(b));
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
  using ::sqrt;
  return sqrt(dot(a,a));
}

template <std::size_t dim>
float length(const std::array<float, dim> a) {
  using ::sqrt;
  return sqrt(dot(a,a));
}

////////////////////////////////
// operator distance
////////////////////////////////

template <class T, std::size_t dim>
double distance(const std::array<T, dim>& a, const std::array<T, dim>& b) {
  using ::operator-;
  using ::sqrt;
  auto c = a-b;
  return sqrt(dot(c,c));
}

template <std::size_t dim>
float distance(const std::array<float, dim>& a, const std::array<float, dim>& b) {
  using ::operator-;
  using ::sqrt;
  auto c = a-b;
  return sqrt(dot(c,c));
}

////////////////////////////////
// operator distance_sqr
////////////////////////////////

template <class T, std::size_t dim>
T distance_sqr(const std::array<T, dim>& a, const std::array<T, dim>& b) {
  using ::operator-;
  auto c = a-b;
  return dot(c,c);
}

////////////////////////////////
// operator normalize
////////////////////////////////

template <class T, std::size_t dim>
std::array<T, dim> normalize(const std::array<T, dim>& a) {
  using ::sqrt;
  using ::operator/;
  T denom = static_cast<T>(sqrt(dot(a, a)));
  return !(denom == static_cast<T>(0)) ? a / denom : a;
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

template <class T>
void solve_roll_pitch_yaw_transformation(T& rx, T& ry, T& rz, T& tx, T& ty, T& tz, const array4x4<T>& m)
{
  rz = atan2(m.col[0][1], m.col[0][0]);
  const auto sg = sin(rz);
  const auto cg = cos(rz);
  ry = atan2(-m.col[0][2], m.col[0][0] * cg + m.col[0][1] * sg);
  rx = atan2(m.col[2][0] * sg - m.col[2][1] * cg, m.col[1][1] * cg - m.col[1][0] * sg);
  tx = m.col[3][0];
  ty = m.col[3][1];
  tz = m.col[3][2];
}

template <class T>
array4x4<T> compute_from_roll_pitch_yaw_transformation(T rx, T ry, T rz, T tx, T ty, T tz)
{
  array4x4<T> m = get_identity<T>();
  T ca = cos(rx);
  T sa = sin(rx);
  T cb = cos(ry);
  T sb = sin(ry);
  T cg = cos(rz);
  T sg = sin(rz);
  m.col[0][0] = cb * cg;
  m.col[1][0] = cg * sa * sb - ca * sg;
  m.col[2][0] = sa * sg + ca * cg * sb;
  m.col[0][1] = cb * sg;
  m.col[1][1] = sa * sb * sg + ca * cg;
  m.col[2][1] = ca * sb * sg - cg * sa;
  m.col[0][2] = -sb;
  m.col[1][2] = cb * sa;
  m.col[2][2] = ca * cb;
  m.col[3][0] = tx;
  m.col[3][1] = ty;
  m.col[3][2] = tz;
  return m;
}

template <class T>
array4x4<T> quaternion_to_rotation(const std::array<T, 4>& quaternion)
{
  array4x4<T> rot;
  rot[0] = static_cast<T>(1) - static_cast<T>(2) * (quaternion[1] * quaternion[1] + quaternion[2] * quaternion[2]);
  rot[4] = static_cast<T>(2) * (quaternion[0] * quaternion[1] - quaternion[2] * quaternion[3]);
  rot[8] = static_cast<T>(2) * (quaternion[2] * quaternion[0] + quaternion[1] * quaternion[3]);
  rot[12] = static_cast<T>(0);
  
  rot[1] = static_cast<T>(2) * (quaternion[0] * quaternion[1] + quaternion[2] * quaternion[3]);
  rot[5] = static_cast<T>(1) - 2.f * (quaternion[2] * quaternion[2] + quaternion[0] * quaternion[0]);
  rot[9] = static_cast<T>(2) * (quaternion[1] * quaternion[2] - quaternion[0] * quaternion[3]);
  rot[13] = static_cast<T>(0);
  
  rot[2] = static_cast<T>(2) * (quaternion[2] * quaternion[0] - quaternion[1] * quaternion[3]);
  rot[6] = static_cast<T>(2) * (quaternion[1] * quaternion[2] + quaternion[0] * quaternion[3]);
  rot[10] = static_cast<T>(1) - static_cast<T>(2) * (quaternion[1] * quaternion[1] + quaternion[0] * quaternion[0]);
  rot[14] = static_cast<T>(0);
  
  rot[3] = static_cast<T>(0);
  rot[7] = static_cast<T>(0);
  rot[11] = static_cast<T>(0);
  rot[15] = static_cast<T>(1);
  return rot;
}

template <class T>
std::array<T, 4> quaternion_multiply(const std::array<T, 4>& q1, const std::array<T, 4>& q2)
{
  return std::array<T, 4>({{q1[3] * q2[0] + q1[0] * q2[3] + q1[1] * q2[2] - q1[2] * q2[1],
    q1[3] * q2[1] - q1[0] * q2[2] + q1[1] * q2[3] + q1[2] * q2[0],
    q1[3] * q2[2] + q1[0] * q2[1] - q1[1] * q2[0] + q1[2] * q2[3],
    q1[3] * q2[3] - q1[0] * q2[0] - q1[1] * q2[1] - q1[2] * q2[2]}});
}

template <class T>
std::array<T, 4> quaternion_axis(const std::array<T, 4>& q)
{
  return normalize(std::array<T, 4>{{q[0], q[1], q[2], 0}});
}

template <class T>
float quaternion_angle(const std::array<T, 4>& q)
{
  return static_cast<T>(2) * acos(q[3]);
}

template <class T>
std::array<T, 4> quaternion_conjugate(const std::array<T, 4>& quaternion)
{
  return std::array<T, 4>{{-quaternion[0], -quaternion[1], -quaternion[2], quaternion[3]}};
}

template <class T>
std::array<T, 4> quaternion_inverse(const std::array<T, 4>& quaternion)
{
  using ::operator/;
  T denom = dot(quaternion, quaternion);
  return quaternion_conjugate(quaternion) / denom;
}

template <class T>
std::array<T, 4> quaternion_normalize(const std::array<T, 4>& quaternion)
{
  using ::operator/;
  using ::sqrt;
  T denom = sqrt(dot(quaternion, quaternion));
  return quaternion / denom;
}

template <class T>
array4x4<T> look_at(const std::array<T, 3>& eye, const std::array<T, 3>& center, const std::array<T, 3>& up)
{
  array4x4<T> m;
  std::array<T, 3> z = normalize(::operator - (eye, center));
  std::array<T, 3> x = normalize(cross(up, z));
  std::array<T, 3> y = cross(z, x);
  std::array<T, 4> X{{x[0], y[0], z[0], static_cast<T>(0)}};
  std::array<T, 4> Y{{x[1], y[1], z[1], static_cast<T>(0)}};
  std::array<T, 4> Z{{x[2], y[2], z[2], static_cast<T>(0)}};
  std::array<T, 4> W{{-dot(x, eye), -dot(y, eye), -dot(z, eye), static_cast<T>(1)}};
  m.col[0] = X;
  m.col[1] = Y;
  m.col[2] = Z;
  m.col[3] = W;
  return m;
}

template <class T>
array4x4<T> look_at(const std::array<T, 4>& eye, const std::array<T, 4>& center, const std::array<T, 4>& up)
{
  array4x4<T> m;
  std::array<T, 4> z = normalize(eye - center);
  std::array<T, 4> x = normalize(cross(up, z));
  std::array<T, 4> y = cross(z, x);
  std::array<T, 4> X{{x[0], y[0], z[0], static_cast<T>(0)}};
  std::array<T, 4> Y{{x[1], y[1], z[1], static_cast<T>(0)}};
  std::array<T, 4> Z{{x[2], y[2], z[2], static_cast<T>(0)}};
  std::array<T, 4> W{{-dot(x, eye), -dot(y, eye), -dot(z, eye), static_cast<T>(1)}};
  m.col[0] = X;
  m.col[1] = Y;
  m.col[2] = Z;
  m.col[3] = W;
  return m;
}

template <class T>
void get_eye_center_up(std::array<T, 3>& eye, std::array<T, 3>& center, std::array<T, 3>& up, const array4x4<T>& transform)
{
  using ::operator-;
  array4x4<T> tr_inv = invert_orthonormal(transform);
  eye[0] = tr_inv[12];
  eye[1] = tr_inv[13];
  eye[2] = tr_inv[14];
  
  up = {{tr_inv[4], tr_inv[5], tr_inv[6]}};
  center = eye - std::array<T, 3>({{tr_inv[8], tr_inv[9], tr_inv[10]}});
}

template <class T>
void get_eye_center_up(std::array<T, 4>& eye, std::array<T, 4>& center, std::array<T, 4>& up, const array4x4<T>& transform)
{
  using ::operator-;
  array4x4<T> tr_inv = invert_orthonormal(transform);
  eye[0] = tr_inv[12];
  eye[1] = tr_inv[13];
  eye[2] = tr_inv[14];
  eye[3] = 1;
  
  up = {{tr_inv[4], tr_inv[5], tr_inv[6], static_cast<T>(0)}};
  center = eye - std::array<T, 4>({{tr_inv[8], tr_inv[9], tr_inv[10], 0}});
}

template <class T>
std::array<T, 4> roll_pitch_yaw_to_quaternion(T rx, T ry, T rz)
{
  T cy = cos(rz / static_cast<T>(2));
  T sy = sin(rz / static_cast<T>(2));
  T cp = cos(ry / static_cast<T>(2));
  T sp = sin(ry / static_cast<T>(2));
  T cr = cos(rx / static_cast<T>(2));
  T sr = sin(rx / static_cast<T>(2));
  
  std::array<T, 4> q;
  q[0] = sr * cp * cy - cr * sp * sy;
  q[1] = cr * sp * cy + sr * cp * sy;
  q[2] = cr * cp * sy - sr * sp * cy;
  q[3] = cr * cp * cy + sr * sp * sy;
  return q;
}

template <class T>
std::array<T, 4> rotation_to_quaternion(const array4x4<T>& m)
{
  T rz = atan2(m.col[0][1], m.col[0][0]);
  const auto sg = sin(rz);
  const auto cg = cos(rz);
  T ry = atan2(-m.col[0][2], m.col[0][0] * cg + m.col[0][1] * sg);
  T rx = atan2(m.col[2][0] * sg - m.col[2][1] * cg, m.col[1][1] * cg - m.col[1][0] * sg);
  return roll_pitch_yaw_to_quaternion(rx, ry, rz);
}

template <class T>
array4x4<T> transpose(const array4x4<T>& m)
{
  array4x4<T> out;
  transpose(out.col[0], out.col[1], out.col[2], out.col[3], m.col[0], m.col[1], m.col[2], m.col[3]);
  return out;
}

template <class T>
array4x4<T> invert_orthonormal(const array4x4<T>& m)
{
  using ::operator-;
  using ::operator*;
  using ::operator+;
  array4x4<T> out;
  transpose(out.col[0], out.col[1], out.col[2], out.col[3], m.col[0], m.col[1], m.col[2], std::array<T, 4>{{static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)}});
  out.col[3] = -(out.col[0] * m[12] + out.col[1] * m[13] + out.col[2] * m[14]);
  out.f[15] = static_cast<T>(1);
  return out;
}

template <class T>
std::array<T, 4> matrix_vector_multiply(const array4x4<T>& m, const std::array<T, 4>& v)
{
  using ::operator*;
  using ::operator+;
  std::array<T, 4> out = m.col[0] * v[0] + m.col[1] * v[1] + m.col[2] * v[2] + m.col[3] * v[3];
  return out;
}

template <class T>
std::array<T, 3> transform_point(const array4x4<T>& m, const std::array<T, 3>& v)
{
  return {{ m.f[0]*v[0] + m.f[4]*v[1] + m.f[8]*v[2] + m.f[12], m.f[1]*v[0] + m.f[5]*v[1] + m.f[9]*v[2] + m.f[13], m.f[2]*v[0] + m.f[6]*v[1] + m.f[10]*v[2] + m.f[14]}};
}

template <class T>
std::array<T, 3> transform_direction(const array4x4<T>& m, const std::array<T, 3>& v)
{
  return {{ m.f[0]*v[0] + m.f[4]*v[1] + m.f[8]*v[2], m.f[1]*v[0] + m.f[5]*v[1] + m.f[9]*v[2], m.f[2]*v[0] + m.f[6]*v[1] + m.f[10]*v[2]}};
}

template <class T>
array4x4<T> operator + (const array4x4<T>& left, const array4x4<T>& right)
{
  using ::operator+;
  return array4x4<T>(left.col[0] + right.col[0], left.col[1] + right.col[1], left.col[2] + right.col[2], left.col[3] + right.col[3]);
}

template <class T>
array4x4<T> operator - (const array4x4<T>& left, const array4x4<T>& right)
{
  using ::operator-;
  return array4x4<T>(left.col[0] - right.col[0], left.col[1] - right.col[1], left.col[2] - right.col[2], left.col[3] - right.col[3]);
}

template <class T>
array4x4<T> operator + (const array4x4<T>& a)
{
  return a;
}

template <class T>
array4x4<T> operator - (const array4x4<T>& a)
{
  using ::operator-;
  return array4x4<T>(-a.col[0], -a.col[1], -a.col[2], -a.col[3]);
}

template <class T>
array4x4<T> operator / (const array4x4<T>& left, const T value)
{
  using ::operator/;
  return array4x4<T>(left.col[0] / value, left.col[1] / value, left.col[2] / value, left.col[3] / value);
}

template <class T>
array4x4<T> operator / (const T value, const array4x4<T>& right)
{
  using ::operator/;
  return array4x4<T>(value / right.col[0], value / right.col[1], value / right.col[2], value / right.col[3]);
}

template <class T>
array4x4<T> operator * (const array4x4<T>& left, const T value)
{
  using ::operator*;
  return array4x4<T>(left.col[0] * value, left.col[1] * value, left.col[2] * value, left.col[3] * value);
}

template <class T>
array4x4<T> operator * (const T value, const array4x4<T>& right)
{
  using ::operator*;
  return array4x4<T>(value * right.col[0], value * right.col[1], value * right.col[2], value * right.col[3]);
}

template <class T>
array4x4<T> make_identity()
{
  return get_identity<T>();
}

template <class T>
array4x4<T> make_transformation(const std::array<T, 4>& origin, const std::array<T, 4>& x_axis, const std::array<T, 4>& y_axis, const std::array<T, 4>& z_axis)
{
  array4x4<T> matrix(x_axis, y_axis, z_axis, origin);
  matrix.col[0][3] = static_cast<T>(0);
  matrix.col[1][3] = static_cast<T>(0);
  matrix.col[2][3] = static_cast<T>(0);
  matrix.col[3][3] = static_cast<T>(1);
  
  return matrix;
}

template <class T>
array4x4<T> make_rotation(const std::array<T, 4>& position, const std::array<T, 4>& dir, T angle_radians)
{
  auto matrix = make_identity<T>();
  auto direction = normalize(dir);
  
  auto cos_alpha = cos(angle_radians);
  auto sin_alpha = sin(angle_radians);
  
  matrix[0] = (direction[0] * direction[0]) * (1 - cos_alpha) + cos_alpha;
  matrix[4] = (direction[0] * direction[1]) * (1 - cos_alpha) - direction[2] * sin_alpha;
  matrix[8] = (direction[0] * direction[2]) * (1 - cos_alpha) + direction[1] * sin_alpha;
  
  matrix[1] = (direction[0] * direction[1]) * (1 - cos_alpha) + direction[2] * sin_alpha;
  matrix[5] = (direction[1] * direction[1]) * (1 - cos_alpha) + cos_alpha;
  matrix[9] = (direction[1] * direction[2]) * (1 - cos_alpha) - direction[0] * sin_alpha;
  
  matrix[2] = (direction[0] * direction[2]) * (1 - cos_alpha) - direction[1] * sin_alpha;
  matrix[6] = (direction[1] * direction[2]) * (1 - cos_alpha) + direction[0] * sin_alpha;
  matrix[10] = (direction[2] * direction[2]) * (1 - cos_alpha) + cos_alpha;
  
  auto rotated_position = matrix_vector_multiply(matrix, position);
  
  matrix[12] = position[0] - rotated_position[0];
  matrix[13] = position[1] - rotated_position[1];
  matrix[14] = position[2] - rotated_position[2];
  
  return matrix;
}

template <class T>
array4x4<T> make_scale3d(T scale_x, T scale_y, T scale_z)
{
  array4x4<T> m({{static_cast<T>(scale_x), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)}}, {{static_cast<T>(0), static_cast<T>(scale_y), static_cast<T>(0), static_cast<T>(0)}}, {{static_cast<T>(0), static_cast<T>(0), static_cast<T>(scale_z), static_cast<T>(0)}}, {{static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)}});
}

template <class T>
array4x4<T> make_translation(const std::array<T, 3>& translation)
{
  return make_translation(translation[0], translation[1], translation[2]);
}

template <class T>
array4x4<T> make_translation(const std::array<T, 4>& translation)
{
  return make_translation(translation[0], translation[1], translation[2]);
}

template <class T>
std::array<T, 4> get_translation(const array4x4<T>& matrix)
{
  return matrix.col[3];
}

template <class T>
void set_x_axis(array4x4<T>& matrix, const std::array<T, 4>& x)
{
  matrix.col[0] = x;
  matrix.col[0][3] = static_cast<T>(0);
}

template <class T>
void set_y_axis(array4x4<T>& matrix, const std::array<T, 4>& y)
{
  matrix.col[1] = y;
  matrix.col[1][3] = static_cast<T>(0);
}

template <class T>
void set_z_axis(array4x4<T>& matrix, const std::array<T, 4>& z)
{
  matrix.col[2] = z;
  matrix.col[2][3] = static_cast<T>(0);
}

template <class T>
void set_translation(array4x4<T>& matrix, const std::array<T, 4>& t)
{
  matrix.col[3] = t;
  matrix.col[3][3] = static_cast<T>(1);
}

template <class T>
std::array<T, 4> get_x_axis(const array4x4<T>& matrix)
{
  return matrix.col[0];
}

template <class T>
std::array<T, 4> get_y_axis(const array4x4<T>& matrix)
{
  return matrix.col[1];
}

template <class T>
std::array<T, 4> get_z_axis(const array4x4<T>& matrix)
{
  return matrix.col[2];
}

template <class T, std::size_t dim>
array_tree<T, dim>::array_tree()
{
}

template <class T, std::size_t dim>
array_tree<T, dim>::aabb_node::aabb_node() : _tag(0xffffffff) {}

template <class T, std::size_t dim>
array_tree<T, dim>::aabb_node::aabb_node(const aabb_node& left, const aabb_node& right) : _min(left._min), _max(left._max), _tag(0xffffffff)
{
  for (std::size_t i = 0; i < dim; ++i)
  {
    _min[i] = _min[i] < right._min[i] ? _min[i] : right._min[i];
    _max[i] = _max[i] < right._max[i] ? right._max[i] : _max[i];
  }
}

template <class T, std::size_t dim>
T array_tree<T, dim>::aabb_node::distance_sqr(const std::array<T, dim>& pt) const
{
  T tmp = (_min[0] < pt[0] ? pt[0] : _min[0]);
  tmp = pt[0] - (_max[0] < tmp ? _max[0] : tmp);
  T dist = tmp*tmp;
  for (std::size_t i = 1; i < dim; ++i)
  {
    tmp = (_min[i] < pt[i] ? pt[i] : _min[i]);
    tmp = pt[i] - (_max[i] < tmp ? _max[i] : tmp);
    dist += tmp*tmp;
  }
  return dist;
}


template <class T, std::size_t dim>
uint64_t array_tree<T, dim>::find_nearest(T& dist_sqr, const std::array<T, dim>& pt) const
{
  std::vector<uint64_t> stack;
  uint64_t best_node = 0;
  T best_distance_sqr = distance_sqr(_nodes[best_node]._node._min, pt);
  stack.push_back(_nodes.size()-1); // put root on the stack
  while (!stack.empty())
  {
    const uint64_t node_id = stack.back();
    stack.pop_back();
    const auto& n = _nodes[node_id];
    if (n._child_1 == 0xffffffffffffffff) // a leaf
    {
      T distsqr = distance_sqr(_nodes[node_id]._node._min, pt);
      if (distsqr < best_distance_sqr)
      {
        best_distance_sqr = distsqr;
        best_node = node_id;
      }
    }
    else
    {
      T distsqr1 = _nodes[n._child_1]._node.distance_sqr(pt);
      T distsqr2 = _nodes[n._child_2]._node.distance_sqr(pt);
      
      if (distsqr1 < distsqr2)
      {
        if (best_distance_sqr > distsqr2)
        {
          stack.push_back(n._child_2);
          stack.push_back(n._child_1);
        }
        else if (best_distance_sqr > distsqr1)
        {
          stack.push_back(n._child_1);
        }
      }
      else
      {
        if (best_distance_sqr > distsqr1)
        {
          stack.push_back(n._child_1);
          stack.push_back(n._child_2);
        }
        else if (best_distance_sqr > distsqr2)
        {
          stack.push_back(n._child_2);
        }
      }
    }
  }
  dist_sqr = best_distance_sqr;
  return _nodes[best_node]._node._tag;
}

template <class T, std::size_t dim>
template <class Iter>
void array_tree<T, dim>::build_tree(Iter first, Iter last)
{
  std::size_t size = std::distance(first, last);
  _nodes.clear();
  _nodes.reserve(size*2);
  std::vector<leaf> leafs;
  leafs.reserve(size);
  for (std::size_t i = 0; i < size; ++i)
  {
    leaf l;
    l.pt = *first++;
    l.index = i;
    leafs.push_back(l);
  }
  _optimise(leafs.begin(), leafs.end(), 0);
}

template <class T, std::size_t dim>
bool array_tree<T, dim>::empty() const
{
  return _nodes.empty();
}

template <class T, std::size_t dim>
uint64_t array_tree<T, dim>::_optimise(typename std::vector<leaf>::iterator first, typename std::vector<leaf>::iterator last, uint32_t level)
{
  array_tree_node n;
  typename std::vector<leaf>::iterator mid = first + (last - first) / 2;
  const int _dim = level % dim;
  std::nth_element(first, mid, last, [_dim](const leaf& left, const leaf& right)
                   {
    return left.pt[_dim] < right.pt[_dim];
  });
  if (mid != first)
  {
    n._child_1 = _optimise(first, mid, level+1);
    n._child_2 = _optimise(mid, last, level+1);
    n._node = aabb_node(_nodes[n._child_1]._node, _nodes[n._child_2]._node);
  }
  else
  {
    n._child_1 = 0xffffffffffffffff;
    n._child_2 = 0xffffffffffffffff;
    n._node._tag = first->index;
    n._node._min = first->pt;
    n._node._max = first->pt;
  }
  const uint64_t ret_val = (uint64_t)_nodes.size();
  _nodes.push_back(n);
  return ret_val;
}

template <class T, std::size_t dim>
std::vector<std::array<T, dim>> k_means(const std::array<T, dim>* X, std::size_t Xsize, std::size_t k, std::size_t batch_size, uint32_t iterations, uint64_t seed)
{
  using ::operator*;
  using ::operator+;
  //Given: cluster size "k", mini-batch size "batch_size", iterations "iterations", data set "X".
  if (k == 0)
    return std::vector<std::array<T, dim>>();
  if (k >= Xsize)
    {
    std::vector<std::array<T, dim>> C(X, X+Xsize);
    return C;
    }
  if (batch_size >= Xsize)
    batch_size = Xsize;
  //Initialize pseudo random number generator
  uint64_t rnd_state = seed;
  //Initialize each c in C with an x picked randomly from X
  std::vector<std::array<T, dim>> C;
  C.reserve(k);
  while (C.size() < k)
    {
    while (C.size() < k)
    {
      rnd_state ^= (rnd_state << 13);
      rnd_state ^= (rnd_state >> 7);
      rnd_state ^= (rnd_state << 17);
      std::size_t x = static_cast<std::size_t>(rnd_state % Xsize);
      C.push_back(X[x]);
    }
    std::sort(C.begin(), C.end());
    C.erase(std::unique(C.begin(), C.end()), C.end());
  }
  std::vector<uint32_t> v(C.size(), 0);
  for (uint32_t iter = 0; iter < iterations; ++iter)
  {
    ma::array_tree<T, dim> tree;
    tree.build_tree(C.begin(), C.end());
    std::vector<std::size_t> M;
    M.reserve(batch_size);
    std::vector<std::size_t> closest_cluster_indices(batch_size, 0);
    if (batch_size == Xsize)
      {
      for (std::size_t i = 0; i < batch_size; ++i)
        {
        M.push_back(i);
        T dist_sqr;
        closest_cluster_indices[i] = tree.find_nearest(dist_sqr, X[i]);
        }
      }
    else
      {
      for (std::size_t i = 0; i < batch_size; ++i)
      {
        rnd_state ^= (rnd_state << 13);
        rnd_state ^= (rnd_state >> 7);
        rnd_state ^= (rnd_state << 17);
        std::size_t x = static_cast<std::size_t>(rnd_state % Xsize);
        M.push_back(x);
        T dist_sqr;
        closest_cluster_indices[i] = tree.find_nearest(dist_sqr, X[x]);
      }
      }
    for (std::size_t i = 0; i < batch_size; ++i)
    {
      std::size_t c = closest_cluster_indices[i];
      v[c] = v[c] + 1;
      T eta = static_cast<T>(1) / static_cast<T>(v[c]);
      C[c] = (static_cast<T>(1) - eta)*C[c] + eta*X[M[i]];
    }
  }
  return C;
}

} // namespace ma
