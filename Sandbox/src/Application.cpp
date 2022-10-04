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
	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}