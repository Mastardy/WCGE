#include "Key.hpp"

#include <array>

namespace WCGE
{
	Key::Key(int value, int glfwValue) : value{value}, glfwValue{glfwValue} {}

	Key::Key() : value{0}, glfwValue{0} {}

	int Key::GetValue()
	{
		return value;
	}

	int Key::GetGLFWValue()
	{
		return glfwValue;
	}

	const Key Key::Space = Key(0, 32);

	const Key Key::Apostrophe = Key(1, 39);
	
	const Key Key::Comma = Key(2, 44);
	const Key Key::Minus = Key(3, 45);
	const Key Key::Period = Key(4, 46);
	const Key Key::Slash = Key(5, 47);
	const Key Key::A0 = Key(6, 48);
	const Key Key::A1 = Key(7, 49);
	const Key Key::A2 = Key(8, 50);
	const Key Key::A3 = Key(9, 51);
	const Key Key::A4 = Key(10, 52);
	const Key Key::A5 = Key(11, 53);
	const Key Key::A6 = Key(12, 54);
	const Key Key::A7 = Key(13, 55);
	const Key Key::A8 = Key(14, 56);
	const Key Key::A9 = Key(15, 57);
	
	const Key Key::Semicolon = Key(16, 59);
	
	const Key Key::Equal = Key(17, 61);
	
	const Key Key::A = Key(18, 65);
	const Key Key::B = Key(19, 66);
	const Key Key::C = Key(20, 67);
	const Key Key::D = Key(21, 68);
	const Key Key::E = Key(22, 69);
	const Key Key::F = Key(23, 70);
	const Key Key::G = Key(24, 71);
	const Key Key::H = Key(25, 72);
	const Key Key::I = Key(26, 73);
	const Key Key::J = Key(27, 74);
	const Key Key::K = Key(28, 75);
	const Key Key::L = Key(29, 76);
	const Key Key::M = Key(30, 77);
	const Key Key::N = Key(31, 78);
	const Key Key::O = Key(32, 79);
	const Key Key::P = Key(33, 80);
	const Key Key::Q = Key(34, 81);
	const Key Key::R = Key(35, 82);
	const Key Key::S = Key(36, 83);
	const Key Key::T = Key(37, 84);
	const Key Key::U = Key(38, 85);
	const Key Key::V = Key(39, 86);
	const Key Key::W = Key(40, 87);
	const Key Key::X = Key(41, 88);
	const Key Key::Y = Key(42, 89);
	const Key Key::Z = Key(43, 90);
	const Key Key::LBracket = Key(44, 91);
	const Key Key::Backslash = Key(45, 92);
	const Key Key::RBracket = Key(46, 93);
	
	const Key Key::GraveAccent = Key(47, 96);
	
	const Key Key::World1 = Key(48, 161);
	const Key Key::World2 = Key(49, 162);
	
	const Key Key::Escape = Key(50, 256);
	const Key Key::Enter = Key(51, 257);
	const Key Key::Tab = Key(52, 258);
	const Key Key::Backspace = Key(53, 259);
	const Key Key::Insert = Key(54, 260);
	const Key Key::Delete = Key(55, 261);
	const Key Key::Right = Key(56, 262);
	const Key Key::Left = Key(57, 263);
	const Key Key::Down = Key(58, 264);
	const Key Key::Up = Key(59, 265);
	const Key Key::PageUp = Key(60, 266);
	const Key Key::PageDown = Key(61, 267);
	const Key Key::Home = Key(62, 268);
	const Key Key::End = Key(63, 269);

	const Key Key::CapsLock = Key(64, 280);
	const Key Key::ScrollLock = Key(65, 281);
	const Key Key::NumLock = Key(66, 282);
	const Key Key::PrintScreen = Key(67, 283);
	const Key Key::Pause = Key(68, 284);

	const Key Key::F1 = Key(69, 290);
	const Key Key::F2 = Key(70, 291);
	const Key Key::F3 = Key(71, 292);
	const Key Key::F4 = Key(72, 293);
	const Key Key::F5 = Key(73, 294);
	const Key Key::F6 = Key(74, 295);
	const Key Key::F7 = Key(75, 296);
	const Key Key::F8 = Key(76, 297);
	const Key Key::F9 = Key(77, 298);
	const Key Key::F10 = Key(78, 299);
	const Key Key::F11 = Key(79, 300);
	const Key Key::F12 = Key(80, 301);

	const Key Key::KP0 = Key(81, 320);
	const Key Key::KP1 = Key(82, 321);
	const Key Key::KP2 = Key(83, 322);
	const Key Key::KP3 = Key(84, 323);
	const Key Key::KP4 = Key(85, 324);
	const Key Key::KP5 = Key(86, 325);
	const Key Key::KP6 = Key(87, 326);
	const Key Key::KP7 = Key(88, 327);
	const Key Key::KP8 = Key(89, 328);
	const Key Key::KP9 = Key(90, 329);
	const Key Key::KPDecimal = Key(91, 330);
	const Key Key::KPDivide = Key(92, 331);
	const Key Key::KPMultiply = Key(93, 332);
	const Key Key::KPSubtract = Key(94, 333);
	const Key Key::KPAdd = Key(95, 334);
	const Key Key::KPEnter = Key(96, 335);
	const Key Key::KPEqual = Key(97, 336);

	const Key Key::LShift = Key(98, 340);
	const Key Key::LCtrl = Key(99, 341);
	const Key Key::LAlt = Key(100, 342);
	const Key Key::LSuper = Key(101, 343);
	const Key Key::RShift = Key(102, 344);
	const Key Key::RCtrl = Key(103, 345);
	const Key Key::RAlt = Key(104, 346);
	const Key Key::RSuper = Key(105, 347);
	const Key Key::Menu = Key(106, 348);
}