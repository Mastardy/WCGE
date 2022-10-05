#include <WCGE.hpp>
#include <iostream>

using namespace WCGE;
using namespace WCGE::Math;

class Sandbox : public Application
{
public:
	std::map<int, char> numbers{};

	Sandbox() : Application() {}

	~Sandbox() {}
	
	void Run()
	{
		Application::Run();

		Rect a;
		Rect b(5);

		std::cout << a << '\n' << b;

		isRunning = false;
	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}