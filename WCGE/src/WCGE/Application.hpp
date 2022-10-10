#pragma once

#include "Core.hpp"
#include "Graphics/Window.hpp"

namespace WCGE
{
	class WCGE_API Application
	{
	public:
		bool isRunning;
		bool log;
		Graphics::Window* window;

		Application();
		virtual ~Application();

		virtual void Run();

		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
	};

	Application* CreateApplication();
}