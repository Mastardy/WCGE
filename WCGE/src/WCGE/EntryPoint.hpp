#pragma once

#include <Windows.h>

#ifdef WCGE_PLATFORM_WINDOWS

extern WCGE::Application* WCGE::CreateApplication();

int main(int argc, char** argv)
{
	auto app = WCGE::CreateApplication();
	app->Run();
	delete app;
}

#endif