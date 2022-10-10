#include "Logging.hpp"

#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>

namespace WCGE
{
	tm* GetTimeBuffer()
	{
		const time_t now = std::time(nullptr);
		auto* buffer = new tm;
		auto error = localtime_s(buffer, &now);

		return buffer;
	}

	std::string GetCurrentTime()
	{
		char str[26];
		auto error = asctime_s(str, sizeof str, GetTimeBuffer());
		str[strlen(str) - 1] = '\0';
		
		return str;
	}

	void Logging::Init()
	{
		Info("Starting Log for WCGE [Wait Craft Game Engine]\n");
	}

	void Logging::Debug(const std::string& message)
	{
		std::cout << "[" + GetCurrentTime() + "] DEBUG - " + message + '\n';
	}

	void Logging::Info(const std::string& message)
	{
		std::cout << "[" + GetCurrentTime() + "] INFO - " + message + '\n';
	}

	void Logging::Warning(const std::string& message)
	{
		std::cout << "[" + GetCurrentTime() + "] WARNING - " + message + '\n';
	}

	void Logging::Error(const std::string& message)
	{
		std::cout << "\n[" + GetCurrentTime() + "] ERROR - " + message + '\n';
	}
}