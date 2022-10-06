#include "Application.hpp"

#include "Core/Logging.hpp"
#include "Core/Time.hpp"

namespace WCGE
{
	Application::Application()
	{
		log = false;
		isRunning = true;
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		if(log) WCGE::Logging::Init();
		WCGE::Time::Init();
		
		Start();

		while(isRunning)
		{
			WCGE::Time::Update();
			Update();
			LateUpdate();
		}

		if(log) WCGE::Logging::Terminate();
	}

	void Application::Start() {}

	void Application::Update() {}

	void Application::LateUpdate() {}
}