#pragma once

#include <WCGE.hpp>

#include "../Mesh/CircleMesh.hpp"
#include "../Material/CircleMaterial.hpp"

using namespace WCGE;
using namespace WCGE::Graphics;

class ColorfulCircle : public Entity
{
public:
	ColorfulCircle();
	void Create();

private:
	void Update() override;

	CircleMesh circleMesh;
	CircleMaterial circleMaterial;
	float timer;
};