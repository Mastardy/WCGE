#pragma once

#include "../Core.hpp"
#include <string>

namespace WCGE
{
	class WCGE_API Logging
	{
	public:
		static void Init();

		static void Debug(const std::string& message);
		static void Info(const std::string& message);
		static void Warning(const std::string& message);
		static void Error(const std::string& message);

		static std::string Bool(const bool& condition);
		
		static void Pause();
	};
}