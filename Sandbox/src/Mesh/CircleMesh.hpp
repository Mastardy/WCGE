#pragma once

#include "WCGE/Graphics/Mesh.hpp"
#include "WCGE/Core/Logging.hpp"

using namespace WCGE::Graphics;

class CircleMesh : public Mesh
{
public:
	CircleMesh();
	CircleMesh(int nSides);
	virtual void GenerateMesh() override;
	virtual void Draw() override;

private:
	int nSides;
};