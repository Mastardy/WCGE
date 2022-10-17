#include <WCGE.hpp>
#include <WCGE/EntryPoint.hpp>

#include "Entities/ColorfulCircle.hpp"

#include <glad/glad.h>

using namespace WCGE;
using namespace Math;
using namespace Graphics;

class Sandbox final : public Application
{
public:
	std::map<int, char> numbers{};

	ColorfulCircle colorfulSmile;

	Sandbox() : Application()
	{
		log = true;
		window = new Window(500, 500, "Test", false);
	}

	void Start() override
	{
		colorfulSmile.Create();
	}

	void Update() override
	{
		Math::Vector2 movement;

		if (Input::GetKey(Key::W))
		{
			movement.y += 1.0f;
		}
		else if (Input::GetKey(Key::S))
		{
			movement.y += -1.0f;
		}

		if (Input::GetKey(Key::A))
		{
			movement.x += -1.0f;
		}
		else if (Input::GetKey(Key::D))
		{
			movement.x += 1.0f;
		}

		movement = movement.Normalized() * Time::GetDeltaTime();
		colorfulSmile.GetComponent<Transform>().Translate(movement);
	}

	void LateUpdate() override
	{
		if(Input::GetKey(Key::Escape)) isRunning = false;
	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}