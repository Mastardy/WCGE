#include "Time.h"

#include <chrono>

using namespace std::chrono;

namespace WCGE
{
	float Time::timeScale = 1.0f;

	steady_clock::time_point Time::applicationStart;
	steady_clock::time_point Time::currentFrame;
	steady_clock::time_point Time::lastFrame;
	
	float Time::time = 0;
	float Time::deltaTime = 0;

	void Time::Init()
	{
		currentFrame = steady_clock::now();
		applicationStart = steady_clock::now();
		lastFrame = steady_clock::now();
	}

	void Time::Update()
	{
		CalculateCurrentFrame();
		CalculateTime();
		CalculateDeltaTime();
	}

	void Time::CalculateCurrentFrame()
	{
		currentFrame = steady_clock::now();
	}

	void Time::CalculateDeltaTime()
	{
		duration<float> duration = currentFrame - lastFrame;
		deltaTime = duration.count() * timeScale;
		lastFrame = steady_clock::now();
	}

	void Time::CalculateTime()
	{
		duration<float> duration = currentFrame - applicationStart;
		time = duration.count() * timeScale;
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