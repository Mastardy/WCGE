#pragma once

#include "../Core.hpp"

#include "Shader.hpp"

namespace WCGE::Graphics
{
	class WCGE_API Material
	{
	public:
		Material() : transform{}, shader{nullptr} {}
		Material(Shader* shader);
		Shader* GetShader() const;
		virtual void Use();
		Math::Matrix4 GetTransform();
		void SetTransform(const Math::Matrix4& transform);

	protected:
		Math::Matrix4 transform;
		Shader* shader;
	};
}