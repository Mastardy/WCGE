#pragma once

#include "../Core.hpp"

#include <string>

namespace WCGE
{
	struct WCGE_API IComponent
	{
	public:
		virtual void Update() abstract;
		std::string GetName();

	private:
		std::string name;
	};
}