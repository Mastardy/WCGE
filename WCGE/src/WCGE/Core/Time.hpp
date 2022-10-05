#pragma once

#include "../Core.hpp"

#include <chrono>

using namespace std::chrono;

template class WCGE_API duration<__int64, std::nano>;
template class WCGE_API steady_clock::time_point;

namespace WCGE
{
	class WCGE_API Time
	{
	public:
		static float timeScale;

		static void Init();

		static void Update();

		static void CalculateCurrentFrame();
		static void CalculateTime();
		static void CalculateDeltaTime();

		static float GetDeltaTime();
		static float GetTime();

	private:
		static steady_clock::time_point applicationStart;
		static steady_clock::time_point currentFrame;
		static steady_clock::time_point lastFrame;
		static float deltaTime;
		static float time;
	};
}