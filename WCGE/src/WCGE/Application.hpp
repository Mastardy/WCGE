#pragma once

#include "Core.hpp"
#include "Graphics/Window.hpp"
#include <GLFW/glfw3.h>

#include <string>

namespace WCGE
{
	class WCGE_API Application
	{
	public:
		bool isRunning;
		bool log;
		Graphics::Window* window;

		Application();
		~Application();

		virtual void Run();

		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
	};

	Application* CreateApplication();
}