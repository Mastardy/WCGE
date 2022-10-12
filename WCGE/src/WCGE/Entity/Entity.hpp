#pragma once
#pragma warning ( disable : 4251 )

#include "../Core.hpp"
#include "IComponent.hpp"

#include <string>
#include <vector>
#include <map>

namespace WCGE
{
	class IComponent;

	class WCGE_API Entity
	{
	public:
		static void UpdateAll();

		virtual void Update();

		template<class ComponentType, typename... Args>
		void AddComponent(Args&&... params)
		{
			ComponentType* newComponent = new ComponentType(std::forward<Args>(params)...);
			components.emplace_back(newComponent);
		}

		template<class ComponentType>
		ComponentType& GetComponent()
		{
			for(auto&& component : components)
			{
				if(component->IsClassType(ComponentType::type))
				{
					return *static_cast<ComponentType*>(component);
				}
			}
			return *static_cast<ComponentType*>(nullptr);
		}

		template<class ComponentType>
		bool RemoveComponent()
		{
			if(components.empty())
			{
				return false;
			}

			auto& index = std::find_if(components.begin(), components.end(), [classType = ComponentType::type](auto& component)
									   {
										   return component->IsClassType(classType);
									   });
			
			bool success = index != components.end();
			
			if(success)
			{
				components.erase(index);
			}

			return success;
		}

	protected:
		static std::map<unsigned int, Entity*> entities;
		static unsigned int currentId;

		Entity();
		
		unsigned int id;
		std::string className;
		std::vector<IComponent*> components;
	};
}