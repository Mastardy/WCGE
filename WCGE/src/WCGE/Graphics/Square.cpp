#include "Square.hpp"

#include <glad/glad.h>

namespace WCGE
{
	Square::Square()
	{
		vertexArrayObject = 0;
		vertexBufferObject = 0;
		elementBufferObject = 0;
	}

	void Square::Create()
	{
		vertices[0] = Math::Vector3(-0.5f, 0.5f);
		vertices[1] = Math::Vector3(0.5f, 0.5f);
		vertices[2] = Math::Vector3(-0.5f, -0.5f);
		vertices[3] = Math::Vector3(0.5f, -0.5f);

		indices[0] = Math::Vector3UInt(0, 1, 2);
		indices[1] = Math::Vector3UInt(2, 3, 1);

		glGenVertexArrays(1, &vertexArrayObject);
		glGenBuffers(1, &vertexBufferObject);
		glGenBuffers(1, &elementBufferObject);

		glBindVertexArray(vertexArrayObject);

		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glEnableVertexAttribArray(0);
	}

	void Square::Draw() const
	{
		glBindVertexArray(vertexArrayObject);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT , nullptr);
		glBindVertexArray(0);
	}
}