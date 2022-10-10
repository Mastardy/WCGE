#include "Vector3UInt.hpp"

#include <sstream>
#include <stdexcept>

namespace WCGE::Math
{
	Vector3UInt::Vector3UInt() : x{ 0 }, y{ 0 }, z{ 0 } {}
	Vector3UInt::Vector3UInt(const unsigned int value) : x{ value }, y{ value }, z{ value } {}
	Vector3UInt::Vector3UInt(const unsigned int x, const unsigned int y) : x{ x }, y{ y }, z{ 0 } {}
	Vector3UInt::Vector3UInt(const unsigned int x, const unsigned int y, const unsigned int z) : x{ x }, y{ y }, z{ z } {}
	Vector3UInt::Vector3UInt(const Vector3UInt& other) : x{ other.x }, y{ other.y }, z{ other.z } {}

	Vector3UInt& Vector3UInt::operator=(const Vector3UInt& other)
	{
		*this = other;
		return *this;
	}

	unsigned int Vector3UInt::operator[](const int i) const
	{
		if(i < 0 || i > 2)
		{
			throw std::out_of_range("");
		}

		return xyz[i];
	}


	std::string Vector3UInt::ToString() const
	{
		std::stringstream ss;
		ss << "X: " << x << " Y: " << y << " Z: " << z;
		return ss.str();
	}
}