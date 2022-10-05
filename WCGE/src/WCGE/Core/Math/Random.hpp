#pragma once
#pragma warning(disable : 4251)

#include "../../Core.hpp"

#include <random>
#include <map>

namespace WCGE::Math
{	
	class WCGE_API Random
	{
	public:
		static void Seed(int seed);
		static float GetValue(float min, float max);
		static float GetValue(int min, float max);
		static float GetValue(float min, int max);
		static int GetValue(int min, int max);

	private:
		static int currentSeed;
		static std::map<int, std::mt19937_64> generators;
	};
}