#pragma once
#pragma warning(disable : 4251)

#include "../Core.hpp"

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace WCGE::Graphics
{
	class WCGE_API Window
	{
	public:
		Window();		
		Window(int width, int height, std::string title);

		void CreateGLFWWindow();

		int GetWidth();
		int GetHeight();
		std::string GetTitle();
		GLFWwindow* GetGLFWWindow();

	private:
		int width;
		int height;
		std::string title;
		GLFWwindow* glfwWindow;
	};
}