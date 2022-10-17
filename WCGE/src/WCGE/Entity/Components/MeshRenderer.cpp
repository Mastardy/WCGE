#include "MeshRenderer.hpp"

#include "../../Core/Logging.hpp"

namespace WCGE
{
	const std::size_t MeshRenderer::type = std::hash<std::string>()("MeshRenderer");

	MeshRenderer::MeshRenderer(Entity* parent, Graphics::Mesh* mesh, Graphics::Material* material) : IComponent(parent)
	{
		name = "MeshRenderer";

		this->mesh = mesh;
		mesh->Create();
		this->material = material;
	}

	bool MeshRenderer::IsClassType(const std::size_t classType) const
	{
		if (classType == type)
		{
			return true;
		}
		return IComponent::IsClassType(classType);
	}

	Graphics::Mesh* MeshRenderer::GetMesh()
	{
		return mesh;
	}

	Graphics::Material* MeshRenderer::GetMaterial()
	{
		return material;
	}

	Math::Matrix4 MeshRenderer::GetTransform()
	{
		return material->GetTransform();
	}

	void MeshRenderer::SetTransform(const Math::Matrix4& transform)
	{
		material->SetTransform(transform);
	}

	void MeshRenderer::Update()
	{
		material->Use();
		mesh->Draw();
	}
}