#include "Material.hpp"

#include "../Core/Logging.hpp"

namespace WCGE::Graphics
{
	Material::Material(Shader* shader)
	{
		this->shader = shader;
		transform = Math::Matrix4::identity;
	}

	Math::Matrix4 Material::GetTransform()
	{
		return transform;
	}

	void Material::SetTransform(const Math::Matrix4& transform)
	{
		this->transform = transform;
	}

	Shader* Material::GetShader()
	{
		return shader;
	}

	void Material::Use()
	{
		shader->Use();
	}
}