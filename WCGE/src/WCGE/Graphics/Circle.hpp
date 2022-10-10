#pragma once

#include "../Core.hpp"
#include "../Core/Math/Math.hpp"

namespace WCGE
{
	class WCGE_API Circle
	{
	public:
		Circle();
		void Create(int nSides);
		void Draw() const;
		std::vector<Math::Vector3> vertices;
		std::vector<Math::Vector3UInt> indices;
	private:

		unsigned int vertexBufferObject;
		unsigned int elementBufferObject;
		unsigned int vertexArrayObject;
	};
}