#include "math_array_tests.h"
#include "test_assert.h"

#include "../math_array.h"

#include <random>
#include <vector>

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
  
  ma::array4x4<T> a, b, c;
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
    using namespace ma;
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
    using namespace ma;
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
    using namespace ma;
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
    using namespace ma;
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
    using namespace ma;
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
    using namespace ma;
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
    using namespace ma;
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
    using namespace ma;
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
    using namespace ma;  
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
    using namespace ma;
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
    using namespace ma;
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
    using namespace ma;
    TEST_EQ(4, max_horizontal(this->a2));
    TEST_EQ(6, max_horizontal(this->a3));
    TEST_EQ(8, max_horizontal(this->a4));
    TEST_EQ(2*NDIM, max_horizontal(this->an));
  }
};

template <class T>
void test_transpose()
{
  using namespace ma;
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
    using namespace ma;
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
    res = invert(this->c);
    res = matrix_matrix_multiply(res, this->c);
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
    using namespace ma;
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
    using namespace ma;
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

void run_all_lookat_tests()
{
  using namespace ma;
  std::mt19937 gen(0);
  std::uniform_real_distribution<> dis(0.0, 1.0);
  for (int i = 0; i < 10; ++i)
  {
    std::array<float, 3> eye{{static_cast<float>(dis(gen)), static_cast<float>(dis(gen)), static_cast<float>(dis(gen))}};
    std::array<float, 3> center{{static_cast<float>(dis(gen)), static_cast<float>(dis(gen)), static_cast<float>(dis(gen))}};
    eye = eye * 50.f;
    center = center * 50.f;
    std::array<float, 3> x{{static_cast<float>(dis(gen)), static_cast<float>(dis(gen)), static_cast<float>(dis(gen))}};
    std::array<float, 3> up = normalize(cross(center-eye, x));
    auto tr = look_at(eye, center, up);
    std::array<float, 3> eye2, center2, up2;
    get_eye_center_up(eye2, center2, up2, tr);
    float tol = 1e-5f;
    TEST_EQ_CLOSE(eye[0], eye2[0], tol);
    TEST_EQ_CLOSE(eye[1], eye2[1], tol);
    TEST_EQ_CLOSE(eye[2], eye2[2], tol);
    TEST_EQ_CLOSE(up[0], up2[0], tol);
    TEST_EQ_CLOSE(up[1], up2[1], tol);
    TEST_EQ_CLOSE(up[2], up2[2], tol);
    auto center_dir = normalize(center - eye);
    auto expected_center = eye + center_dir;
    TEST_EQ_CLOSE(expected_center[0], center2[0], tol);
    TEST_EQ_CLOSE(expected_center[1], center2[1], tol);
    TEST_EQ_CLOSE(expected_center[2], center2[2], tol);
  }
}

void run_all_quaternion_tests()
{
  using namespace ma;
  std::vector<float> rx, ry, rz;
  rx = {{0.0, 0.1, 0.2, 0.3, 0.4, -0.1, -0.2, -0.3, -0.4, 0.5, 0.6, 0.7, 0.8, 0.9, -0.5, -0.6, -0.7, -0.8, -0.9, 1.0}};
  ry = { {0.0, 0.0, 0.1, 0.1, 0.2, 0.2, 0.3, 0.3, -0.1, -0.1, -0.2, -0.2, -0.3, -0.3, -0.4, -0.4, 0.7, 0.8, 0.9, 1.0} };
  rz = { {1.0, 0.9, 0.8, 0.7, -1.0, -0.9, -0.8, -0.7, 0.6, 0.5, 0.4, 0.3, -0.6, -0.5, -0.4, -0.3, 0.1, 0.0, -0.1, -0.9} };
  for (size_t i = 0; i < rx.size(); ++i)
  {
    float x = rx[i];
    float y = ry[i];
    float z = rz[i];
    array4x4<float> rot = compute_from_roll_pitch_yaw_transformation(x, y, z, 0.f, 0.f, 0.f);
    float tx,ty,tz;
    solve_roll_pitch_yaw_transformation(x, y, z, tx, ty, tz, rot);
    TEST_EQ_CLOSE(x, rx[i], 1e-5f);
    TEST_EQ_CLOSE(y, ry[i], 1e-5f);
    TEST_EQ_CLOSE(z, rz[i], 1e-5f);
    auto q = rotation_to_quaternion(rot);
    auto q2 = roll_pitch_yaw_to_quaternion(x, y, z);
    
    auto q_inv = quaternion_inverse(q);
    auto q_qinv = quaternion_multiply(q, q_inv);
    TEST_EQ_CLOSE(0, q_qinv[0], 1e-5f);
    TEST_EQ_CLOSE(0, q_qinv[1], 1e-5f);
    TEST_EQ_CLOSE(0, q_qinv[2], 1e-5f);
    TEST_EQ_CLOSE(1, q_qinv[3], 1e-5f);
    
    for (int j = 0; j < 4; ++j)
      TEST_EQ_CLOSE(q[j], q2[j], 1e-5f);
    auto rot2 = quaternion_to_rotation(q);
    for (int j = 0; j < 16; ++j)
      TEST_EQ_CLOSE(rot[j], rot2[j], 1e-5f);
    
    float angle = quaternion_angle(q);
    auto axis = quaternion_axis(q);
    auto rot3 = make_rotation({{0.f,0.f,0.f,1.f}}, axis, angle);
    auto q3 = rotation_to_quaternion(rot3);
    for (int j = 0; j < 4; ++j)
      TEST_EQ_CLOSE(q[j], q3[j], 1e-5f);
  }
}

namespace
{

inline void invert(float* out, const float* m)
{
  float inv[16], det;
  int i;
  
  inv[0] = m[5] * m[10] * m[15] -
  m[5] * m[11] * m[14] -
  m[9] * m[6] * m[15] +
  m[9] * m[7] * m[14] +
  m[13] * m[6] * m[11] -
  m[13] * m[7] * m[10];
  
  inv[4] = -m[4] * m[10] * m[15] +
  m[4] * m[11] * m[14] +
  m[8] * m[6] * m[15] -
  m[8] * m[7] * m[14] -
  m[12] * m[6] * m[11] +
  m[12] * m[7] * m[10];
  
  inv[8] = m[4] * m[9] * m[15] -
  m[4] * m[11] * m[13] -
  m[8] * m[5] * m[15] +
  m[8] * m[7] * m[13] +
  m[12] * m[5] * m[11] -
  m[12] * m[7] * m[9];
  
  inv[12] = -m[4] * m[9] * m[14] +
  m[4] * m[10] * m[13] +
  m[8] * m[5] * m[14] -
  m[8] * m[6] * m[13] -
  m[12] * m[5] * m[10] +
  m[12] * m[6] * m[9];
  
  inv[1] = -m[1] * m[10] * m[15] +
  m[1] * m[11] * m[14] +
  m[9] * m[2] * m[15] -
  m[9] * m[3] * m[14] -
  m[13] * m[2] * m[11] +
  m[13] * m[3] * m[10];
  
  inv[5] = m[0] * m[10] * m[15] -
  m[0] * m[11] * m[14] -
  m[8] * m[2] * m[15] +
  m[8] * m[3] * m[14] +
  m[12] * m[2] * m[11] -
  m[12] * m[3] * m[10];
  
  inv[9] = -m[0] * m[9] * m[15] +
  m[0] * m[11] * m[13] +
  m[8] * m[1] * m[15] -
  m[8] * m[3] * m[13] -
  m[12] * m[1] * m[11] +
  m[12] * m[3] * m[9];
  
  inv[13] = m[0] * m[9] * m[14] -
  m[0] * m[10] * m[13] -
  m[8] * m[1] * m[14] +
  m[8] * m[2] * m[13] +
  m[12] * m[1] * m[10] -
  m[12] * m[2] * m[9];
  
  inv[2] = m[1] * m[6] * m[15] -
  m[1] * m[7] * m[14] -
  m[5] * m[2] * m[15] +
  m[5] * m[3] * m[14] +
  m[13] * m[2] * m[7] -
  m[13] * m[3] * m[6];
  
  inv[6] = -m[0] * m[6] * m[15] +
  m[0] * m[7] * m[14] +
  m[4] * m[2] * m[15] -
  m[4] * m[3] * m[14] -
  m[12] * m[2] * m[7] +
  m[12] * m[3] * m[6];
  
  inv[10] = m[0] * m[5] * m[15] -
  m[0] * m[7] * m[13] -
  m[4] * m[1] * m[15] +
  m[4] * m[3] * m[13] +
  m[12] * m[1] * m[7] -
  m[12] * m[3] * m[5];
  
  inv[14] = -m[0] * m[5] * m[14] +
  m[0] * m[6] * m[13] +
  m[4] * m[1] * m[14] -
  m[4] * m[2] * m[13] -
  m[12] * m[1] * m[6] +
  m[12] * m[2] * m[5];
  
  inv[3] = -m[1] * m[6] * m[11] +
  m[1] * m[7] * m[10] +
  m[5] * m[2] * m[11] -
  m[5] * m[3] * m[10] -
  m[9] * m[2] * m[7] +
  m[9] * m[3] * m[6];
  
  inv[7] = m[0] * m[6] * m[11] -
  m[0] * m[7] * m[10] -
  m[4] * m[2] * m[11] +
  m[4] * m[3] * m[10] +
  m[8] * m[2] * m[7] -
  m[8] * m[3] * m[6];
  
  inv[11] = -m[0] * m[5] * m[11] +
  m[0] * m[7] * m[9] +
  m[4] * m[1] * m[11] -
  m[4] * m[3] * m[9] -
  m[8] * m[1] * m[7] +
  m[8] * m[3] * m[5];
  
  inv[15] = m[0] * m[5] * m[10] -
  m[0] * m[6] * m[9] -
  m[4] * m[1] * m[10] +
  m[4] * m[2] * m[9] +
  m[8] * m[1] * m[6] -
  m[8] * m[2] * m[5];
  
  det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
  
  for (i = 0; i < 16; ++i)
    out[i] = inv[i] / det;
}

inline void invert_orthonormal(float* out, const float* in)
{
  // transpose
  out[0] = in[0];
  out[1] = in[4];
  out[2] = in[8];
  out[4] = in[1];
  out[5] = in[5];
  out[6] = in[9];
  out[8] = in[2];
  out[9] = in[6];
  out[10] = in[10];
  out[3] = 0;
  out[7] = 0;
  out[11] = 0;
  out[15] = 1;
  
  // translation
  out[12] = -(in[0] * in[12] + in[1] * in[13] + in[2] * in[14]);
  out[13] = -(in[4] * in[12] + in[5] * in[13] + in[6] * in[14]);
  out[14] = -(in[8] * in[12] + in[9] * in[13] + in[10] * in[14]);
}

inline void matrix_multiply(float* out, const float* left, const float* right)
{
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      out[i + (j << 2)] = left[i] * right[(j << 2)] + left[i + 4] * right[(j << 2) + 1] + left[i + 8] * right[(j << 2) + 2] + left[i + 12] * right[(j << 2) + 3];
    }
  }
}
} // namespace

void test_array4x4()
{
  using namespace ma;
  array4x4<float> m, m2, m_inv, m_inv_inv;
  float inv[16];
  m = get_identity<float>();
  
  TEST_EQ(1.f, m[0]);
  TEST_EQ(0.f, m[1]);
  TEST_EQ(0.f, m[2]);
  TEST_EQ(0.f, m[3]);
  TEST_EQ(0.f, m[4]);
  TEST_EQ(1.f, m[5]);
  TEST_EQ(0.f, m[6]);
  TEST_EQ(0.f, m[7]);
  TEST_EQ(0.f, m[8]);
  TEST_EQ(0.f, m[9]);
  TEST_EQ(1.f, m[10]);
  TEST_EQ(0.f, m[11]);
  TEST_EQ(0.f, m[12]);
  TEST_EQ(0.f, m[13]);
  TEST_EQ(0.f, m[14]);
  TEST_EQ(1.f, m[15]);
  
  for (int i = 0; i < 16; ++i)
    m2[i] = (float)i;
  m = transpose(m2);
  TEST_EQ(0.f, m[0]);
  TEST_EQ(4.f, m[1]);
  TEST_EQ(8.f, m[2]);
  TEST_EQ(12.f, m[3]);
  TEST_EQ(1.f, m[4]);
  TEST_EQ(5.f, m[5]);
  TEST_EQ(9.f, m[6]);
  TEST_EQ(13.f, m[7]);
  TEST_EQ(2.f, m[8]);
  TEST_EQ(6.f, m[9]);
  TEST_EQ(10.f, m[10]);
  TEST_EQ(14.f, m[11]);
  TEST_EQ(3.f, m[12]);
  TEST_EQ(7.f, m[13]);
  TEST_EQ(11.f, m[14]);
  TEST_EQ(15.f, m[15]);
  
  m = get_identity<float>();
  m[0] = 1.f / sqrt(2.f);
  m[1] = 1.f / sqrt(2.f);
  m[4] = -1.f / sqrt(2.f);
  m[5] = 1.f / sqrt(2.f);
  m[10] = 1.f;
  m[12] = 31.f;
  m[13] = 52.f;
  m[14] = -27.f;
  
  invert_orthonormal(inv, m.f.data());
  
  m_inv = invert_orthonormal(m);
  
  for (int i = 0; i < 16; ++i)
  {
    TEST_EQ_CLOSE(inv[i], m_inv[i], 1e-5);
  }
  
  m_inv_inv = invert_orthonormal(m_inv);
  for (int i = 0; i < 16; ++i)
  {
    TEST_EQ_CLOSE(m[i], m_inv_inv[i], 1e-5f);
  }
  
  m = get_identity<float>();
  m[0] = 1.f / sqrt(2.f);
  m[1] = 1.f / sqrt(2.f);
  m[4] = -1.f / sqrt(2.f);
  m[5] = 1.f / sqrt(2.f);
  m[10] = 1.f;
  m[12] = 31.f;
  m[13] = 52.f;
  m[14] = -27.f;
  
  invert(inv, m.f.data());
  
  m_inv = invert(m);
  
  for (int i = 0; i < 16; ++i)
  {
    TEST_EQ_CLOSE(inv[i], m_inv[i], 1e-5f);
  }
  
  m_inv_inv = invert(m_inv);
  for (int i = 0; i < 16; ++i)
  {
    TEST_EQ_CLOSE(m[i], m_inv_inv[i], 1e-5f);
  }
  
  m[0] = 0.f;
  m[1] = 3.f;
  m[2] = 0.f;
  m[3] = 0.f;
  
  m[4] = 2.f;
  m[5] = 7.f;
  m[6] = 0.f;
  m[7] = 1.f;
  
  m[8] = 8.f;
  m[9] = 1.f;
  m[10] = 1.f;
  m[11] = 0.f;
  
  m[12] = 6.f;
  m[13] = 0.f;
  m[14] = 2.f;
  m[15] = 1.f;
  
  invert(inv, m.f.data());
  
  m_inv = invert(m);
  
  for (int i = 0; i < 16; ++i)
  {
    TEST_EQ_CLOSE(inv[i], m_inv[i], 1e-5f);
  }
  
  m_inv_inv = invert(m_inv);
  for (int i = 0; i < 16; ++i)
  {
    TEST_EQ_CLOSE(m[i], m_inv_inv[i], 1e-5f);
  }
  
  m = get_identity<float>();
  m[0] = 1.f / sqrt(2.f);
  m[1] = 1.f / sqrt(2.f);
  m[4] = -1.f / sqrt(2.f);
  m[5] = 1.f / sqrt(2.f);
  m[10] = 1.f;
  m[12] = 31.f;
  m[13] = 52.f;
  m[14] = -27.f;
  
  std::array<float, 4> v0({{1.f, 0.f, 0.f, 0.f}});
  auto res = matrix_vector_multiply(m, v0);
  TEST_EQ(m[0], res[0]);
  TEST_EQ(m[1], res[1]);
  TEST_EQ(m[2], res[2]);
  TEST_EQ(m[3], res[3]);
  
  std::array<float, 4> v1({{0.f, 1.f, 0.f, 0.f}});
  res = matrix_vector_multiply(m, v1);
  TEST_EQ(m[4], res[0]);
  TEST_EQ(m[5], res[1]);
  TEST_EQ(m[6], res[2]);
  TEST_EQ(m[7], res[3]);
  
  std::array<float, 4> v2({{0.f, 0.f, 1.f, 0.f}});
  res = matrix_vector_multiply(m, v2);
  TEST_EQ(m[8], res[0]);
  TEST_EQ(m[9], res[1]);
  TEST_EQ(m[10], res[2]);
  TEST_EQ(m[11], res[3]);
  
  std::array<float, 4> v3({{0.f, 0.f, 0.f, 1.f}});
  res = matrix_vector_multiply(m, v3);
  TEST_EQ(m[12], res[0]);
  TEST_EQ(m[13], res[1]);
  TEST_EQ(m[14], res[2]);
  TEST_EQ(m[15], res[3]);
  
  m = get_identity<float>();
  m[0] = 1.f / sqrt(2.f);
  m[1] = 1.f / sqrt(2.f);
  m[4] = -1.f / sqrt(2.f);
  m[5] = 1.f / sqrt(2.f);
  m[10] = 1.f;
  m[12] = 31.f;
  m[13] = 52.f;
  m[14] = -27.f;
  
  m_inv = invert_orthonormal(m);
  m2 = matrix_matrix_multiply(m, m_inv);
  
  TEST_EQ_CLOSE(1.f, m2[0], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[1], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[2], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[3], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[4], 1e-5f);
  TEST_EQ_CLOSE(1.f, m2[5], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[6], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[7], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[8], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[9], 1e-5f);
  TEST_EQ_CLOSE(1.f, m2[10], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[11], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[12], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[13], 1e-5f);
  TEST_EQ_CLOSE(0.f, m2[14], 1e-5f);
  TEST_EQ_CLOSE(1.f, m2[15], 1e-5f);
}

} // anonymous namespace

void run_math_array_tests()
{
  run_typed_math_array_tests<float>();
  run_typed_math_array_tests<double>();
  run_typed_math_array_tests<int>();
  run_typed_math_array_tests<custom_stuff::custom_object>();
  run_all_lookat_tests();
  run_all_quaternion_tests();
  test_array4x4();
}
