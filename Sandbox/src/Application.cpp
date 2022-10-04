#include <WCGE.h>
#include <iostream>

using namespace WCGE;
using namespace WCGE::Math;

class Sandbox : public Application
{
public:
	Sandbox() : Application() {}

	~Sandbox() {}
	
	void Run()
	{
		Application::Run();

		std::cout << Vector3::Angle(Vector3(1, 0, 0), Vector3(1, 1, 0)) << '\n';
	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}