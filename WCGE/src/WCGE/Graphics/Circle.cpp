#include "Circle.hpp"

#include "../Core/Logging.hpp"

#include <glad/glad.h>

namespace WCGE
{
	Circle::Circle() : vertexBufferObject{0}, elementBufferObject{0}, vertexArrayObject{0} {}

	void Circle::Create(int nSides)
	{
		if(nSides < 3) Logging::Error("A circle must have more than 3 sides!");

		float piece = (360.0f / nSides) * (Math::PI / 180.0f);
		float radius = 0.5f;

		for(int i = 0; i < nSides; i++)
		{
			Vertex vertex;
			vertex.vertices = Math::Vector3(Math::Cos(piece * i) * radius, Math::Sin(piece * i) * radius, 0.0f);
			vertex.texCoords = Math::Vector2((Math::Cos(piece * i) + 1.0f) / 2.0f, (Math::Sin(piece * i) + 1.0f) / 2.0f);
			vertices.push_back(vertex);
		}

		for(int i = 0; i < nSides - 2; i++)
		{
			indices.push_back(Math::Vector3UInt(0, i + 1, i + 2));
		}

		glGenVertexArrays(1, &vertexArrayObject);
		glGenBuffers(1, &vertexBufferObject);
		glGenBuffers(1, &elementBufferObject);

		glBindVertexArray(vertexArrayObject);

		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(Math::Vector3UInt), &indices[0], GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(sizeof(Vertex::vertices)));
		glEnableVertexAttribArray(1);
	}

	void Circle::Draw() const
	{
		glBindVertexArray(vertexArrayObject);
		glDrawElements(GL_TRIANGLES, indices.size() * 3, GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}
}