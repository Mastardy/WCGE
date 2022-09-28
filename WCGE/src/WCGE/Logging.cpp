#include "Logging.h"

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <format>
#include <algorithm>

namespace WCGE
{
	std::ofstream* Logging::logFile;

	tm* GetTimeBuffer()
	{
		time_t now = std::time(0);
		tm* buffer = new tm;
		localtime_s(buffer, &now);

		return buffer;
	}

	std::string GetCurrentTime()
	{
		tm* timeBuffer = GetTimeBuffer();

		char str[26];
		asctime_s(str, sizeof str, timeBuffer);
		str[strlen(str) - 1] = '\0';
		
		return str;
	}

	void Logging::Init()
	{
		tm* timeBuffer = GetTimeBuffer();

		std::string fileName = "LOG_" + std::to_string(timeBuffer->tm_mday)
			+ "-" + std::to_string(timeBuffer->tm_mon + 1)
			+ "-" + std::to_string((timeBuffer->tm_year + 1900) % 100)
			+ "_" + std::to_string(timeBuffer->tm_hour)
			+ "-" + std::to_string(timeBuffer->tm_min)
			+ "-" + std::to_string(timeBuffer->tm_sec) + ".log";
		logFile = new std::ofstream(fileName);

		Log("Starting Log for WCGE [Wait Console Game Engine]\n\n");
	}

	void Logging::Log(std::string message)
	{
		*logFile << "[" + GetCurrentTime() + "] INFO - " + message + '\n';
	}

	void Logging::Error(std::string message)
	{
		*logFile << "\n[" + GetCurrentTime() + "] ERROR - " + message + '\n';
	}

	void Logging::Terminate()
	{
		logFile->close();
	}
}