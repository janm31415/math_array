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
      a2 = { { 1,4} };
      b2 = { { 3,2} };
      a3 = { { 1,2,6} };
      b3 = { { 4,5,3} };
      a4 = { { 1,2,3,8 } };
      b4 = { { 5,6,7,4} };
      for (int i = 0; i < NDIM; ++i)
      {
        an[i] = static_cast<T>(i + 1);
        bn[i] = static_cast<T>(NDIM + i + 1);
      }
      auto tmp = bn[NDIM - 1];
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

      res2 = a2 + static_cast<T>(2);
      for (int i = 0; i < 2; ++i)
        TEST_EQ(a2[i] + 2, res2[i]);
      res3 = a3 + static_cast<T>(2);
      for (int i = 0; i < 3; ++i)
        TEST_EQ(a3[i] + 2, res3[i]);
      res4 = a4 + static_cast<T>(2);
      for (int i = 0; i < 4; ++i)
        TEST_EQ(a4[i] + 2, res4[i]);
      resn = an + static_cast<T>(2);
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(an[i] + 2, resn[i]);

      res2 = static_cast<T>(2) + b2;
      for (int i = 0; i < 2; ++i)
        TEST_EQ(2 + b2[i], res2[i]);
      res3 = static_cast<T>(2) + b3;
      for (int i = 0; i < 3; ++i)
        TEST_EQ(2 + b3[i], res3[i]);
      res4 = static_cast<T>(2) + b4;
      for (int i = 0; i < 4; ++i)
        TEST_EQ(2 + b4[i], res4[i]);
      resn = static_cast<T>(2) + bn;
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(2 + bn[i], resn[i]);
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

      res2 = a2 - static_cast<T>(2);
      for (int i = 0; i < 2; ++i)
        TEST_EQ(a2[i] - 2, res2[i]);
      res3 = a3 - static_cast<T>(2);
      for (int i = 0; i < 3; ++i)
        TEST_EQ(a3[i] - 2, res3[i]);
      res4 = a4 - static_cast<T>(2);
      for (int i = 0; i < 4; ++i)
        TEST_EQ(a4[i] - 2, res4[i]);
      resn = an - static_cast<T>(2);
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(an[i] - 2, resn[i]);

      res2 = static_cast<T>(2) - b2;
      for (int i = 0; i < 2; ++i)
        TEST_EQ(2 - b2[i], res2[i]);
      res3 = static_cast<T>(2) - b3;
      for (int i = 0; i < 3; ++i)
        TEST_EQ(2 - b3[i], res3[i]);
      res4 = static_cast<T>(2) - b4;
      for (int i = 0; i < 4; ++i)
        TEST_EQ(2 - b4[i], res4[i]);
      resn = static_cast<T>(2) - bn;
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(2 - bn[i], resn[i]);
    }
  };

  template <class T>
  struct multiply_vectors : public math_array_fixture<T>
  {
    void test()
    {
      auto res2 = a2 * b2;
      for (int i = 0; i < 2; ++i)
        TEST_EQ(a2[i] * b2[i], res2[i]);
      auto res3 = a3 * b3;
      for (int i = 0; i < 3; ++i)
        TEST_EQ(a3[i] * b3[i], res3[i]);
      auto res4 = a4 * b4;
      for (int i = 0; i < 4; ++i)
        TEST_EQ(a4[i] * b4[i], res4[i]);
      auto resn = an * bn;
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(an[i] * bn[i], resn[i]);

      res2 = a2 * static_cast<T>(2);
      for (int i = 0; i < 2; ++i)
        TEST_EQ(a2[i] * 2, res2[i]);
      res3 = a3 * static_cast<T>(2);
      for (int i = 0; i < 3; ++i)
        TEST_EQ(a3[i] * 2, res3[i]);
      res4 = a4 * static_cast<T>(2);
      for (int i = 0; i < 4; ++i)
        TEST_EQ(a4[i] * 2, res4[i]);
      resn = an * static_cast<T>(2);
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(an[i] * 2, resn[i]);

      res2 = static_cast<T>(2) * b2;
      for (int i = 0; i < 2; ++i)
        TEST_EQ(2 * b2[i], res2[i]);
      res3 = static_cast<T>(2) * b3;
      for (int i = 0; i < 3; ++i)
        TEST_EQ(2 * b3[i], res3[i]);
      res4 = static_cast<T>(2) * b4;
      for (int i = 0; i < 4; ++i)
        TEST_EQ(2 * b4[i], res4[i]);
      resn = static_cast<T>(2) * bn;
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(2 * bn[i], resn[i]);
    }
  };

  template <class T>
  struct divide_vectors : public math_array_fixture<T>
  {
    void test()
    {
      auto res2 = a2 / b2;
      for (int i = 0; i < 2; ++i)
        TEST_EQ(a2[i] / b2[i], res2[i]);
      auto res3 = a3 / b3;
      for (int i = 0; i < 3; ++i)
        TEST_EQ(a3[i] / b3[i], res3[i]);
      auto res4 = a4 / b4;
      for (int i = 0; i < 4; ++i)
        TEST_EQ(a4[i] / b4[i], res4[i]);
      auto resn = an / bn;
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(an[i] / bn[i], resn[i]);

      res2 = a2 / static_cast<T>(2);
      for (int i = 0; i < 2; ++i)
        TEST_EQ(a2[i] / 2, res2[i]);
      res3 = a3 / static_cast<T>(2);
      for (int i = 0; i < 3; ++i)
        TEST_EQ(a3[i] / 2, res3[i]);
      res4 = a4 / static_cast<T>(2);
      for (int i = 0; i < 4; ++i)
        TEST_EQ(a4[i] / 2, res4[i]);
      resn = an / static_cast<T>(2);
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(an[i] / 2, resn[i]);

      res2 = static_cast<T>(2) / b2;
      for (int i = 0; i < 2; ++i)
        TEST_EQ(2 / b2[i], res2[i]);
      res3 = static_cast<T>(2) / b3;
      for (int i = 0; i < 3; ++i)
        TEST_EQ(2 / b3[i], res3[i]);
      res4 = static_cast<T>(2) / b4;
      for (int i = 0; i < 4; ++i)
        TEST_EQ(2 / b4[i], res4[i]);
      resn = static_cast<T>(2) / bn;
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(2 / bn[i], resn[i]);
    }
  };


  template <class T>
  struct min_vectors : public math_array_fixture<T>
  {
    void test()
    {
      auto res2 = min(a2,b2);
      for (int i = 0; i < 2; ++i)
        TEST_EQ(std::min<T>(a2[i], b2[i]), res2[i]);
      auto res3 = min(a3, b3);
      for (int i = 0; i < 3; ++i)
        TEST_EQ(std::min<T>(a3[i], b3[i]), res3[i]);
      auto res4 = min(a4, b4);
      for (int i = 0; i < 4; ++i)
        TEST_EQ(std::min<T>(a4[i], b4[i]), res4[i]);
      auto resn = min(an, bn);
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(std::min<T>(an[i], bn[i]), resn[i]);
    }
  };

  template <class T>
  struct max_vectors : public math_array_fixture<T>
  {
    void test()
    {
      auto res2 = max(a2, b2);
      for (int i = 0; i < 2; ++i)
        TEST_EQ(std::max<T>(a2[i], b2[i]), res2[i]);
      auto res3 = max(a3, b3);
      for (int i = 0; i < 3; ++i)
        TEST_EQ(std::max<T>(a3[i], b3[i]), res3[i]);
      auto res4 = max(a4, b4);
      for (int i = 0; i < 4; ++i)
        TEST_EQ(std::max<T>(a4[i], b4[i]), res4[i]);
      auto resn = max(an, bn);
      for (int i = 0; i < NDIM; ++i)
        TEST_EQ(std::max<T>(an[i], bn[i]), resn[i]);
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
  }
}

void run_math_array_tests()
{
  run_typed_math_array_tests<float>();
  run_typed_math_array_tests<double>();
  run_typed_math_array_tests<int>();
}