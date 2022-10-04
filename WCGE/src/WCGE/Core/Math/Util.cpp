#include "Util.h"

#include <algorithm>
#include <math.h>
#include <initializer_list>

namespace WCGE::Math
{
	float Abs(float number)
	{
		return fabsf(number);
	}

	int Abs(int number)
	{
		return abs(number);
	}

	float Acos(float number)
	{
		return acosf(number);
	}

	float Asin(float number)
	{
		return asinf(number);
	}

	float Atan(float number)
	{
		return atanf(number);
	}

	float Atan2(float y, float x)
	{
		return atan2f(y, x);
	}

	float Ceil(float number)
	{
		return ceilf(number);
	}

	int CeilToInt(float number)
	{
		return static_cast<int>(ceilf(number));
	}

	float Clamp(float min, float max, float number)
	{
		return number < min ? min : (number > max ? max : number);
	}

	float Clamp01(float number)
	{
		return Clamp(0, 1, number);
	}

	float Cos(float number)
	{
		return cosf(number);
	}

	float Exp(float number)
	{
		return expf(number);
	}

	float Floor(float number)
	{
		return floorf(number);
	}

	int FloorToInt(float number)
	{
		return static_cast<int>(floorf(number));
	}

	float InvLerp(float start, float end, float number)
	{
		return Lerp(end, start, number);
	}

	float Lerp(float start, float end, float number)
	{
		number = Clamp01(number);
		return start + ((end - start) * number);
	}

	float Ln(float number)
	{
		return logf(number);
	}

	float Log(float number, float base)
	{
		return logf(number) / logf(base);
	}

	float Log10(float number)
	{
		return log10f(number);
	}

	float Max(std::initializer_list<float> numbers)
	{
		return std::max(numbers);
	}

	int Max(std::initializer_list<int> numbers)
	{
		return std::max(numbers);
	}

	float Min(std::initializer_list<float> numbers)
	{
		return std::min(numbers);
	}

	int Min(std::initializer_list<int> numbers)
	{
		return std::min(numbers);
	}

	float MoveTowards(float start, float end, float step)
	{
		return Min(std::initializer_list<float>({start + step, end}));
	}

	float Pow(float number, float power)
	{
		return powf(number, power);
	}

	float Round(float number)
	{
		return roundf(number);
	}

	int RoundToInt(float number)
	{
		return static_cast<int>(roundf(number));
	}

	int Sign(float number)
	{
		return number < 0 ? -1 : (number > 0 ? 1 : 0);
	}

	float Sin(float number)
	{
		return sinf(number);
	}

	float Sqrt(float number)
	{
		return sqrtf(number);
	}

	float Tan(float number)
	{
		return tanf(number);
	}
}