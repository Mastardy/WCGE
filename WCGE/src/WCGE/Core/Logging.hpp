#pragma once

#include "../Core.hpp"
#include <fstream>

namespace WCGE
{
	class WCGE_API Logging
	{
	public:
		static void Init();
		static void Close();

		static void Debug(std::string message);
		static void Info(std::string message);
		static void Warning(std::string message);
		static void Error(std::string message);
	private:
		static std::ofstream* logFile;
	};
}