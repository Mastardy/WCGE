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

		Matrix3 b(1, 3, 2, -3, -1, -3, 2, 3, 1);

		auto c = b.Inverse();

		std::cout << c[0] << " " << c[1] << " " << c[2] << '\n';
		std::cout << c[3] << " " << c[4] << " " << c[5] << '\n';
		std::cout << c[6] << " " << c[7] << " " << c[8] << '\n';

		isRunning = false;
	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}