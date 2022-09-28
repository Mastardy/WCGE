#pragma once

#ifdef WCGE_PLATFORM_WINDOWS
#include "Application.h"

extern WCGE::Application* WCGE::CreateApplication();

int main(int argc, char** argv)
{
	auto app = WCGE::CreateApplication();
	app->Run();
	delete app;
}

#endif


abcdefg
abcdefg
abcdefg
abcdefg
abcdefg
abcdefg