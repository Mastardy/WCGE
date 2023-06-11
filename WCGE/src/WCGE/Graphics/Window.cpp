#include "Window.hpp"

#include <string>
#include <stdexcept>

namespace WCGE::Graphics
{
	Window::Window() : debugLine{false}, width{800}, height{600}, title{"Application"}, glfwWindow{nullptr} {}

	Window::Window(int width, int height, const std::string& title, bool debugLine) : debugLine{debugLine}, width{width}, height{height}, title{title}, glfwWindow{nullptr} {}
	
	void Window::CreateGLFWWindow()
	{
		GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		glfwWindow = window;
		if(glfwWindow == nullptr)
		{
			glfwTerminate();
			throw std::runtime_error("GLFW window could not be created!");
		}
	}

	int Window::GetWidth() const
	{
		return width;
	}
	
	int Window::GetHeight() const
	{
		return height;
	}
	
	std::string Window::GetTitle()
	{
		return title;
	}

	GLFWwindow* Window::GetGLFWWindow() const
	{
		return glfwWindow;
	}
}