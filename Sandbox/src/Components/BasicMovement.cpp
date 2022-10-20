#include "BasicMovement.hpp"

#include "WCGE/Core/Logging.hpp"

const std::size_t BasicMovement::type = std::hash<std::string>()("BasicMovement");

bool BasicMovement::IsClassType(const std::size_t classType) const
{
	if (classType == type)
	{
		return true;
	}
	return IComponent::IsClassType(classType);
}

BasicMovement::BasicMovement(Entity* parent) : IComponent(parent)
{
	name = "BasicMovement";

	this->parent = parent;
}

void BasicMovement::Update()
{
	Math::Vector2 movement;
	Math::Vector3 rotation;
	float scale = 0.0f;

	if (Input::GetKey(Key::W))
	{
		movement.y = 1.0f;
	}
	else if (Input::GetKey(Key::S))
	{
		movement.y = -1.0f;
	}

	if (Input::GetKey(Key::A))
	{
		movement.x = -1.0f;
	}
	else if (Input::GetKey(Key::D))
	{
		movement.x = 1.0f;
	}

	if (Input::GetKey(Key::Up))
	{
		rotation.x = 1.0f;
	}
	else if (Input::GetKey(Key::Down))
	{
		rotation.x = -1.0f;
	}

	if (Input::GetKey(Key::Left))
	{
		rotation.z = -1.0f;
	}
	else if (Input::GetKey(Key::Right))
	{
		rotation.z = 1.0f;
	}

	if (Input::GetKey(Key::LShift))
	{
		scale = 0.5f;
	}
	else if (Input::GetKey(Key::LCtrl))
	{
		scale = -0.5f;
	}

	movement.Normalize();
	
	Transform* transform = &parent->GetComponent<Transform>();
	
	transform->Translate(movement * Time::GetDeltaTime());
	transform->Rotate(rotation * Time::GetDeltaTime());
	transform->Scale(1.0f + (scale * Time::GetDeltaTime()));
}
