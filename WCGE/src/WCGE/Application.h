#pragma once

#include "Core.h"

namespace WCGE
{
	class WCGE_API Application
	{
	public:
		bool isRunning;

		Application();
		~Application();

		virtual void Run();
	};

	Application* CreateApplication();
}