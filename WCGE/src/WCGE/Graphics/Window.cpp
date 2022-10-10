#include "Window.hpp"

#include <string>
#include <stdexcept>

namespace WCGE::Graphics
{
	Window::Window() : width{800}, height{600}, title{"Application"}, glfwWindow{nullptr}, debugLine{false} {}

	Window::Window(int width, int height, std::string title, bool debugLine) : width{width}, height{height}, title{title}, glfwWindow{nullptr}, debugLine{debugLine} {}
	
	void Window::CreateGLFWWindow()
	{
		GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		glfwWindow = window;
		if(glfwWindow == NULL)
		{
			glfwTerminate();
			throw std::runtime_error("GLFW window could not be created!");
		}
	}

	int Window::GetWidth()
	{
		return width;
	}
	
	int Window::GetHeight()
	{
		return height;
	}
	
	std::string Window::GetTitle()
	{
		return title;
	}

	GLFWwindow* Window::GetGLFWWindow()
	{
		return glfwWindow;
	}
}