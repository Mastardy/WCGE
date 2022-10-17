#include "CircleMesh.hpp"

using namespace WCGE;

CircleMesh::CircleMesh() : Mesh()
{
	nSides = 0;
}

CircleMesh::CircleMesh(int nSides)
{
	this->nSides = nSides;
}

void CircleMesh::GenerateMesh()
{
	if (nSides < 3) Logging::Error("A circle must have more than 3 sides!");

	float piece = (360.0f / nSides) * (Math::PI / 180.0f);
	float radius = 0.75f;

	for (int i = 0; i < nSides; i++)
	{
		Mesh::Vertex vertex;
		vertex.vertices = Math::Vector3(Math::Cos(piece * i) * radius, Math::Sin(piece * i) * radius, 0.0f);
		vertex.texCoords = Math::Vector2((Math::Cos(piece * i) + 1.0f) / 2.0f, (Math::Sin(piece * i) + 1.0f) / 2.0f);
		vertices.push_back(vertex);
	}

	for (int i = 0; i < nSides - 2; i++)
	{
		indices.push_back(Math::Vector3UInt(0, i + 1, i + 2));
	}
}

void CircleMesh::Draw()
{
	Mesh::Draw();
}