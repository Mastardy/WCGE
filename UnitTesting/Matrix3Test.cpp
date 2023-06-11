#include "gtest/gtest.h"
#include <WCGE.hpp>

TEST(Matrix3Test, TestAssignment)
{
    const Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 m2 = m1;

    EXPECT_FLOAT_EQ(m2[0], 1);
    EXPECT_FLOAT_EQ(m2[1], 2);
    EXPECT_FLOAT_EQ(m2[2], 3);
    EXPECT_FLOAT_EQ(m2[3], 4);
    EXPECT_FLOAT_EQ(m2[4], 5);
    EXPECT_FLOAT_EQ(m2[5], 6);
    EXPECT_FLOAT_EQ(m2[6], 7);
    EXPECT_FLOAT_EQ(m2[7], 8);
    EXPECT_FLOAT_EQ(m2[8], 9);
}

TEST(Matrix3Test, TestSubscriptOperator)
{
    const Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);

    EXPECT_FLOAT_EQ(m[0], 1);
    EXPECT_FLOAT_EQ(m[1], 2);
    EXPECT_FLOAT_EQ(m[2], 3);
    EXPECT_FLOAT_EQ(m[3], 4);
    EXPECT_FLOAT_EQ(m[4], 5);
    EXPECT_FLOAT_EQ(m[5], 6);
    EXPECT_FLOAT_EQ(m[6], 7);
    EXPECT_FLOAT_EQ(m[7], 8);
    EXPECT_FLOAT_EQ(m[8], 9);
}

TEST(Matrix3Test, TestEquality)
{
    const Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 m2(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 m3(9, 8, 7, 6, 5, 4, 3, 2, 1);

    EXPECT_TRUE(m1 == m2);
    EXPECT_EQ(m1, m2);
    EXPECT_FALSE(m1 == m3);
}

TEST(Matrix3Test, TestInequality)
{
    const Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 m2(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 m3(9, 8, 7, 6, 5, 4, 3, 2, 1);

    EXPECT_FALSE(m1 != m2);
    EXPECT_TRUE(m1 != m3);
}

TEST(Matrix3Test, TestAddition)
{
    const Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 m2(9, 8, 7, 6, 5, 4, 3, 2, 1);

    const Matrix3 result = m1 + m2;

    EXPECT_FLOAT_EQ(result[0], 10);
    EXPECT_FLOAT_EQ(result[1], 10);
    EXPECT_FLOAT_EQ(result[2], 10);
    EXPECT_FLOAT_EQ(result[3], 10);
    EXPECT_FLOAT_EQ(result[4], 10);
    EXPECT_FLOAT_EQ(result[5], 10);
    EXPECT_FLOAT_EQ(result[6], 10);
    EXPECT_FLOAT_EQ(result[7], 10);
    EXPECT_FLOAT_EQ(result[8], 10);
}

TEST(Matrix3Test, TestAdditionAssignment)
{
    Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 m2(9, 8, 7, 6, 5, 4, 3, 2, 1);
    
    m1 += m2;

    EXPECT_FLOAT_EQ(m1[0], 10);
    EXPECT_FLOAT_EQ(m1[1], 10);
    EXPECT_FLOAT_EQ(m1[2], 10);
    EXPECT_FLOAT_EQ(m1[3], 10);
    EXPECT_FLOAT_EQ(m1[4], 10);
    EXPECT_FLOAT_EQ(m1[5], 10);
    EXPECT_FLOAT_EQ(m1[6], 10);
    EXPECT_FLOAT_EQ(m1[7], 10);
    EXPECT_FLOAT_EQ(m1[8], 10);
}

TEST(Matrix3Test, TestSubtraction)
{
    const Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 m2(9, 8, 7, 6, 5, 4, 3, 2, 1);

    const Matrix3 result = m1 - m2;

    EXPECT_FLOAT_EQ(result[0], -8);
    EXPECT_FLOAT_EQ(result[1], -6);
    EXPECT_FLOAT_EQ(result[2], -4);
    EXPECT_FLOAT_EQ(result[3], -2);
    EXPECT_FLOAT_EQ(result[4], 0);
    EXPECT_FLOAT_EQ(result[5], 2);
    EXPECT_FLOAT_EQ(result[6], 4);
    EXPECT_FLOAT_EQ(result[7], 6);
    EXPECT_FLOAT_EQ(result[8], 8);
}

TEST(Matrix3Test, TestSubtractionAssignment)
{
    Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 m2(9, 8, 7, 6, 5, 4, 3, 2, 1);

    m1 -= m2;

    EXPECT_FLOAT_EQ(m1[0], -8);
    EXPECT_FLOAT_EQ(m1[1], -6);
    EXPECT_FLOAT_EQ(m1[2], -4);
    EXPECT_FLOAT_EQ(m1[3], -2);
    EXPECT_FLOAT_EQ(m1[4], 0);
    EXPECT_FLOAT_EQ(m1[5], 2);
    EXPECT_FLOAT_EQ(m1[6], 4);
    EXPECT_FLOAT_EQ(m1[7], 6);
    EXPECT_FLOAT_EQ(m1[8], 8);
}

TEST(Matrix3Test, TestMultiplication)
{
    const Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 m2(9, 8, 7, 6, 5, 4, 3, 2, 1);

    const Matrix3 result = m1 * m2;

    EXPECT_FLOAT_EQ(result[0], 30);
    EXPECT_FLOAT_EQ(result[1], 24);
    EXPECT_FLOAT_EQ(result[2], 18);
    EXPECT_FLOAT_EQ(result[3], 84);
    EXPECT_FLOAT_EQ(result[4], 69);
    EXPECT_FLOAT_EQ(result[5], 54);
    EXPECT_FLOAT_EQ(result[6], 138);
    EXPECT_FLOAT_EQ(result[7], 114);
    EXPECT_FLOAT_EQ(result[8], 90);
}

TEST(Matrix3Test, TestMultiplicationAssignment)
{
    Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 m2(9, 8, 7, 6, 5, 4, 3, 2, 1);

    m1 *= m2;

    EXPECT_FLOAT_EQ(m1[0], 30);
    EXPECT_FLOAT_EQ(m1[1], 24);
    EXPECT_FLOAT_EQ(m1[2], 18);
    EXPECT_FLOAT_EQ(m1[3], 84);
    EXPECT_FLOAT_EQ(m1[4], 69);
    EXPECT_FLOAT_EQ(m1[5], 54);
    EXPECT_FLOAT_EQ(m1[6], 138);
    EXPECT_FLOAT_EQ(m1[7], 114);
    EXPECT_FLOAT_EQ(m1[8], 90);
}

TEST(Matrix3Test, TestScalarMultiplication)
{
    const Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);

    const Matrix3 result = m * 2.0f;

    EXPECT_FLOAT_EQ(result[0], 2);
    EXPECT_FLOAT_EQ(result[1], 4);
    EXPECT_FLOAT_EQ(result[2], 6);
    EXPECT_FLOAT_EQ(result[3], 8);
    EXPECT_FLOAT_EQ(result[4], 10);
    EXPECT_FLOAT_EQ(result[5], 12);
    EXPECT_FLOAT_EQ(result[6], 14);
    EXPECT_FLOAT_EQ(result[7], 16);
    EXPECT_FLOAT_EQ(result[8], 18);
}

TEST(Matrix3Test, TestScalarMultiplicationAssignment)
{
    Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);

    m *= 2.0f;

    EXPECT_FLOAT_EQ(m[0], 2);
    EXPECT_FLOAT_EQ(m[1], 4);
    EXPECT_FLOAT_EQ(m[2], 6);
    EXPECT_FLOAT_EQ(m[3], 8);
    EXPECT_FLOAT_EQ(m[4], 10);
    EXPECT_FLOAT_EQ(m[5], 12);
    EXPECT_FLOAT_EQ(m[6], 14);
    EXPECT_FLOAT_EQ(m[7], 16);
    EXPECT_FLOAT_EQ(m[8], 18);
}

TEST(Matrix3Test, TestDeterminant)
{
    const Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);

    const float result = m.Determinant();

    EXPECT_FLOAT_EQ(result, 0);
}

TEST(Matrix3Test, TestTranspose)
{
    const Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);

    const Matrix3 result = m.Transpose();

    EXPECT_FLOAT_EQ(result[0], 1);
    EXPECT_FLOAT_EQ(result[1], 4);
    EXPECT_FLOAT_EQ(result[2], 7);
    EXPECT_FLOAT_EQ(result[3], 2);
    EXPECT_FLOAT_EQ(result[4], 5);
    EXPECT_FLOAT_EQ(result[5], 8);
    EXPECT_FLOAT_EQ(result[6], 3);
    EXPECT_FLOAT_EQ(result[7], 6);
    EXPECT_FLOAT_EQ(result[8], 9);
}

TEST(Matrix3TEST, TestInverse0)
{
    const Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
    const Matrix3 result = m.Inverse();

    const Matrix3 expected = Matrix3::zero;

    EXPECT_EQ(result, expected);
}

TEST(Matrix3Test, TestInverse)
{
    const Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 10);
    const Matrix3 result = m.Inverse();

    EXPECT_FLOAT_EQ(result[0], -0.6666666f);
    EXPECT_FLOAT_EQ(result[1], -1.3333333f);
    EXPECT_FLOAT_EQ(result[2], 1.0f);
    EXPECT_FLOAT_EQ(result[3], -0.6666666f);
    EXPECT_FLOAT_EQ(result[4], 3.6666666f);
    EXPECT_FLOAT_EQ(result[5], -2.0f);
    EXPECT_FLOAT_EQ(result[6], 1.0f);
    EXPECT_FLOAT_EQ(result[7], -2.0f);
    EXPECT_FLOAT_EQ(result[8], 1.0f);
}

TEST(Matrix3Test, TestIsIdentity)
{
    const Matrix3 m1(1, 0, 0, 0, 1, 0, 0, 0, 1);
    const Matrix3 m2(1, 0, 0, 0, 1, 0, 0, 0, 0);

    EXPECT_TRUE(m1.IsIdentity());
    EXPECT_FALSE(m2.IsIdentity());
}

TEST(Matrix3Test, TestIsZero)
{
    const Matrix3 m1(0, 0, 0, 0, 0, 0, 0, 0, 0);
    const Matrix3 m2(0, 0, 0, 0, 0, 0, 0, 0, 1);

    EXPECT_TRUE(m1.IsZero());
    EXPECT_FALSE(m2.IsZero());
}

TEST(Matrix3Test, TestMatrix2Determinant)
{
    const float result = Matrix3::Matrix2Determinant(1, 2, 3, 4);

    EXPECT_EQ(result, -2);
}