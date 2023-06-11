#pragma once

#include "../Core.hpp"
#include "../Core/Math/Math.hpp"

namespace WCGE::Graphics
{
	class WCGE_API Mesh
	{
	public:
		Mesh();
		void Create();
		virtual void GenerateMesh();
		virtual void Draw();

	protected:
		struct Vertex
		{
			Vertex() = default;
			Vertex(const Math::Vector3& vertices, const Math::Vector2& texCoords)
			{
				this->vertices = vertices;
				this->texCoords = texCoords;
			}

			Math::Vector3 vertices;
			Math::Vector2 texCoords;
		};

		std::vector<Vertex> vertices;
		std::vector<Math::Vector3UInt> indices;

		unsigned int VBO;
		unsigned int EBO;
		unsigned int VAO;
	};
}