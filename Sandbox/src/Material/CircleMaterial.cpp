#include "CircleMaterial.hpp"

#include "WCGE/Core/Logging.hpp"

CircleMaterial::CircleMaterial() : Material()
{
	timer = 0.0f;
	transform = Math::Matrix4::identity;
}

CircleMaterial::CircleMaterial(Shader* shader, Texture* texture)
{
	this->shader = shader;
	this->texture = texture;

	transform = Math::Matrix4::identity;
	timer = 0.0f;
}

void CircleMaterial::Use()
{
	texture->Bind();
	shader->Use();
	shader->SetFloat("timer", timer);
	shader->SetMatrix4x4("transform", transform);
}