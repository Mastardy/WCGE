#include "Input.hpp"

#include <map>

namespace WCGE
{
	GLFWwindow* Input::window;
	
	Math::Vector2 Input::mousePosition;
	Math::Vector2 Input::mouseDelta;
	Math::Vector2 Input::mouseScrollDelta = Math::Vector2::zero;
	Math::Vector2 Input::mouseScrollDeltaRaw = Math::Vector2::zero;

	std::array<bool, 107> Input::wasPressedThisFrame {false};
	std::array<bool, 107> Input::wasReleasedThisFrame {false};
	std::array<bool, 107> Input::isPressed {false};

	std::array<Key, 107> keys {};

	void Input::Init(GLFWwindow* window)
	{
		glfwSetScrollCallback(window, MouseScrollCallBack);

		Input::window = window;
		keys[0] = Key::Space;
		keys[1] = Key::Apostrophe;
		keys[2] = Key::Comma;
		keys[3] = Key::Minus;
		keys[4] = Key::Period;
		keys[5] = Key::Slash;
		keys[6] = Key::A0;
		keys[7] = Key::A1;
		keys[8] = Key::A2;
		keys[9] = Key::A3;
		keys[10] = Key::A4;
		keys[11] = Key::A5;
		keys[12] = Key::A6;
		keys[13] = Key::A7;
		keys[14] = Key::A8;
		keys[15] = Key::A9;
		keys[16] = Key::Semicolon;
		keys[17] = Key::Equal;
		keys[18] = Key::A;
		keys[19] = Key::B;
		keys[20] = Key::C;
		keys[21] = Key::D;
		keys[22] = Key::E;
		keys[23] = Key::F;
		keys[24] = Key::G;
		keys[25] = Key::H;
		keys[26] = Key::I;
		keys[27] = Key::J;
		keys[28] = Key::K;
		keys[29] = Key::L;
		keys[30] = Key::M;
		keys[31] = Key::N;
		keys[32] = Key::O;
		keys[33] = Key::P;
		keys[34] = Key::Q;
		keys[35] = Key::R;
		keys[36] = Key::S;
		keys[37] = Key::T;
		keys[38] = Key::U;
		keys[39] = Key::V;
		keys[40] = Key::W;
		keys[41] = Key::X;
		keys[42] = Key::Y;
		keys[43] = Key::Z;
		keys[44] = Key::LBracket;
		keys[45] = Key::Backslash;
		keys[46] = Key::RBracket;
		keys[47] = Key::GraveAccent;
		keys[48] = Key::World1;
		keys[49] = Key::World2;
		keys[50] = Key::Escape;
		keys[51] = Key::Enter;
		keys[52] = Key::Tab;
		keys[53] = Key::Backspace;
		keys[54] = Key::Insert;
		keys[55] = Key::Delete;
		keys[56] = Key::Right;
		keys[57] = Key::Left;
		keys[58] = Key::Down;
		keys[59] = Key::Up;
		keys[60] = Key::PageUp;
		keys[61] = Key::PageDown;
		keys[62] = Key::Home;
		keys[63] = Key::End;
		keys[64] = Key::CapsLock;
		keys[65] = Key::ScrollLock;
		keys[66] = Key::NumLock;
		keys[67] = Key::PrintScreen;
		keys[68] = Key::Pause;
		keys[69] = Key::F1;
		keys[70] = Key::F2;
		keys[71] = Key::F3;
		keys[72] = Key::F4;
		keys[73] = Key::F5;
		keys[74] = Key::F6;
		keys[75] = Key::F7;
		keys[76] = Key::F8;
		keys[77] = Key::F9;
		keys[78] = Key::F10;
		keys[79] = Key::F11;
		keys[80] = Key::F12;
		keys[81] = Key::KP0;
		keys[82] = Key::KP1;
		keys[83] = Key::KP2;
		keys[84] = Key::KP3;
		keys[85] = Key::KP4;
		keys[86] = Key::KP5;
		keys[87] = Key::KP6;
		keys[88] = Key::KP7;
		keys[89] = Key::KP8;
		keys[90] = Key::KP9;
		keys[91] = Key::KPDecimal;
		keys[92] = Key::KPDivide;
		keys[93] = Key::KPMultiply;
		keys[94] = Key::KPSubtract;
		keys[95] = Key::KPAdd;
		keys[96] = Key::KPEnter;
		keys[97] = Key::KPEqual;
		keys[98] = Key::LShift;
		keys[99] = Key::LCtrl;
		keys[100] = Key::LAlt;
		keys[101] = Key::LSuper;
		keys[102] = Key::RShift;
		keys[103] = Key::RCtrl;
		keys[104] = Key::RAlt;
		keys[105] = Key::RSuper;
		keys[106] = Key::Menu;
	}

	void Input::Update()
	{
		if(mouseScrollDeltaRaw != Math::Vector2::zero)
		{
			mouseScrollDelta = mouseScrollDeltaRaw;
			mouseScrollDeltaRaw = Math::Vector2::zero;
		}

		std::array<bool, 107> wasPressedLastFrame = isPressed;

		for(int i = 0; i < 107; i++)
		{
			isPressed[i] = glfwGetKey(window, keys[i].GetGLFWValue()) == GLFW_PRESS;
			if(isPressed[i] && !wasPressedLastFrame[i]) wasPressedThisFrame[i] = true;
			else wasPressedThisFrame[i] = false;
			if(!isPressed[i] && wasPressedLastFrame[i]) wasReleasedThisFrame[i] = true;
			else wasReleasedThisFrame[i] = false;
		}

		double x, y;
		auto lastMousePosition = mousePosition;
		glfwGetCursorPos(window, &x, &y);
		mousePosition.x = x;
		mousePosition.y = y;
		mouseDelta = mousePosition - lastMousePosition;
	}

	void Input::LateUpdate()
	{
		mouseScrollDelta = Math::Vector2::zero;
	}

	void Input::Close()
	{

	}

	bool Input::GetKey(Key key)
	{
		return isPressed[key.GetValue()];
	}

	bool Input::GetKeyDown(Key key)
	{
		return wasPressedThisFrame[key.GetValue()];
	}

	bool Input::GetKeyUp(Key key)
	{
		return wasReleasedThisFrame[key.GetValue()];
	}

	Math::Vector2 Input::GetMousePosition()
	{
		return mousePosition;
	}

	Math::Vector2 Input::GetMouseDelta()
	{
		return mouseDelta;
	}

	Math::Vector2 Input::GetMouseScrollDelta()
	{
		return mouseScrollDelta;
	}

	void Input::MouseScrollCallBack(GLFWwindow* window, double offsetX, double offsetY)
	{
		mouseScrollDeltaRaw = Math::Vector2(offsetX, offsetY);
	}
}