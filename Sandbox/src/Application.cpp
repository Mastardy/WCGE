#include <WCGE.hpp>
#include <iostream>

using namespace WCGE;
using namespace WCGE::Math;
using namespace WCGE::Graphics;

class Sandbox : public Application
{
public:
	std::map<int, char> numbers{};

	Sandbox() : Application()
	{
		window = new Window(500, 500, "Test");
	}

	~Sandbox() {}

	void Start()
	{

	}

	void Update()
	{
		if(Input::GetKey(Key::Escape)) isRunning = false;
	}

	void LateUpdate()
	{
	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}