#pragma once

#include <Windows.h>

#ifdef WCGE_PLATFORM_WINDOWS

extern WCGE::Application* WCGE::CreateApplication();

int main(int argc, char** argv)
{
	auto app = WCGE::CreateApplication();
	WCGE::Logging::Init();
	WCGE::Time::Init();

	while(app->isRunning)
	{
		WCGE::Time::CalculateDeltaTime();
		WCGE::Time::CalculateTime();
		app->Run();
	}
	
	WCGE::Logging::Terminate();
	delete app;
}

#endif