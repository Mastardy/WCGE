#include "IComponent.hpp"

namespace WCGE
{
	const std::size_t IComponent::type = 0;

	bool IComponent::IsClassType(const std::size_t classType) const
	{
		return classType == type;
	}

	IComponent::IComponent(Entity* parent)
	{
		this->parent = parent;
	}

	std::string IComponent::GetName()
	{
		return name;
	}
}