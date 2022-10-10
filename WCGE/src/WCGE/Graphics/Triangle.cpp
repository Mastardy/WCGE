#include "Triangle.hpp"

#include <glad/glad.h>

namespace WCGE
{
	Triangle::Triangle()
	{
		vertexArrayObject = 0;
		vertexBufferObject = 0;
	}

	void Triangle::Create()
	{
		vertices[0] = Vertex{{Math::Vector3(-0.5f, -0.5f, 0.0f)}, {Math::Vector3(1.0f, 0.0f, 0.0f)}};
		vertices[1] = Vertex{{Math::Vector3(0.5f, -0.5f, 0.0f)}, {Math::Vector3(0.0f, 1.0f, 0.0f)}};
		vertices[2] = Vertex{{Math::Vector3(0.0f, 0.5f, 0.0f)}, {Math::Vector3(0.0f, 0.0f, 1.0f)}};

		glGenVertexArrays(1, &vertexArrayObject);
		glGenBuffers(1, &vertexBufferObject);

		glBindVertexArray(vertexArrayObject);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)sizeof(Math::Vector3));
		glEnableVertexAttribArray(1);
	}

	void Triangle::Draw() const
	{
		glBindVertexArray(vertexArrayObject);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
	}
}