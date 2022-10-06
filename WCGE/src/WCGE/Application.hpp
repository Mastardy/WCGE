#pragma once

#include "Core.hpp"

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

		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
	};

	Application* CreateApplication();
}