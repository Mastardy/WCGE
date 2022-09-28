#pragma once

#include "Core.h"

namespace WCGE
{
	class WCGE_API Application
	{
	public:
		Application();
		~Application();

		virtual void Run();
	};

	Application* CreateApplication();
}