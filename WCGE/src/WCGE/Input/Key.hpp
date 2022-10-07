#pragma once

#include "../Core.hpp"

namespace WCGE
{
	class WCGE_API Key
	{
	private:
		Key(int value, int glfwValue);
		int value;
		int glfwValue;
	public:
		Key();
		int GetValue();
		int GetGLFWValue();

		static const Key Space;
		static const Key Apostrophe; /* ' */
		static const Key Comma;      /* , */
		static const Key Minus;      /* - */
		static const Key Period;     /* . */
		static const Key Slash;      /* / */
		static const Key A0;
		static const Key A1;
		static const Key A2;
		static const Key A3;
		static const Key A4;
		static const Key A5;
		static const Key A6;
		static const Key A7;
		static const Key A8;
		static const Key A9;
		static const Key Semicolon;
		static const Key Equal;
		static const Key A;
		static const Key B;
		static const Key C;
		static const Key D;
		static const Key E;
		static const Key F;
		static const Key G;
		static const Key H;
		static const Key I;
		static const Key J;
		static const Key K;
		static const Key L;
		static const Key M;
		static const Key N;
		static const Key O;
		static const Key P;
		static const Key Q;
		static const Key R;
		static const Key S;
		static const Key T;
		static const Key U;
		static const Key V;
		static const Key W;
		static const Key X;
		static const Key Y;
		static const Key Z;
		static const Key LBracket;
		static const Key Backslash;
		static const Key RBracket;
		static const Key GraveAccent;
		static const Key World1;
		static const Key World2;
		static const Key Escape;
		static const Key Enter;
		static const Key Tab;
		static const Key Backspace;
		static const Key Insert;
		static const Key Delete;
		static const Key Right;
		static const Key Left;
		static const Key Down;
		static const Key Up;
		static const Key PageUp;
		static const Key PageDown;
		static const Key Home;
		static const Key End;
		static const Key CapsLock;
		static const Key ScrollLock;
		static const Key NumLock;
		static const Key PrintScreen;
		static const Key Pause;
		static const Key F1;
		static const Key F2;
		static const Key F3;
		static const Key F4;
		static const Key F5;
		static const Key F6;
		static const Key F7;
		static const Key F8;
		static const Key F9;
		static const Key F10;
		static const Key F11;
		static const Key F12;
		static const Key KP0;
		static const Key KP1;
		static const Key KP2;
		static const Key KP3;
		static const Key KP4;
		static const Key KP5;
		static const Key KP6;
		static const Key KP7;
		static const Key KP8;
		static const Key KP9;
		static const Key KPDecimal;
		static const Key KPDivide;
		static const Key KPMultiply;
		static const Key KPSubtract;
		static const Key KPAdd;
		static const Key KPEnter;
		static const Key KPEqual;
		static const Key LShift;
		static const Key LCtrl;
		static const Key LAlt;
		static const Key LSuper;
		static const Key RShift;
		static const Key RCtrl;
		static const Key RAlt;
		static const Key RSuper;
		static const Key Menu;
	};
}
