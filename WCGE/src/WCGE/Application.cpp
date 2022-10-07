#include "Application.hpp"

#include "Core/Logging.hpp"
#include "Core/Time.hpp"

#include "Graphics/Renderer.hpp"

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
		
		Start();

		while(isRunning)
		{
			Time::Update();
			Update();
			LateUpdate();
			if(!Renderer::Update()) isRunning = false;
		}

		Renderer::Close();
		if(log) Logging::Close();
	}

	void Application::Start() {}

	void Application::Update() {}

	void Application::LateUpdate() {}
}