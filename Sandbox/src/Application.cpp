#include <WCGE.hpp>
#include <WCGE/EntryPoint.hpp>

#include "Entities/ColorfulCircle.hpp"

#include "Entities/BasicCamera.h"

#include <glad/glad.h>

using namespace WCGE;
using namespace Math;
using namespace Graphics;

class Sandbox final : public Application
{
public:
	ColorfulCircle* colorfulSmile;
	BasicCamera* camera;

	Sandbox() : Application()
	{
		log = true;
		window = new Window(960, 540, "Test", false);
		camera = new BasicCamera();
		colorfulSmile = new ColorfulCircle();
	}

	void Start() override
	{
		colorfulSmile->Create();
		colorfulSmile->GetComponent<Transform>().Translate(0, 0, 1);
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