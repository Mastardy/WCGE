#pragma once

#include "../Core/Math/Math.hpp"

namespace WCGE
{
    class Physics
    {
    public:
        static inline bool CircleCircleCollision(const Math::Vector2& circle1Pos, float circle1Radius, const Math::Vector2& circle2Pos, float circle2Radius)
        {
            return (circle1Pos - circle2Pos).Magnitude() <= circle1Radius + circle2Radius;
        }
    };
}
