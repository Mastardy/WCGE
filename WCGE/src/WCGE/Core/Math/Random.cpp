#include "Random.h"

namespace WCGE
{
    std::map<int, std::mt19937_64> Random::generators{{0, std::mt19937_64(0)}};
    int Random::currentSeed = 0;

    void Random::Seed(int seed)
    {
        currentSeed = seed;
        if(generators.find(seed) == generators.end()) generators[seed] = std::mt19937_64(seed);
    }

    float Random::GetValue(float min, float max)
    {
        std::uniform_real_distribution<float> distribution(min, max);
        return distribution(generators[currentSeed]);
    }

    int Random::GetValue(int min, int max)
    {
        std::uniform_int_distribution distribution(min, max);
        return distribution(generators[currentSeed]);
    }

}