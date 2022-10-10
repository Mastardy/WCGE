#include <WCGE.hpp>

using namespace WCGE;
using namespace Math;
using namespace Graphics;

class Sandbox final : public Application
{
public:
	std::map<int, char> numbers{};

	Triangle triangle;
	Shader baseShader;

	Sandbox() : Application()
	{
		log = true;
		window = new Window(500, 500, "Test");
	}

	void Start() override
	{
		baseShader.Create("./Shaders/baseShader.vert", "./Shaders/baseShader.frag");
		triangle.Create();
	}

	void Update() override
	{
		baseShader.Use();
		triangle.Draw();
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