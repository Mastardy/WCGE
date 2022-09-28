#pragma once

#ifdef WCGE_PLATFORM_WINDOWS

extern WCGE::Application* WCGE::CreateApplication();

int main(int argc, char** argv)
{
	auto app = WCGE::CreateApplication();
	WCGE::Logging::Init();
	app->Run();
	WCGE::Logging::Terminate();
	delete app;
}

#endif