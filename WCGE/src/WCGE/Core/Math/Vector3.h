#pragma once

#include "../../Core.h"
#include "Vector2.h"

#include <string>

namespace WCGE::Math
{
	class WCGE_API Vector3
	{
	public:

		static const Vector3 zero;
		static const Vector3 one;

		static const Vector3 front;
		static const Vector3 back;
		static const Vector3 up;
		static const Vector3 down;
		static const Vector3 left;
		static const Vector3 right;

		union
		{
			struct
			{
				float x;
				float y;
				float z;
			};
			float xyz[3];
		};

		Vector3();
		Vector3(float value);
		Vector3(const Vector2& other);
		Vector3(float x, float y);
		Vector3(float x, float y, float z);
		Vector3(const Vector3& other);

		Vector3& operator=(const Vector3& other);
		float operator[](int i) const;

		bool operator==(const Vector3& other) const;
		bool operator!=(const Vector3& other) const;

		Vector3 operator+(const Vector3& other) const;
		Vector3& operator+=(const Vector3& other);

		Vector3 operator-(const Vector3& other) const;
		Vector3& operator-=(const Vector3& other);

		Vector3 operator*(float scalar) const;
		Vector3& operator*=(float scalar);

		Vector3 operator/(float scalar) const;
		Vector3& operator/=(float scalar);

		bool Equals(const Vector3& other) const;
		float Magnitude() const;
		float SqrMagnitude() const;
		Vector3 Normalized() const;
		void Normalize();

		static float Cross(const Vector3& leftHandSide, const Vector3& rightHandSide);
		static float Distance(const Vector3& leftHandSide, const Vector3& rightHandSide);
		static float Dot(const Vector3& leftHandSide, const Vector3& rightHandSide);
		static Vector3 Lerp(const Vector3& start, const Vector3& end, float value);
		static Vector3 Scale(const Vector3& inVector, const Vector3& scalarVector);
		static Vector3 Slerp(const Vector3& start, const Vector3& end, float value);

		std::string ToString();
	};
}