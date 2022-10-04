#include <WCGE.h>
#include <iostream>

using namespace WCGE;

class Sandbox : public Application
{
public:
	float timer = 0.0f;
	bool goingUp = true;

	float lastWrite = 0.0f;

	Sandbox() : Application() {}

	~Sandbox() {}
	
	void Run()
	{
		Application::Run();

		if(goingUp) timer += Time::GetDeltaTime();
		else timer -= Time::GetDeltaTime();

		if(timer > 1.0f) goingUp = false;
		else if(timer < 0.0f) goingUp = true;

		if(Time::GetTime() - lastWrite < 0.25f) return;

		lastWrite = Time::GetTime();
	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}