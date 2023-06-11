#include "Transform.hpp"
#include "MeshRenderer.hpp"

#include "../../Core/Logging.hpp"

#include <iostream>

namespace WCGE
{
	const std::size_t Transform::type = std::hash<std::string>()("Transform");

	Transform::Transform(Entity* parent) : IComponent(parent) 
	{ 
		name = "Transform";

		position = Math::Vector3(0.0f, 0.0f, 0.0f);
		rotation = Math::Vector3(0.0f, 0.0f, 0.0f);
		scale = Math::Vector3(1.0f, 1.0f, 1.0f);
	}

	Transform::Transform(Entity* parent, const Math::Vector3& position, const Math::Vector3& rotation, const Math::Vector3& scale) : IComponent(parent)
	{
		name = "Transform";

		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
	}

	bool Transform::IsClassType(const std::size_t classType) const
	{
		if(classType == type)
		{
			return true;
		}
		return IComponent::IsClassType(classType);
	}

	void Transform::Update()
	{
		if(MeshRenderer *meshRenderer = &(parent->GetComponent<MeshRenderer>()))
		{
			Math::Matrix4 transform = meshRenderer->GetTransform();
			
			transform = Math::Matrix4::identity * Math::Matrix4::Translate(position) * Math::Matrix4::Rotate(rotation) * Math::Matrix4::Scale(scale);

			meshRenderer->SetTransform(transform);
		}
	}

	void Transform::Translate(float xTranslation, float yTranslation, float zTranslation)
	{
		position.x += xTranslation;
		position.y += yTranslation;
		position.z += zTranslation;
	}

	void Transform::Translate(const Math::Vector3& translation)
	{
		position += translation;
	}

	void Transform::Rotate(float xRotation, float yRotation, float zRotation)
	{
		rotation.x += xRotation;
		rotation.y += yRotation;
		rotation.z += zRotation;
	}

	void Transform::Rotate(const Math::Vector3& rotation)
	{
		this->rotation += rotation;
	}

	void Transform::Scale(float scalar)
	{
		scale *= scalar;
	}

	void Transform::Scale(float xScalar, float yScalar, float zScalar)
	{
		scale.x *= xScalar;
		scale.y *= yScalar;
		scale.z *= zScalar;
	}

	void Transform::Scale(const Math::Vector3& scalar)
	{
		scale *= scalar;
	}
}