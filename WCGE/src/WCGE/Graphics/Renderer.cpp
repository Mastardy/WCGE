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
		if(window.debugLine) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	bool Renderer::Update()
	{
		if(glfwWindowShouldClose(window->GetGLFWWindow())) return false;

		glClearColor(0.5f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		return true;
	}

	void Renderer::LateUpdate()
	{
		glfwSwapBuffers(window->GetGLFWWindow());
		glfwPollEvents();
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