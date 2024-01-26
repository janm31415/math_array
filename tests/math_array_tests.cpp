#include "math_array_tests.h"
#include "test_assert.h"

#include "../math_array.h"

#define NDIM 10

namespace custom_stuff
{

struct custom_object
{
  custom_object() : _value(0) {}
  
  custom_object(double value) : _value(value) {}
  
  bool operator == (const custom_object& other) const
  {
    return other._value == _value;
  }
  bool operator < (const custom_object& other) const
  {
    return _value < other._value;
  }
  custom_object operator - () const
  {
    return custom_object(-_value);
  }
  custom_object operator + (const custom_object& other) const
  {
    return custom_object(_value + other._value);
  }
  custom_object operator - (const custom_object& other) const
  {
    return custom_object(_value - other._value);
  }
  custom_object operator * (const custom_object& other) const
  {
    return custom_object(_value * other._value);
  }
  custom_object operator / (const custom_object& other) const
  {
    return custom_object(_value / other._value);
  }
  double _value;
};

double sqrt(const custom_object& o)
{
  return ::sqrt(o._value);
}

std::ostream& operator <<(std::ostream& stream, const custom_object& obj)
{
  stream << obj._value;
  return stream;
}

} // namespace custom_stuff

namespace {
template <class T>
struct math_array_fixture
{
  math_array_fixture()
  {
    a2 = { { -1,4} };
    b2 = { { 3,-2} };
    a3 = { { -1,2,6} };
    b3 = { { 4,-5,3} };
    a4 = { { -1,2,3,8 } };
    b4 = { { 5,-6,7,4} };
    for (int i = 0; i < NDIM; ++i)
    {
      an[i] = static_cast<T>(i + 1);
      bn[i] = static_cast<T>(NDIM + i + 1);
    }
    auto tmp = bn[NDIM - 1];
    an[0] = -an[0];
    bn[1] = -bn[1];
    bn[NDIM - 1] = an[NDIM - 1];
    an[NDIM - 1] = tmp;
  }
  
  std::array<T, 2> a2;
  std::array<T, 2> b2;
  std::array<T, 3> a3;
  std::array<T, 3> b3;
  std::array<T, 4> a4;
  std::array<T, 4> b4;
  std::array<T, NDIM> an;
  std::array<T, NDIM> bn;
};

template <class T>
struct math_array4x4_fixture
{
  math_array4x4_fixture()
  {
    for (int i = 0; i < 16; ++i)
      {
      a[i] = i+1;
      b[i] = a[i]*2;
      c[i] = i+1;
      }
    c[14] = -1;
    c[7] = -3;
    v = {{1,2,3,1}};
    w = {{4,5,6,0}};
  }
  
  array4x4<T> a, b, c;
  std::array<T, 4> v, w;
};


template <class T>
struct add_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = this->a2 + this->b2; // Usage of this-> to make it compile with XCode. Don't know why this is necessary. Maybe the compiler has issues with the template usage?
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i] + this->b2[i], res2[i]);
    auto res3 = this->a3 + this->b3;
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i] + this->b3[i], res3[i]);
    auto res4 = this->a4 + this->b4;
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i] + this->b4[i], res4[i]);
    auto resn = this->an + this->bn;
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i] + this->bn[i], resn[i]);
    
    res2 = this->a2 + static_cast<T>(2);
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i] + static_cast<T>(2), res2[i]);
    res3 = this->a3 + static_cast<T>(2);
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i] + static_cast<T>(2), res3[i]);
    res4 = this->a4 + static_cast<T>(2);
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i] + static_cast<T>(2), res4[i]);
    resn = this->an + static_cast<T>(2);
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i] + static_cast<T>(2), resn[i]);
    
    res2 = static_cast<T>(2) + this->b2;
    for (int i = 0; i < 2; ++i)
      TEST_EQ(static_cast<T>(2) + this->b2[i], res2[i]);
    res3 = static_cast<T>(2) + this->b3;
    for (int i = 0; i < 3; ++i)
      TEST_EQ(static_cast<T>(2) + this->b3[i], res3[i]);
    res4 = static_cast<T>(2) + this->b4;
    for (int i = 0; i < 4; ++i)
      TEST_EQ(static_cast<T>(2) + this->b4[i], res4[i]);
    resn = static_cast<T>(2) + this->bn;
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(static_cast<T>(2) + this->bn[i], resn[i]);
  }
};

template <class T>
struct subtract_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = this->a2 - this->b2;
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i] - this->b2[i], res2[i]);
    auto res3 = this->a3 - this->b3;
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i] - this->b3[i], res3[i]);
    auto res4 = this->a4 - this->b4;
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i] - this->b4[i], res4[i]);
    auto resn = this->an - this->bn;
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i] - this->bn[i], resn[i]);
    
    res2 = this->a2 - static_cast<T>(2);
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i] - static_cast<T>(2), res2[i]);
    res3 = this->a3 - static_cast<T>(2);
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i] - static_cast<T>(2), res3[i]);
    res4 = this->a4 - static_cast<T>(2);
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i] - static_cast<T>(2), res4[i]);
    resn = this->an - static_cast<T>(2);
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i] - static_cast<T>(2), resn[i]);
    
    res2 = static_cast<T>(2) - this->b2;
    for (int i = 0; i < 2; ++i)
      TEST_EQ(static_cast<T>(2) - this->b2[i], res2[i]);
    res3 = static_cast<T>(2) - this->b3;
    for (int i = 0; i < 3; ++i)
      TEST_EQ(static_cast<T>(2) - this->b3[i], res3[i]);
    res4 = static_cast<T>(2) - this->b4;
    for (int i = 0; i < 4; ++i)
      TEST_EQ(static_cast<T>(2) - this->b4[i], res4[i]);
    resn = static_cast<T>(2) - this->bn;
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(static_cast<T>(2) - this->bn[i], resn[i]);
  }
};

template <class T>
struct multiply_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = this->a2 * this->b2;
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i] * this->b2[i], res2[i]);
    auto res3 = this->a3 * this->b3;
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i] * this->b3[i], res3[i]);
    auto res4 = this->a4 * this->b4;
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i] * this->b4[i], res4[i]);
    auto resn = this->an * this->bn;
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i] * this->bn[i], resn[i]);
    
    res2 = this->a2 * static_cast<T>(2);
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i] * static_cast<T>(2), res2[i]);
    res3 = this->a3 * static_cast<T>(2);
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i] * static_cast<T>(2), res3[i]);
    res4 = this->a4 * static_cast<T>(2);
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i] * static_cast<T>(2), res4[i]);
    resn = this->an * static_cast<T>(2);
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i] * static_cast<T>(2), resn[i]);
    
    res2 = static_cast<T>(2) * this->b2;
    for (int i = 0; i < 2; ++i)
      TEST_EQ(static_cast<T>(2) * this->b2[i], res2[i]);
    res3 = static_cast<T>(2) * this->b3;
    for (int i = 0; i < 3; ++i)
      TEST_EQ(static_cast<T>(2) * this->b3[i], res3[i]);
    res4 = static_cast<T>(2) * this->b4;
    for (int i = 0; i < 4; ++i)
      TEST_EQ(static_cast<T>(2) * this->b4[i], res4[i]);
    resn = static_cast<T>(2) * this->bn;
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(static_cast<T>(2) * this->bn[i], resn[i]);
  }
};

template <class T>
struct divide_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = this->a2 / this->b2;
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i] / this->b2[i], res2[i]);
    auto res3 = this->a3 / this->b3;
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i] / this->b3[i], res3[i]);
    auto res4 = this->a4 / this->b4;
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i] / this->b4[i], res4[i]);
    auto resn = this->an / this->bn;
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i] / this->bn[i], resn[i]);
    
    res2 = this->a2 / static_cast<T>(2);
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i] / static_cast<T>(2), res2[i]);
    res3 = this->a3 / static_cast<T>(2);
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i] / static_cast<T>(2), res3[i]);
    res4 = this->a4 / static_cast<T>(2);
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i] / static_cast<T>(2), res4[i]);
    resn = this->an / static_cast<T>(2);
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i] / static_cast<T>(2), resn[i]);
    
    res2 = static_cast<T>(2) / this->b2;
    for (int i = 0; i < 2; ++i)
      TEST_EQ(static_cast<T>(2) / this->b2[i], res2[i]);
    res3 = static_cast<T>(2) / this->b3;
    for (int i = 0; i < 3; ++i)
      TEST_EQ(static_cast<T>(2) / this->b3[i], res3[i]);
    res4 = static_cast<T>(2) / this->b4;
    for (int i = 0; i < 4; ++i)
      TEST_EQ(static_cast<T>(2) / this->b4[i], res4[i]);
    resn = static_cast<T>(2) / this->bn;
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(static_cast<T>(2) / this->bn[i], resn[i]);
  }
};


template <class T>
struct min_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = min(this->a2,this->b2);
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i] < this->b2[i] ? this->a2[i] : this->b2[i], res2[i]);
    auto res3 = min(this->a3, this->b3);
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i] < this->b3[i] ? this->a3[i] : this->b3[i], res3[i]);
    auto res4 = min(this->a4, this->b4);
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i] < this->b4[i] ? this->a4[i] : this->b4[i], res4[i]);
    auto resn = min(this->an, this->bn);
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i] < this->bn[i] ? this->an[i] : this->bn[i], resn[i]);
  }
};

template <class T>
struct max_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = max(this->a2, this->b2);
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i] < this->b2[i] ? this->b2[i] : this->a2[i], res2[i]);
    auto res3 = max(this->a3, this->b3);
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i] < this->b3[i] ? this->b3[i] : this->a3[i], res3[i]);
    auto res4 = max(this->a4, this->b4);
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i] < this->b4[i] ? this->b4[i] : this->a4[i], res4[i]);
    auto resn = max(this->an, this->bn);
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i] < this->bn[i] ? this->bn[i] : this->an[i], resn[i]);
  }
};

template <class T>
struct abs_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = abs(this->a2);
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i] < 0 ? -this->a2[i] : this->a2[i], res2[i]);
    auto res3 = abs(this->a3);
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i] < 0 ? -this->a3[i] : this->a3[i], res3[i]);
    auto res4 = abs(this->a4);
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i] < 0 ? -this->a4[i] : this->a4[i], res4[i]);
    auto resn = abs(this->an);
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i] < 0 ? -this->an[i] : this->an[i], resn[i]);
  }
};

template <class T>
struct sqrt_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = sqrt(abs(this->a2));
    for (int i = 0; i < 2; ++i)
      TEST_EQ(static_cast<T>(sqrt(this->a2[i] < 0 ? -this->a2[i] : this->a2[i])), res2[i]);
    auto res3 = sqrt(abs(this->a3));
    for (int i = 0; i < 3; ++i)
      TEST_EQ(static_cast<T>(sqrt(this->a3[i] < 0 ? -this->a3[i] : this->a3[i])), res3[i]);
    auto res4 = sqrt(abs(this->a4));
    for (int i = 0; i < 4; ++i)
      TEST_EQ(static_cast<T>(sqrt(this->a4[i] < 0 ? -this->a4[i] : this->a4[i])), res4[i]);
    auto resn = sqrt(abs(this->an));
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(static_cast<T>(sqrt(this->an[i] < 0 ? -this->an[i] : this->an[i])), resn[i]);
  }
};

template <class T>
struct dot_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = dot(this->a2, this->b2);
    TEST_EQ(this->a2[0]*this->b2[0] + this->a2[1]*this->b2[1], res2);
    auto res3 = dot(this->a3, this->b3);
    TEST_EQ(this->a3[0]*this->b3[0] + this->a3[1]*this->b3[1] + this->a3[2]*this->b3[2], res3);
    auto res4 = dot(this->a4, this->b4);
    TEST_EQ(this->a4[0]*this->b4[0] + this->a4[1]*this->b4[1] + this->a4[2]*this->b4[2] + this->a4[3]*this->b4[3], res4);
    auto resn = dot(this->an, this->bn);
    T expected = static_cast<T>(0);
    for (int i = 0; i < NDIM; ++i)
      expected = expected + this->an[i]*this->bn[i];
    TEST_EQ(expected, resn);
  }
};

template <class T>
struct length_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = length(this->a2);
    TEST_EQ(sqrt(dot(this->a2, this->a2)), res2);
    auto res3 = length(this->a3);
    TEST_EQ(sqrt(dot(this->a3, this->a3)), res3);
    auto res4 = length(this->a4);
    TEST_EQ(sqrt(dot(this->a4, this->a4)), res4);
    auto resn = length(this->an);
    TEST_EQ(sqrt(dot(this->an, this->an)), resn);
  }
};

template <class T>
struct distance_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = distance(this->a2, this->b2);
    TEST_EQ(sqrt(dot(this->a2-this->b2, this->a2-this->b2)), res2);
    auto res3 = distance(this->a3, this->b3);
    TEST_EQ(sqrt(dot(this->a3-this->b3, this->a3-this->b3)), res3);
    auto res4 = distance(this->a4, this->b4);
    TEST_EQ(sqrt(dot(this->a4-this->b4, this->a4-this->b4)), res4);
    auto resn = distance(this->an, this->bn);
    TEST_EQ(sqrt(dot(this->an-this->bn, this->an-this->bn)), resn);
  }
};

template <class T>
struct distance_sqr_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = distance_sqr(this->a2, this->b2);
    TEST_EQ(dot(this->a2-this->b2, this->a2-this->b2), res2);
    auto res3 = distance_sqr(this->a3, this->b3);
    TEST_EQ(dot(this->a3-this->b3, this->a3-this->b3), res3);
    auto res4 = distance_sqr(this->a4, this->b4);
    TEST_EQ(dot(this->a4-this->b4, this->a4-this->b4), res4);
    auto resn = distance_sqr(this->an, this->bn);
    TEST_EQ(dot(this->an-this->bn, this->an-this->bn), resn);
  }
};

template <class T>
struct normalize_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = normalize(this->a2);
    for (int i = 0; i < 2; ++i)
      TEST_EQ(static_cast<T>(this->a2[i])/static_cast<T>(sqrt(dot(this->a2, this->a2))), res2[i]);
    auto res3 = normalize(this->a3);
    for (int i = 0; i < 3; ++i)
      TEST_EQ(static_cast<T>(this->a3[i])/static_cast<T>(sqrt(dot(this->a3, this->a3))), res3[i]);
    auto res4 = normalize(this->a4);
    for (int i = 0; i < 4; ++i)
      TEST_EQ(static_cast<T>(this->a4[i])/static_cast<T>(sqrt(dot(this->a4, this->a4))), res4[i]);
    auto resn = normalize(this->an);
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(static_cast<T>(this->an[i])/static_cast<T>(sqrt(dot(this->an, this->an))), resn[i]);
  }
};

template <class T>
struct compare_vectors : public math_array_fixture<T>
{
  void test()
  {
    TEST_ASSERT(this->a2 == this->a2);
    TEST_ASSERT(this->a3 == this->a3);
    TEST_ASSERT(this->a4 == this->a4);
    TEST_ASSERT(this->an == this->an);
    TEST_ASSERT(!(this->a2 == this->b2));
    TEST_ASSERT(!(this->a3 == this->b3));
    TEST_ASSERT(!(this->a4 == this->b4));
    TEST_ASSERT(!(this->an == this->bn));
    TEST_ASSERT(!(this->a2 < this->a2));
    TEST_ASSERT(!(this->a3 < this->a3));
    TEST_ASSERT(!(this->a4 < this->a4));
    TEST_ASSERT(!(this->an < this->an));
    TEST_ASSERT(!(this->a2 > this->a2));
    TEST_ASSERT(!(this->a3 > this->a3));
    TEST_ASSERT(!(this->a4 > this->a4));
    TEST_ASSERT(!(this->an > this->an));
    TEST_ASSERT(this->a2 <= this->a2);
    TEST_ASSERT(this->a3 <= this->a3);
    TEST_ASSERT(this->a4 <= this->a4);
    TEST_ASSERT(this->an <= this->an);
    TEST_ASSERT(this->a2 >= this->a2);
    TEST_ASSERT(this->a3 >= this->a3);
    TEST_ASSERT(this->a4 >= this->a4);
    TEST_ASSERT(this->an >= this->an);
    TEST_ASSERT(!(this->a2 > this->b2));
    TEST_ASSERT(!(this->a3 > this->b3));
    TEST_ASSERT(!(this->a4 > this->b4));
    TEST_ASSERT(!(this->an > this->bn));
    TEST_ASSERT((this->a2 < this->b2));
    TEST_ASSERT((this->a3 < this->b3));
    TEST_ASSERT((this->a4 < this->b4));
    TEST_ASSERT((this->an < this->bn));
    TEST_ASSERT(!(this->a2 >= this->b2));
    TEST_ASSERT(!(this->a3 >= this->b3));
    TEST_ASSERT(!(this->a4 >= this->b4));
    TEST_ASSERT(!(this->an >= this->bn));
    TEST_ASSERT((this->a2 <= this->b2));
    TEST_ASSERT((this->a3 <= this->b3));
    TEST_ASSERT((this->a4 <= this->b4));
    TEST_ASSERT((this->an <= this->bn));
  }
};

template <class T>
struct cross_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res3 = cross(this->a3, this->b3);
    TEST_EQ(this->a3[1]*this->b3[2] - this->a3[2]*this->b3[1], res3[0]);
    TEST_EQ(this->a3[2]*this->b3[0] - this->a3[0]*this->b3[2], res3[1]);
    TEST_EQ(this->a3[0]*this->b3[1] - this->a3[1]*this->b3[0], res3[2]);
    auto res4 = cross(this->a4, this->b4);
    TEST_EQ(this->a4[1]*this->b4[2] - this->a4[2]*this->b4[1], res4[0]);
    TEST_EQ(this->a4[2]*this->b4[0] - this->a4[0]*this->b4[2], res4[1]);
    TEST_EQ(this->a4[0]*this->b4[1] - this->a4[1]*this->b4[0], res4[2]);
    TEST_EQ(static_cast<T>(0), res4[3]);
  }
};

template <class T>
struct unary_sign_vectors : public math_array_fixture<T>
{
  void test()
  {
    auto res2 = +this->a2;
    for (int i = 0; i < 2; ++i)
      TEST_EQ(this->a2[i], res2[i]);
    auto res3 = +this->a3;
    for (int i = 0; i < 3; ++i)
      TEST_EQ(this->a3[i], res3[i]);
    auto res4 = +this->a4;
    for (int i = 0; i < 4; ++i)
      TEST_EQ(this->a4[i], res4[i]);
    auto resn = +this->an;
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(this->an[i], resn[i]);
    
    res2 = -this->a2;
    for (int i = 0; i < 2; ++i)
      TEST_EQ(-this->a2[i], res2[i]);
    res3 = -this->a3;
    for (int i = 0; i < 3; ++i)
      TEST_EQ(-this->a3[i], res3[i]);
    res4 = -this->a4;
    for (int i = 0; i < 4; ++i)
      TEST_EQ(-this->a4[i], res4[i]);
    resn = -this->an;
    for (int i = 0; i < NDIM; ++i)
      TEST_EQ(-this->an[i], resn[i]);
  }
};

template <class T>
struct min_horizontal_vectors : public math_array_fixture<T>
{
  void test()
  {
  TEST_EQ(-1, min_horizontal(this->a2));
  TEST_EQ(-1, min_horizontal(this->a3));
  TEST_EQ(-1, min_horizontal(this->a4));
  TEST_EQ(-1, min_horizontal(this->an));
  }
};

template <class T>
struct max_horizontal_vectors : public math_array_fixture<T>
{
  void test()
  {
  TEST_EQ(4, max_horizontal(this->a2));
  TEST_EQ(6, max_horizontal(this->a3));
  TEST_EQ(8, max_horizontal(this->a4));
  TEST_EQ(2*NDIM, max_horizontal(this->an));
  }
};

template <class T>
void test_transpose()
  {
  std::array<T, 4> c0 = {1, 2, 3, 4};
  std::array<T, 4> c1 = {5, 6, 7, 8};
  std::array<T, 4> c2 = {9, 10, 11, 12};
  std::array<T, 4> c3 = {13, 14, 15, 16};
  std::array<T, 4> r0, r1, r2, r3;
  transpose(r0, r1, r2, r3, c0, c1, c2, c3);
  TEST_EQ(1, r0[0]);
  TEST_EQ(5, r0[1]);
  TEST_EQ(9, r0[2]);
  TEST_EQ(13, r0[3]);
  TEST_EQ(2, r1[0]);
  TEST_EQ(6, r1[1]);
  TEST_EQ(10, r1[2]);
  TEST_EQ(14, r1[3]);
  TEST_EQ(3, r2[0]);
  TEST_EQ(7, r2[1]);
  TEST_EQ(11, r2[2]);
  TEST_EQ(15, r2[3]);
  TEST_EQ(4, r3[0]);
  TEST_EQ(8, r3[1]);
  TEST_EQ(12, r3[2]);
  TEST_EQ(16, r3[3]);
  }

template <class T>
struct array4x4_tests : public math_array4x4_fixture<T>
{
  void test()
  {
  for (int i = 0; i < 16; ++i)
    TEST_EQ(static_cast<T>(i+1), this->a[i]);
  array4x4<T> id = get_identity<T>();
  array4x4<T> res = matrix_matrix_multiply(id, this->a);
  for (int i = 0; i < 16; ++i)
    TEST_EQ(static_cast<T>(i+1), res[i]);
  res = matrix_matrix_multiply(this->a, id);
  for (int i = 0; i < 16; ++i)
    TEST_EQ(static_cast<T>(i+1), res[i]);
  res = matrix_matrix_multiply(id, this->b);
  for (int i = 0; i < 16; ++i)
    TEST_EQ(this->b[i], res[i]);
  res = matrix_matrix_multiply(this->b, id);
  for (int i = 0; i < 16; ++i)
    TEST_EQ(this->b[i], res[i]);
  res = matrix_matrix_multiply(this->a, this->b);
  TEST_EQ(180, res[0]);
  TEST_EQ(200, res[1]);
  TEST_EQ(220, res[2]);
  TEST_EQ(240, res[3]);
  TEST_EQ(404, res[4]);
  TEST_EQ(456, res[5]);
  TEST_EQ(508, res[6]);
  TEST_EQ(560, res[7]);
  TEST_EQ(628, res[8]);
  TEST_EQ(712, res[9]);
  TEST_EQ(796, res[10]);
  TEST_EQ(880, res[11]);
  TEST_EQ(852, res[12]);
  TEST_EQ(968, res[13]);
  TEST_EQ(1084, res[14]);
  TEST_EQ(1200, res[15]);
  res = make_translation<T>(1, 2, 3);
  for (int i = 0; i < 12; ++i)
    TEST_EQ(id[i], res[i]);
  TEST_EQ(static_cast<T>(1), res[12]);
  TEST_EQ(static_cast<T>(2), res[13]);
  TEST_EQ(static_cast<T>(3), res[14]);
  TEST_EQ(static_cast<T>(1), res[15]);
  }
};

template <class T>
struct array4x4_invert_tests : public math_array4x4_fixture<T>
{
  void test()
  {
  }
};

template <>
struct array4x4_invert_tests<double> : public math_array4x4_fixture<double>
{
  void test()
  {
  auto id = get_identity<double>();
  auto res = invert(this->c);
  auto res2 = matrix_matrix_multiply(res, this->c);
  for (int i = 0; i < 16; ++i)
    TEST_EQ_CLOSE(id[i], res2[i], 1e-12);
  }
};

template <>
struct array4x4_invert_tests<float> : public math_array4x4_fixture<float>
{
  void test()
  {
  auto id = get_identity<float>();
  auto res = invert(this->c);
  auto res2 = matrix_matrix_multiply(res, this->c);
  for (int i = 0; i < 16; ++i)
    TEST_EQ_CLOSE(id[i], res2[i], 1e-6f);
  }
};

template <class T>
void run_typed_math_array_tests()
{
  add_vectors<T>().test();
  subtract_vectors<T>().test();
  multiply_vectors<T>().test();
  divide_vectors<T>().test();
  min_vectors<T>().test();
  max_vectors<T>().test();
  abs_vectors<T>().test();
  sqrt_vectors<T>().test();
  dot_vectors<T>().test();
  length_vectors<T>().test();
  distance_vectors<T>().test();
  distance_sqr_vectors<T>().test();
  normalize_vectors<T>().test();
  compare_vectors<T>().test();
  cross_vectors<T>().test();
  unary_sign_vectors<T>().test();
  min_horizontal_vectors<T>().test();
  max_horizontal_vectors<T>().test();
  test_transpose<T>();
  array4x4_tests<T>().test();
  array4x4_invert_tests<T>().test();
}
} // anonymous namespace

void run_math_array_tests()
{
  run_typed_math_array_tests<float>();
  run_typed_math_array_tests<double>();
  run_typed_math_array_tests<int>();
  run_typed_math_array_tests<custom_stuff::custom_object>();
}
