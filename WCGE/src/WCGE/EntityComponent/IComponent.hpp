#pragma once

#include "../Core.hpp"

#include "Entity.hpp"

#include <string>

namespace WCGE
{
	class Entity;

	class WCGE_API IComponent
	{
	public:
		static const std::size_t type;

		virtual bool IsClassType(const std::size_t classType) const;

		IComponent(Entity* parent);
		virtual ~IComponent() = default;

		virtual void Update() abstract;
		std::string GetName();

	protected:
		Entity* parent;
		std::string name;
	};
}