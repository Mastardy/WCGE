#include "Application.hpp"

#include "Core/Logging.hpp"
#include "Core/Time.hpp"

#include "Graphics/Renderer.hpp"

#include "Input/Input.hpp"

#include "EntityComponent/Entity.hpp"

using namespace WCGE::Graphics;

namespace WCGE
{
	Application::Application() : window{nullptr}
	{
		log = false;
		isRunning = true;
	}

	Application::~Application() = default;

	void Application::Run()
	{
		if(log) Logging::Init();
		Time::Init();
		Renderer::Init(*window);
		Input::Init(window->GetGLFWWindow());
		
		Start();

		while(isRunning)
		{
			if(!Renderer::Update()) isRunning = false;
			Time::Update();
			Input::Update();
			Entity::UpdateAll();
			Update();
			LateUpdate();
			Input::LateUpdate();
			Renderer::LateUpdate();
		}

		Renderer::Close();
		Input::Close();
	}

	void Application::Start() {}

	void Application::Update() {}

	void Application::LateUpdate() {}
}