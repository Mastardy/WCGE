#pragma once

#include <WCGE.hpp>

using namespace WCGE;
using namespace WCGE::Graphics;

class ColorfulCircle : public Entity
{
public:
	ColorfulCircle();
	void Create();

private:
	void Update() override;
	Circle circle;
	Shader shader;
	Texture texture;
};