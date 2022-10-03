#pragma once

#include "../Core.h"

#include <chrono>

using namespace std::chrono;

namespace WCGE
{
	class WCGE_API Time
	{
	public:
		static void Init();

		static void CalculateTime();
		static void CalculateDeltaTime();

		static float GetDeltaTime();
		static float GetTime();

	private:
		static steady_clock::time_point applicationStart;
		static steady_clock::time_point lastFrame;
		static float deltaTime;
		static float time;
	};
}