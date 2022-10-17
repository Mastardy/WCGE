#pragma once

#include "WCGE/Graphics/Material.hpp"
#include "WCGE/Graphics/Texture.hpp"

#include "WCGE/Core/Math/Math.hpp"

using namespace WCGE;
using namespace Graphics;

class CircleMaterial : public Material
{
public:
	CircleMaterial();
	CircleMaterial(Shader* shader, Texture* texture);

	virtual void Use() override;

	float timer;
	Texture* texture;
};