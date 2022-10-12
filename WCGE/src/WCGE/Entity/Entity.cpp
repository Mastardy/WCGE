#include "Entity.hpp"

#include "../Core/Logging.hpp"

namespace WCGE
{
	unsigned int Entity::currentId = 0;
	std::map<unsigned int, Entity*> Entity::entities;
	
	Entity::Entity()
	{
		id = currentId++;
		entities.insert(std::make_pair(id, this));
	}

	void Entity::Update()
	{
		for(auto&& component : components)
		{
			component->Update();
		}
	}

	void Entity::UpdateAll()
	{
		std::map<unsigned int, Entity*>::iterator iterator;
		for(iterator = entities.begin(); iterator != entities.end(); iterator++)
		{
			iterator->second->Update();
		}
	}
}