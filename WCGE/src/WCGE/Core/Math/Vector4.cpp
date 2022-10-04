#include "Vector4.h"

#include <cmath>
#include <stdexcept>
#include <string>
#include <sstream>

namespace WCGE::Math
{
	//
	// Constants
	//

	const Vector4 Vector4::zero = Vector4();
	const Vector4 Vector4::one = Vector4(1.0f);

	const Vector4 Vector4::front = Vector4(1.0f, 0.0f, 0.0f);
	const Vector4 Vector4::right = Vector4(0.0f, 1.0f, 0.0f);
	const Vector4 Vector4::up = Vector4(0.0f, 0.0f, 1.0f);
	const Vector4 Vector4::back = Vector4(-1.0f, 0.0f, 0.0f);
	const Vector4 Vector4::left = Vector4(0.0f, -1.0f, 0.0f);
	const Vector4 Vector4::down = Vector4(0.0f, 0.0f, -1.0f);

	//
	// Constructors
	//

	Vector4::Vector4() : x{0}, y{0}, z{0}, w{0} {}
	Vector4::Vector4(float value) : x{value}, y{value}, z{value}, w{value} {}
	Vector4::Vector4(const Vector2& other) : x{other.x}, y{other.y}, z{0}, w{0} {}
	Vector4::Vector4(float x, float y) : x{x}, y{y}, z{0}, w{0} {}
	Vector4::Vector4(const Vector3& other) : x{other.x}, y{other.y}, z{other.z}, w{0} {}
	Vector4::Vector4(float x, float y, float z) : x{x}, y{y}, z{z}, w{0} {}
	Vector4::Vector4(const Vector4& other) : x{other.x}, y{other.y}, z{other.z}, w{other.w} {}
	Vector4::Vector4(float x, float y, float z, float w) : x{x}, y{y}, z{z}, w{w} {}

	//
	// Operators
	//

	Vector4& Vector4::operator=(const Vector4& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}

	float Vector4::operator[](int i) const
	{
		if(i < 0 || i > 3)
		{
			throw std::out_of_range("Vector4[] - Index out of range.");
		}

		return xyzw[i];
	}

	bool Vector4::operator==(const Vector4& other) const
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}
	bool Vector4::operator!=(const Vector4& other) const
	{
		return !(*this == other);
	}

	Vector4 Vector4::operator+(const Vector4& other) const
	{
		return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
	}
	Vector4& Vector4::operator+=(const Vector4& other)
	{
		*this = *this + other;
		return *this;
	}

	Vector4 Vector4::operator-(const Vector4& other) const
	{
		return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
	}
	Vector4& Vector4::operator-=(const Vector4& other)
	{
		*this = *this - other;
		return *this;
	}

	Vector4 Vector4::operator*(float scalar) const
	{
		return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
	}
	Vector4& Vector4::operator*=(float scalar)
	{
		*this = *this * scalar;
		return *this;
	}

	Vector4 Vector4::operator/(float scalar) const
	{
		return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
	}
	Vector4& Vector4::operator/=(float scalar)
	{
		*this = *this / scalar;
		return *this;
	}

	//
	// Member Methods
	//

	bool Vector4::Equals(const Vector4& other) const
	{
		return abs(other.x - x) < FLT_EPSILON && abs(other.y - y) < FLT_EPSILON && abs(other.z - z) < FLT_EPSILON && abs(other.w - w) < FLT_EPSILON;
	}

	float Vector4::Magnitude() const
	{
		return sqrtf(SqrMagnitude());
	}

	float Vector4::SqrMagnitude() const
	{
		return x * x + y * y + z * z + w * w;
	}

	Vector4 Vector4::Normalized() const
	{
		float magnitude = Magnitude();
		if(magnitude == 0) return zero;
		return Vector4(*this / magnitude);
	}

	void Vector4::Normalize()
	{
		auto normalized = this->Normalized();
		x = normalized.x;
		y = normalized.y;
		z = normalized.z;
		w = normalized.w;
	}

	//
	// Static Methods
	//

	float Vector4::Cross(const Vector4& leftHandSide, const Vector4& rightHandSide)
	{
		return leftHandSide.x * rightHandSide.x - leftHandSide.y * rightHandSide.y - leftHandSide.z * rightHandSide.z - leftHandSide.w * rightHandSide.w;
	}

	float Vector4::Distance(const Vector4& leftHandSide, const Vector4& rightHandSide)
	{
		return (leftHandSide - rightHandSide).Magnitude();
	}

	float Vector4::Dot(const Vector4& leftHandSide, const Vector4& rightHandSide)
	{
		return leftHandSide.x * rightHandSide.x + leftHandSide.y * rightHandSide.y + leftHandSide.z * rightHandSide.z + leftHandSide.w * rightHandSide.w;
	}

	Vector4 Vector4::Lerp(const Vector4& start, const Vector4& end, float time)
	{
		return start * (1.0f - time) + end * time;
	}

	Vector4 Vector4::Scale(const Vector4& inVector, const Vector4& scalarVector)
	{
		return Vector4(inVector.x * scalarVector.x, inVector.y * scalarVector.y, inVector.z * scalarVector.z, inVector.w * scalarVector.w);
	}

	Vector4 Vector4::Slerp(const Vector4& start, const Vector4& end, float time)
	{
		float dot = Dot(start, end);
		dot = dot < -1.f ? -1.f : (dot > 1.f ? 1.f : dot);
		float theta = acosf(dot) * time;
		return start * cosf(theta) + (end - start * dot) * sinf(theta);
	}

	std::string Vector4::ToString()
	{
		std::stringstream ss;
		ss << "(" << x << ", " << y << ", " << z << ", " << w << ")";
		return ss.str();
	}
}