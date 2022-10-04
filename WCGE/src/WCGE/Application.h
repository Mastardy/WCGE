#pragma once

#include "Core.h"

namespace WCGE
{
	class WCGE_API Application
	{
	public:
		bool isRunning;
		bool log;

		Application();
		~Application();

		virtual void Run();
	};

	Application* CreateApplication();
}