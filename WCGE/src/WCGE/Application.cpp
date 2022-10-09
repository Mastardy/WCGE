#include "Application.hpp"

#include "Core/Logging.hpp"
#include "Core/Time.hpp"

#include "Graphics/Renderer.hpp"

#include "Input/Input.hpp"

using namespace WCGE::Graphics;

namespace WCGE
{
	Application::Application() : window{nullptr}
	{
		log = false;
		isRunning = true;
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		if(log) Logging::Init();
		Time::Init();
		Renderer::Init(*window);
		Input::Init(window->GetGLFWWindow());
		
		Start();

		while(isRunning)
		{
			Time::Update();
			Input::Update();
			Update();
			LateUpdate();
			if(!Renderer::Update()) isRunning = false;
			Input::LateUpdate();
		}

		Renderer::Close();
		Input::Close();
		if(log) Logging::Close();
	}

	void Application::Start() {}

	void Application::Update() {}

	void Application::LateUpdate() {}
}