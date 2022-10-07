#include "Renderer.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

namespace WCGE::Graphics
{
	Window* Renderer::window;

	void Renderer::Init(Window& window)
	{
		Renderer::window = &window;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window.CreateGLFWWindow();

		glfwMakeContextCurrent(window.GetGLFWWindow());

		glfwSetFramebufferSizeCallback(window.GetGLFWWindow(), FramebufferSizeCallback);

		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			throw std::runtime_error("Failed to initialize GLAD!");
		}
		
		glViewport(0, 0, window.GetWidth(), window.GetHeight());
	}

	bool Renderer::Update()
	{
		GLFWwindow* window = Renderer::window->GetGLFWWindow();

		if(glfwWindowShouldClose(window)) return false;

		glfwSwapBuffers(window);
		glfwPollEvents();

		return true;
	}

	void Renderer::Close()
	{
		glfwTerminate();
	}

	void Renderer::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}