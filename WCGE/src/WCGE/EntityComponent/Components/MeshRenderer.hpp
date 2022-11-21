#pragma once

#include "../../Core.hpp"

#include "../IComponent.hpp"

#include "../../Graphics/Mesh.hpp"
#include "../../Graphics/Material.hpp"

namespace WCGE
{
	class WCGE_API MeshRenderer : public IComponent
	{
	public:
		static const std::size_t type;
		MeshRenderer(Entity* parent, Graphics::Mesh* mesh, Graphics::Material* material);

		virtual bool IsClassType(const std::size_t classType) const override;

		Graphics::Mesh* GetMesh();
		Graphics::Material* GetMaterial();

		Math::Matrix4 GetTransform();
		void SetTransform(const Math::Matrix4& transform);

		virtual void Update() override;

	private:
		Graphics::Material* material;
		Graphics::Mesh* mesh;
	};
}