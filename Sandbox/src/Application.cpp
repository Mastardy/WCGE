#include <WCGE.h>
#include <iostream>
#include <random>
#include <map>

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

		Random::Seed(5);
		std::cout << Random::GetValue(0, 5) << '\n';
	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}