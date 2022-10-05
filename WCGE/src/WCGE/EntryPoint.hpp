#pragma once

#include <Windows.h>

#ifdef WCGE_PLATFORM_WINDOWS

extern WCGE::Application* WCGE::CreateApplication();

int main(int argc, char** argv)
{
	auto app = WCGE::CreateApplication();
	bool beingLogged = app->log;
	if(beingLogged) WCGE::Logging::Init();
	WCGE::Time::Init();

	while(app->isRunning)
	{
		WCGE::Time::Update();
		app->Run();
	}
	
	if(beingLogged) WCGE::Logging::Terminate();
	delete app;
}

#endif