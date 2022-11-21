#include "CircleMaterial.hpp"

#include "WCGE/Core/Logging.hpp"
#include "WCGE/EntityComponent/Entities/Cameras/Camera.hpp"

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

	if (WCGE::Camera::Current())
	{
		shader->SetMatrix4x4("mvp", Camera::Current()->GetProjectionMatrix() * Camera::Current()->GetViewMatrix() * transform);
	}
	else
	{
		shader->SetMatrix4x4("mvp", transform);
	}
}