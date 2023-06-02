#include "Logging.hpp"

#include <iostream>
#include <sstream>
#include <ctime>

namespace WCGE
{	
	std::string GetCurrentTime()
	{
		const time_t now = std::time(nullptr);
		std::tm timeInfo{};
		auto _ = localtime_s(&timeInfo, &now);
		
		const auto format = "%d/%m/%Y %H:%M:%S";

		char buffer[80];
		auto __ = std::strftime(buffer, sizeof(buffer), format, &timeInfo);

		return {buffer};
	}

	void Logging::Init()
	{
		Info("Starting Log for WCGE [Wait Craft Game Engine]\n");
	}

	void Logging::Debug(const std::string& message)
	{
		std::cout << "[\033[36mDEBUG\033[0m - " + GetCurrentTime() + "] " + message + '\n';
	}

	void Logging::Info(const std::string& message)
	{
		std::cout << "[\033[32mINFO\033[0m - " + GetCurrentTime() + "] " + message + '\n';
	}

	void Logging::Warning(const std::string& message)
	{
		std::cout << "[\033[33mWARNING\033[0m - " + GetCurrentTime() + "] " + message + '\n';
	}

	void Logging::Error(const std::string& message)
	{
		std::cout << "[\033[31mERROR\033[0m - " + GetCurrentTime() + "] " + message + '\n';
	}

	void Logging::Pause()
	{
		std::cin.get();
	}
}
