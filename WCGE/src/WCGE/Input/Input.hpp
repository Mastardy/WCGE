#pragma once
#pragma warning(disable : 4251)

#include "../Core.hpp"

#include "../Core/Math/Vector2.hpp"

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
		static void LateUpdate();
		static void Close();

		static bool GetKey(Key key);
		static bool GetKeyDown(Key key);
		static bool GetKeyUp(Key key);

		static Math::Vector2 GetMousePosition();
		static Math::Vector2 GetMouseDelta();
		static Math::Vector2 GetMouseScrollDelta();

		static void MouseScrollCallBack(GLFWwindow* window, double offsetX, double offsetY);

	private: 
		static Math::Vector2 mousePosition;
		static Math::Vector2 mouseDelta;
		static Math::Vector2 mouseScrollDeltaRaw;
		static Math::Vector2 mouseScrollDelta;

		static std::array<bool, 107> wasPressedThisFrame;
		static std::array<bool, 107> wasReleasedThisFrame;
		static std::array<bool, 107> isPressed;
		static GLFWwindow* window;
	};
}