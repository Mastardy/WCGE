#pragma once
#pragma warning(disable : 4251)

#include "../Core.hpp"

#include "Key.hpp"

#include <array>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace WCGE
{
	class WCGE_API Input
	{
	public:
		static void Init(GLFWwindow* window);
		static void Update();
		static void Close();

		static bool GetKey(Key key);
		static bool GetKeyDown(Key key);
		static bool GetKeyUp(Key key);

	private: 
		static std::array<bool, 107> wasPressedThisFrame;
		static std::array<bool, 107> wasReleasedThisFrame;
		static std::array<bool, 107> isPressed;
		static GLFWwindow* window;
	};
}