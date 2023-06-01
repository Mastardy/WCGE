#include "gtest/gtest.h"
#include <WCGE.hpp>

TEST(Matrix4Test, TestAddition)
{
    const Matrix4 a(1, 2, 3, 4,
              5, 6, 7, 8,
              9, 10, 11, 12,
              13, 14, 15, 16);
    
    const Matrix4 b(16, 15, 14, 13,
              12, 11, 10, 9,
              8, 7, 6, 5,
              4, 3, 2, 1);
    
    const Matrix4 expected(17, 17, 17, 17,
                     17, 17, 17, 17,
                     17, 17, 17, 17,
                     17, 17, 17, 17);

    const Matrix4 result = a + b;

    for(int i = 0; i < 4 * 4; i++)
    {
        EXPECT_FLOAT_EQ(result[i], expected[i]);
    }
}

TEST(Matrix4Test, TestSubtraction)
{
    const Matrix4 a(1, 2, 3, 4,
              5, 6, 7, 8,
              9, 10, 11, 12,
              13, 14, 15, 16);
    
    const Matrix4 b(16, 15, 14, 13,
              12, 11, 10, 9,
              8, 7, 6, 5,
              4, 3, 2, 1);
    
    const Matrix4 expected(-15, -13, -11, -9,
                     -7, -5, -3, -1,
                     1, 3, 5, 7,
                     9, 11, 13, 15);

    const Matrix4 result = a - b;
    
    for(int i = 0; i < 4 * 4; i++)
    {
        EXPECT_FLOAT_EQ(result[i], expected[i]);
    }
}

TEST(Matrix4Test, TestMultiplication)
{
    const Matrix4 a(1, 2, 3, 4,
              5, 6, 7, 8,
              9, 10, 11, 12,
              13, 14, 15, 16);
    
    const Matrix4 b(16, 15, 14, 13,
              12, 11, 10, 9,
              8, 7, 6, 5,
              4, 3, 2, 1);
    
    const Matrix4 expected(80, 70, 60, 50,
                     240, 214, 188, 162,
                     400, 358, 316, 274,
                     560, 502, 444, 386);

    const Matrix4 result = a * b;

    for(int i = 0; i < 4 * 4; i++)
    {
        EXPECT_FLOAT_EQ(result[i], expected[i]);
    }
}

TEST(Matrix4Test, TestMultiplicationByScalar)
{
    const Matrix4 a(1, 2, 3, 4,
              5, 6, 7, 8,
              9, 10, 11, 12,
              13, 14, 15, 16);
    
    constexpr float scalar = 2.0f;
    
    const Matrix4 expected(2, 4, 6, 8,
                     10, 12, 14, 16,
                     18, 20, 22, 24,
                     26, 28, 30, 32);

    const Matrix4 result = a * scalar;

    for(int i = 0; i < 4 * 4; i++)
    {
        EXPECT_FLOAT_EQ(result[i], expected[i]);
    }
}

TEST(Matrix4Test, TestDeterminant)
{
    const Matrix4 a(1, 2, 3, 4,
              5, 6, 7, 8,
              9, 10, 11, 12,
              13, 14, 15, 16);
    
    constexpr float expected = 0.0f;

    const float result = a.Determinant();

    EXPECT_FLOAT_EQ(result, expected);
}

TEST(Matrix4Test, TestInverse)
{
    const Matrix4 a(1, 2, 3, 4,
              5, 6, 7, 8,
              9, 10, 11, 12,
              13, 14, 15, 16);
    const Matrix4 expected(0.0f);

    const Matrix4 result = a.Inverse();
    
    for(int i = 0; i < 4 * 4; i++)
    {
        EXPECT_FLOAT_EQ(result[i], expected[i]);
    }
}

TEST(Matrix4Test, TestTranspose)
{
    const Matrix4 a(1, 2, 3, 4,
              5, 6, 7, 8,
              9, 10, 11, 12,
              13, 14, 15, 16);
    const Matrix4 expected(1, 5, 9, 13,
                     2, 6, 10, 14,
                     3, 7, 11, 15,
                     4, 8, 12, 16);

    const Matrix4 result = a.Transpose();

    for(int i = 0; i < 4 * 4; i++)
    {
        EXPECT_FLOAT_EQ(result[i], expected[i]);
    }
}

TEST(Matrix4Test, TestIsIdentity)
{
    const Matrix4 a(1, 0, 0, 0,
              0, 1, 0, 0,
              0, 0, 1, 0,
              0, 0, 0, 1);

    const bool result = a.IsIdentity();

    EXPECT_TRUE(result);
}

TEST(Matrix4Test, TestIsZero)
{
    const Matrix4 a(0, 0, 0, 0,
              0, 0, 0, 0,
              0, 0, 0, 0,
              0, 0, 0, 0);

    const bool result = a.IsZero();

    EXPECT_TRUE(result);
}