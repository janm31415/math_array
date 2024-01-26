#include "math_array_tests.h"
#include "test_assert.h"

#include "../math_array.h"

#define NDIM 10

//using namespace ma;

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
      bool operator != (const custom_object& other) const
        {
        return !(other == *this);
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
    
    custom_object sqrt(const custom_object& o)
      {
      return custom_object(::sqrt(o._value));
      }
    
    std::ostream& operator <<(std::ostream& stream, const custom_object& obj)
      {
      stream << obj._value;
      return stream;
      }

}

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
  }
}

void run_math_array_tests()
{
  run_typed_math_array_tests<float>();
  run_typed_math_array_tests<double>();
  run_typed_math_array_tests<int>();
  run_typed_math_array_tests<custom_stuff::custom_object>();
}
