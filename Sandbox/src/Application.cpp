#include <WCGE.h>
#include <iostream>

class Sandbox : public WCGE::Application
{
public:
	Sandbox() : WCGE::Application() {}

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