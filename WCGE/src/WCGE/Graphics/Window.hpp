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
		Window(int width, int height, const std::string& title, bool debugLine);

		void CreateGLFWWindow();

		int GetWidth() const;
		int GetHeight() const;
		std::string GetTitle();
		GLFWwindow* GetGLFWWindow() const;

		bool debugLine;

	private:
		int width;
		int height;
		std::string title;
		GLFWwindow* glfwWindow;
	};
}