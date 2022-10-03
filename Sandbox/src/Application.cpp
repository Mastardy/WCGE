#include <WCGE.h>
#include <iostream>

using namespace WCGE;

class Sandbox : public Application
{
public:
	Sandbox() : Application() {}

	~Sandbox() {}
	
	void Run()
	{
		Application::Run();

		std::cout << std::fixed << 1 / Time::GetDeltaTime() << '\n';
	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}