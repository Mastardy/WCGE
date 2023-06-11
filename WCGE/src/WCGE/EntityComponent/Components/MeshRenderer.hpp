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

		Graphics::Mesh* GetMesh() const;
		Graphics::Material* GetMaterial() const;

		Math::Matrix4 GetTransform() const;
		void SetTransform(const Math::Matrix4& transform) const;

		virtual void Update() override;

	private:
		Graphics::Material* material;
		Graphics::Mesh* mesh;
	};
}