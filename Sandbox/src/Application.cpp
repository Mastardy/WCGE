#include <WCGE.h>
#include <iostream>

class Sandbox : public WCGE::Application
{
public:
	Sandbox() {}

	~Sandbox() {}
	
	void Run()
	{
		Application::Run();
		std::cout << "Hello Sandbox!";
	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}