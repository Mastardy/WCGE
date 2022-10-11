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