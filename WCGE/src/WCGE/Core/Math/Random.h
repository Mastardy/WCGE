#pragma once
#pragma warning(disable : 4251)

#include "../../Core.h"

#include <random>
#include <map>

namespace WCGE
{	
	class WCGE_API Random
	{
	public:
		static void Seed(int seed);
		static float GetValue(float min, float max);
		static int GetValue(int min, int max);
	private:
		static int currentSeed;
		static std::map<int, std::mt19937_64> generators;
	};
}