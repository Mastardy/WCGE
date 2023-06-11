#include "gtest/gtest.h"

#include <WCGE.hpp>

TEST(Vector3Test, TestConstructor)
{
    const Vector3 v(1.3f, 2.6f, 3.9f);
    EXPECT_FLOAT_EQ(v.x, 1.3f);
    EXPECT_FLOAT_EQ(v.y, 2.6f);
    EXPECT_FLOAT_EQ(v.z, 3.9f);
}

TEST(Vector3Test, TestAddition)
{
    const Vector3 v1(1, 2, 3);
    const Vector3 v2(4, 5, 6);
    const Vector3 v3 = v1 + v2;
    EXPECT_FLOAT_EQ(v3.x, 5);
    EXPECT_FLOAT_EQ(v3.y, 7);
    EXPECT_FLOAT_EQ(v3.z, 9);
}

TEST(Vector3Test, TestSubtraction)
{
    const Vector3 v1(4, 5, 6);
    const Vector3 v2(1, 2, 3);
    const Vector3 v3 = v1 - v2;
    EXPECT_FLOAT_EQ(v3.x, 3);
    EXPECT_FLOAT_EQ(v3.y, 3);
    EXPECT_FLOAT_EQ(v3.z, 3);
}

TEST(Vector3Test, TestMultiplication)
{
    const Vector3 v1(1, 2, 3);
    const Vector3 v2(2, 3, 4);
    const Vector3 v3 = v1 * v2;
    EXPECT_FLOAT_EQ(v3.x, 2);
    EXPECT_FLOAT_EQ(v3.y, 6);
    EXPECT_FLOAT_EQ(v3.z, 12);
}

TEST(Vector3Test, TestDivision)
{
    const Vector3 v1(2, 6, 12);
    const Vector3 v2(2, 3, 4);
    const Vector3 v3 = v1 / v2;
    EXPECT_FLOAT_EQ(v3.x, 1);
    EXPECT_FLOAT_EQ(v3.y, 2);
    EXPECT_FLOAT_EQ(v3.z, 3);
}

TEST(Vector3Test, TestMagnitude)
{
    const Vector3 v(3, 4, 5);
    EXPECT_FLOAT_EQ(v.Magnitude(), sqrtf(50));
}

TEST(Vector3Test, TestSqrMagnitude)
{
    const Vector3 v(3, 4, 5);
    EXPECT_FLOAT_EQ(v.SqrMagnitude(), 50);
}

TEST(Vector3Test, TestDotProduct)
{
    const Vector3 v1(1, 2, 3);
    const Vector3 v2(4, 5, 6);
    EXPECT_FLOAT_EQ(Vector3::Dot(v1, v2), 32);
}

TEST(Vector3Test, TestNormalize)
{
    Vector3 v(3, 4, 5);
    v.Normalize();
    EXPECT_FLOAT_EQ(v.x, 3.0f / sqrtf(50));
    EXPECT_FLOAT_EQ(v.y, 4.0f / sqrtf(50));
    EXPECT_FLOAT_EQ(v.z, 5.0f / sqrtf(50));
}

TEST(Vector3Test, TestCross)
{
    const Vector3 v1(1, 0, 0);
    const Vector3 v2(0, 1, 0);

    const Vector3 result = Vector3::Cross(v1, v2);

    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, 0);
    EXPECT_EQ(result.z, 1);
}

TEST(Vector3Test, TestDistance)
{
    const Vector3 v1(1, 2, 3);
    const Vector3 v2(4, 5, 6);

    const float result = Vector3::Distance(v1, v2);

    EXPECT_FLOAT_EQ(result, 5.196152f);
}

TEST(Vector3Test, TestLerp)
{
    const Vector3 start(1, 2, 3);
    const Vector3 end(4, 5, 6);

    const Vector3 result = Vector3::Lerp(start, end, 0.5f);

    EXPECT_EQ(result.x, 2.5f);
    EXPECT_EQ(result.y, 3.5f);
    EXPECT_EQ(result.z, 4.5f);
}

TEST(Vector3Test, TestScale)
{
    const Vector3 v(1, 2, 3);
    const Vector3 scalar(2, 3, 4);

    const Vector3 result = Vector3::Scale(v, scalar);

    EXPECT_EQ(result.x, 2);
    EXPECT_EQ(result.y, 6);
    EXPECT_EQ(result.z, 12);
}

TEST(Vector3Test, TestSlerp)
{
    const Vector3 start(1, 0, 0);
    const Vector3 end(0, 1, 0);

    const Vector3 result = Vector3::Slerp(start, end, 0.5f);

    EXPECT_FLOAT_EQ(result.x, 0.707107f);
    EXPECT_FLOAT_EQ(result.y, 0.707107f);
    EXPECT_EQ(result.z, 0);
}