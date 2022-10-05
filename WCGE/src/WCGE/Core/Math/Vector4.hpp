#pragma once

#include "../../Core.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

#include <string>
#include <array>

namespace WCGE::Math
{
	class WCGE_API Vector4
	{
	public:

		static const Vector4 zero;
		static const Vector4 one;

		static const Vector4 front;
		static const Vector4 back;
		static const Vector4 up;
		static const Vector4 down;
		static const Vector4 left;
		static const Vector4 right;

		union
		{
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
			std::array<float, 4> xyzw;
		};

		Vector4();
		Vector4(float value);
		Vector4(const Vector2& other);
		Vector4(float x, float y);
		Vector4(const Vector3& other);
		Vector4(float x, float y, float z);
		Vector4(const Vector4& other);
		Vector4(float x, float y, float z, float w);

		Vector4& operator=(const Vector4& other);
		float operator[](int i) const;

		bool operator==(const Vector4& other) const;
		bool operator!=(const Vector4& other) const;

		Vector4 operator+(const Vector4& other) const;
		Vector4& operator+=(const Vector4& other);

		Vector4 operator-(const Vector4& other) const;
		Vector4& operator-=(const Vector4& other);

		Vector4 operator*(float scalar) const;
		Vector4& operator*=(float scalar);

		Vector4 operator/(float scalar) const;
		Vector4& operator/=(float scalar);

		friend std::ostream& operator<<(std::ostream& os, const Vector4& vec4) { return os << vec4.ToString(); }

		bool Equals(const Vector4& other) const;
		float Magnitude() const;
		float SqrMagnitude() const;
		Vector4 Normalized() const;
		void Normalize();

		static float Cross(const Vector4& leftHandSide, const Vector4& rightHandSide);
		static float Distance(const Vector4& leftHandSide, const Vector4& rightHandSide);
		static float Dot(const Vector4& leftHandSide, const Vector4& rightHandSide);
		static Vector4 Lerp(const Vector4& start, const Vector4& end, float value);
		static Vector4 Scale(const Vector4& inVector, const Vector4& scalarVector);
		static Vector4 Slerp(const Vector4& start, const Vector4& end, float value);

		std::string ToString() const;
	};
}