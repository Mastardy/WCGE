#pragma once
#pragma warning ( disable : 4251 )

#include "../Core.hpp"
#include "IComponent.hpp"

#include <string>
#include <map>

namespace WCGE
{
	class WCGE_API Entity
	{
	public:
		static void UpdateAll();

	protected:
		static std::map<unsigned int, Entity*> entities;
		static unsigned int currentId;

		Entity();
		virtual void Update() abstract;
		
		unsigned int id;
		std::string className;
		std::map<unsigned int, IComponent*> components;
	};
}