#pragma once

#include "../Core.hpp"

#include "Window.hpp"

namespace WCGE::Graphics
{
	class WCGE_API Renderer
	{
	public:
		static void Init(Window& window);
		static bool Update();
		static void Close();

		static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
	private:
		static Window* window;
	};
}