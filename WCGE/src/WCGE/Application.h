#pragma once

#include "Core.h"

namespace WCGE
{
	class WCGE_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	Application* CreateApplication();
}