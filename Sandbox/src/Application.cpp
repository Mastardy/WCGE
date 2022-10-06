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

		Matrix4 c = Matrix4::identity;
		
		c *= Matrix4::Translate(Vector3(3, 3, 0));
		c *= Matrix4::Scale(5);
		c *= Matrix4::Rotate(Vector3(45, 0, 0));

		std::cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << '\n';
		std::cout << c[4] << " " << c[5] << " " << c[6] << " " << c[7] << '\n';
		std::cout << c[8] << " " << c[9] << " " << c[10] << " " << c[11] << '\n';
		std::cout << c[12] << " " << c[13] << " " << c[14] << " " << c[15] << '\n';

		isRunning = false;
	}
};

WCGE::Application* WCGE::CreateApplication()
{
	return new Sandbox();
}