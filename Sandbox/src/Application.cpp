#include <WCGE.hpp>

#include <glad/glad.h>

using namespace WCGE;
using namespace Math;
using namespace Graphics;

class Sandbox final : public Application
{
public:
	std::map<int, char> numbers{};

	Circle entity;
	//Triangle entity;
	//Square entity;
	//Shader baseShader;
	Shader circleShader;

	float time = 0.0f;

	Sandbox() : Application()
	{
		log = true;
		window = new Window(500, 500, "Test", false);
	}

	void Start() override
	{
		//baseShader.Create("./Shaders/baseShader.vert", "./Shaders/baseShader.frag");
		circleShader.Create("./Shaders/circle.vert", "./Shaders/circle.frag");
		entity.Create(65);
	}

	void Update() override
	{
		//baseShader.Use();
		time += Time::GetDeltaTime() / 2;
		if(time > 2.0f) time = 0.0f;

		circleShader.Use();
		circleShader.SetFloat("time", time);
		entity.Draw();
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