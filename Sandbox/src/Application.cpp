#include <WCGE.hpp>

#include <glad/glad.h>

using namespace WCGE;
using namespace Math;
using namespace Graphics;

class Sandbox final : public Application
{
public:
	std::map<int, char> numbers{};

	Triangle object;
	//Square object;
	Shader baseShader;

	Sandbox() : Application()
	{
		log = true;
		window = new Window(500, 500, "Test");
	}

	void Start() override
	{
		baseShader.Create("./Shaders/baseShader.vert", "./Shaders/baseShader.frag");
		object.Create();
	}

	void Update() override
	{
		baseShader.Use();
		baseShader.SetFloat("brightness", ((Cos(Time::GetTime() * 5) + 1.0f) / 4.0f) + 0.5f);
		object.Draw();
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