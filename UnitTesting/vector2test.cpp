#include "gtest/gtest.h"

#include <WCGE.hpp>

TEST(Vector2Test, TestAddition)
{
    const Vector2 v1(1, 2);
    const Vector2 v2(3, 4);

    const Vector2 result = v1 + v2;

    EXPECT_FLOAT_EQ(result.x, 4);
    EXPECT_FLOAT_EQ(result.y, 6);
}

TEST(Vector2Test, TestSubtraction)
{
    const Vector2 v1(1, 2);
    const Vector2 v2(3, 4);

    const Vector2 result = v1 - v2;

    EXPECT_FLOAT_EQ(result.x, -2);
    EXPECT_FLOAT_EQ(result.y, -2);
}

TEST(Vector2Test, TestMagnitude)
{
    const Vector2 v(3, 4);

    const float result = v.Magnitude();

    EXPECT_FLOAT_EQ(result, 5.0f);
}

TEST(Vector2Test, TestAngle)
{
    const Vector2 v1(1, 0);
    const Vector2 v2(0, 1);

    const float result = Vector2::Angle(v1, v2);

    EXPECT_FLOAT_EQ(result, WCGE::Math::DEG2RAD * 90.0f);
}

TEST(Vector2Test, TestCross)
{
    const Vector2 v1(1, 0);
    const Vector2 v2(0, 1);

    const float result = Vector2::Cross(v1, v2);

    EXPECT_FLOAT_EQ(result, 1.0f);
}

TEST(Vector2Test, TestDistance)
{
    const Vector2 v1(1, 2);
    const Vector2 v2(4, 6);

    const float result = Vector2::Distance(v1, v2);

    EXPECT_FLOAT_EQ(result, 5);
}

TEST(Vector2Test, TestDot)
{
    const Vector2 v1(1, 2);
    const Vector2 v2(4, 5);

    const float result = Vector2::Dot(v1, v2);

    EXPECT_FLOAT_EQ(result, 14.0f);
}

TEST(Vector2Test, TestLerp)
{
    const Vector2 start(1, 2);
    const Vector2 end(4, 6);

    const Vector2 result = Vector2::Lerp(start, end, 0.5f);

    EXPECT_EQ(result.x, 2.5f);
    EXPECT_EQ(result.y, 4.0f);
}

TEST(Vector2Test, TestScale)
{
    const Vector2 v(1, 2);
    const Vector2 scalar(2, 3);

    const Vector2 result = Vector2::Scale(v, scalar);

    EXPECT_EQ(result.x, 2);
    EXPECT_EQ(result.y, 6);
}

TEST(Vector2Test, TestSlerp)
{
    const Vector2 start(1, 0);
    const Vector2 end(0, 1);

    const Vector2 result = Vector2::Slerp(start, end, 0.5f);

    EXPECT_FLOAT_EQ(result.x, 0.707107f);
    EXPECT_FLOAT_EQ(result.y, 0.707107f);
}