#pragma once

#include "../../Core.hpp"

#include <array>
#include <string>

namespace WCGE::Math
{
	class WCGE_API Vector3UInt
	{
	public:
		union
		{
			struct
			{
				unsigned int x;
				unsigned int y;
				unsigned int z;
			};
			std::array<unsigned int, 3> xyz;
		};

		Vector3UInt();
		Vector3UInt(const unsigned int value);
		Vector3UInt(const unsigned int x, const unsigned int y);
		Vector3UInt(const unsigned int x, const unsigned int y, const unsigned int z);
		Vector3UInt(const Vector3UInt& other);

		Vector3UInt& operator=(const Vector3UInt& other);
		unsigned int operator[](const int i) const;

		std::string ToString() const;
	};
}