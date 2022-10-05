#pragma once

#ifdef WCGE_PLATFORM_WINDOWS
	#ifdef WCGE_BUILD_DLL
		#define WCGE_API __declspec(dllexport)
	#else
		#define WCGE_API __declspec(dllimport)
	#endif
#else
	#error WCGE Only Supports Windows!
#endif