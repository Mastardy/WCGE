#include "Logging.hpp"

#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>

// TODO: Implement in own console | 

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
		char str[26];
		asctime_s(str, sizeof str, GetTimeBuffer());
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

		Info("Starting Log for WCGE [Wait Console Game Engine]\n\n");

		delete timeBuffer;
	}

	void Logging::Debug(std::string message)
	{
		*logFile << "[" + GetCurrentTime() + "] DEBUG - " + message + '\n';
	}

	void Logging::Info(std::string message)
	{
		*logFile << "[" + GetCurrentTime() + "] INFO - " + message + '\n';
	}

	void Logging::Warning(std::string message)
	{
		*logFile << "[" + GetCurrentTime() + "] WARNING - " + message + '\n';
	}

	void Logging::Error(std::string message)
	{
		*logFile << "\n[" + GetCurrentTime() + "] ERROR - " + message + '\n';
	}

	void Logging::Terminate()
	{
		logFile->close();
		delete logFile;
	}
}