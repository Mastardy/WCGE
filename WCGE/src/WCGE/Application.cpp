#include "Application.hpp"

#include "../WCGE.hpp"

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
		
		while(isRunning)
		{
			WCGE::Time::Update();
		}

		if(log) WCGE::Logging::Terminate();
	}
}