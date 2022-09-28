#include <WCGE.h>

class Sandbox : public WCGE::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}