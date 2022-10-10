#pragma once

#include "../Core.hpp"
#include "../Core/Math/Math.hpp"

namespace WCGE {
	class WCGE_API Square
	{
	public:
		Square();
		void Create();
		void Draw() const;
	private:
		std::array<Math::Vector3, 4> vertices;
		std::array<Math::Vector3UInt, 2> indices;

		unsigned int vertexArrayObject;
		unsigned int vertexBufferObject;
		unsigned int elementBufferObject;
	};
}