#include "Mesh.hpp"

#include "../Core/Logging.hpp"

#include <glad/glad.h>

namespace WCGE::Graphics
{
	Mesh::Mesh()
	{
		VBO = 0;
		EBO = 0;
		VAO = 0;

		vertices = {};
		indices = {};
	}

	void Mesh::Create()
	{
		GenerateMesh();

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(Math::Vector3UInt), &indices[0], GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vertex::vertices)));
		glEnableVertexAttribArray(1);
	}

	void Mesh::GenerateMesh()
	{
		vertices =
		{
			Vertex(Math::Vector3(0.0f, 0.5f, 0.0f), Math::Vector2(0.5f, 1.0f)),
			Vertex(Math::Vector3(-0.5f, -0.5f, 0.0f), Math::Vector2(0.0f, 0.0f)),
			Vertex(Math::Vector3(0.5f, -0.5f, 0.0f), Math::Vector2(1.0f, 0.0f))
		};

		indices =
		{
			Math::Vector3UInt(0, 1, 2)
		};
	}

	void Mesh::Draw()
	{
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, indices.size() * 3, GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}
}