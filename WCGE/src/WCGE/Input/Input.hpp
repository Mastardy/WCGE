#pragma once
#pragma warning(disable : 4251)

#include "../Core.hpp"

#include "../Core/Math/Vector2.hpp"

#include "Key.hpp"
#include "Button.hpp"

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

		static bool GetButton(Button button);
		static bool GetButtonDown(Button button);
		static bool GetButtonUp(Button button);

		static Math::Vector2 GetMousePosition();
		static Math::Vector2 GetMouseDelta();
		static Math::Vector2 GetMouseScrollDelta();

		static void MouseScrollCallBack(GLFWwindow* window, double offsetX, double offsetY);

	private: 
		static Math::Vector2 mouseDelta;
		static Math::Vector2 mousePosition;
		static Math::Vector2 mouseScrollDelta;
		static Math::Vector2 mouseScrollDeltaRaw;

		static std::array<bool, 107> keyIsPressed;
		static std::array<bool, 107> keyWasPressedThisFrame;
		static std::array<bool, 107> keyWasReleasedThisFrame;
		
		static std::array<bool, 8> buttonIsPressed;
		static std::array<bool, 8> buttonWasPressedThisFrame;
		static std::array<bool, 8> buttonWasReleasedThisFrame;

		static GLFWwindow* window;
	};
}