#pragma once

#include "../../Core.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <initializer_list>

namespace WCGE::Math
{
	const float PI = static_cast<float>(M_PI);
	const float PI_HALF = PI * 0.5f;
	const float DEG2RAD = PI / 180.0f;
	const float RAD2DEG = 180.0f * static_cast<float>(M_1_PI);

	float WCGE_API Abs(float number);
	int WCGE_API Abs(int number);

	float WCGE_API Acos(float number);
	float WCGE_API Asin(float number);
	float WCGE_API Atan(float number);
	float WCGE_API Atan2(float x, float y);
	float WCGE_API Ceil(float number);
	int WCGE_API CeilToInt(float number);
	float WCGE_API Clamp(float min, float max, float number);
	float WCGE_API Clamp01(float number);
	float WCGE_API Cos(float number);
	float WCGE_API Exp(float number);
	float WCGE_API Floor(float number);
	int WCGE_API FloorToInt(float number);
	float WCGE_API InvLerp(float start, float end, float number);
	float WCGE_API Lerp(float start, float end, float number);
	float WCGE_API Ln(float number);
	float WCGE_API Log(float number, float base);
	float WCGE_API Log10(float number);
	float WCGE_API Max(std::initializer_list<float> numbers);
	int WCGE_API Max(std::initializer_list<int> numbers);
	float WCGE_API Min(std::initializer_list<float> numbers);
	int WCGE_API Min(std::initializer_list<int> numbers);
	float WCGE_API MoveTowards(float start, float end, float step);
	float WCGE_API Pow(float number, float power);
	float WCGE_API Round(float number);
	int WCGE_API RoundToInt(float number);
	int WCGE_API Sign(float number);
	float WCGE_API Sin(float number);
	float WCGE_API Sqrt(float number);
	float WCGE_API Tan(float number);
}