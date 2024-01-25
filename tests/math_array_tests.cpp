#include "math_array_tests.h"

#include "../math_array.h"
#include "test_assert.h"

#define NDIM 10

namespace
{

  template <class T>
  struct math_array_fixture
  {
    math_array_fixture()
    {
      a2 = { { 1,2} };
      b2 = { { 3,4} };
      a3 = { { 1,2,3} };
      b3 = { { 4,5,6} };
      a4 = { { 1,2,3,4 } };
      b4 = { { 5,6,7,8} };
      for (int i = 0; i < NDIM; ++i)
      {
        an[i] = static_cast<T>(i + 1);
        bn[i] = static_cast<T>(NDIM + i + 1);
      }
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
      auto res2 = a2 + b2;
      for (int i = 0; i < 2; ++i)
        TEST_EQ(a2[i] + b2[i], res2[i]);
      auto res3 = a3 + b3;
      for (int i = 0; i < 3; ++i)
        TEST_EQ(a3[i] + b3[i], res3[i]);
      auto res4 = a4 + b4;
      for (int i = 0; i < 4; ++i)
        TEST_EQ(a4[i] + b4[i], res4[i]);
      auto resn = an + bn;
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(an[i] + bn[i], resn[i]);
    }
  };

  template <class T>
  struct subtract_vectors : public math_array_fixture<T>
  {
    void test()
    {
      auto res2 = a2 - b2;
      for (int i = 0; i < 2; ++i)
        TEST_EQ(a2[i] - b2[i], res2[i]);
      auto res3 = a3 - b3;
      for (int i = 0; i < 3; ++i)
        TEST_EQ(a3[i] - b3[i], res3[i]);
      auto res4 = a4 - b4;
      for (int i = 0; i < 4; ++i)
        TEST_EQ(a4[i] - b4[i], res4[i]);
      auto resn = an - bn;
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(an[i] - bn[i], resn[i]);
    }
  };

  template <class T>
  void run_typed_math_array_tests()
  {
    add_vectors<T>().test();
    subtract_vectors<T>().test();
  }
}

void run_math_array_tests()
{
  run_typed_math_array_tests<float>();
  run_typed_math_array_tests<double>();
  run_typed_math_array_tests<int>();
}