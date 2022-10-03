#include "Time.h"

#include <chrono>

using namespace std::chrono;

namespace WCGE
{
	steady_clock::time_point Time::applicationStart;
	steady_clock::time_point Time::lastFrame;
	float Time::time = 0;
	float Time::deltaTime = 0;

	void Time::Init()
	{
		applicationStart = steady_clock::now();
		lastFrame = steady_clock::now();
	}

	void Time::CalculateDeltaTime()
	{
		auto currentFrame = steady_clock::now();
		duration<float> duration = currentFrame - lastFrame;
		deltaTime = duration.count();
		lastFrame = steady_clock::now();
	}

	void Time::CalculateTime()
	{
		auto currentFrame = steady_clock::now();
		duration<float> duration = currentFrame - applicationStart;
		time = duration.count();
	}

	float Time::GetTime()
	{
		return time;
	}

	float Time::GetDeltaTime()
	{
		return deltaTime;
	}
}