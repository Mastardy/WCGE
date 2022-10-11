#pragma once

#include "../Core.hpp"
#include "../Core/Math/Math.hpp"

namespace WCGE
{
	class WCGE_API Circle
	{
	private:
		struct Vertex
		{
			Math::Vector3 vertices;
			Math::Vector2 texCoords;
		};

	public:
		Circle();
		void Create(int nSides);
		void Draw() const;
		std::vector<Vertex> vertices;
		std::vector<Math::Vector3UInt> indices;


	private:
		unsigned int vertexBufferObject;
		unsigned int elementBufferObject;
		unsigned int vertexArrayObject;
	};
}