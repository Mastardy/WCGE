#include "Transform.hpp"

namespace WCGE
{
	const std::size_t Transform::type = std::hash<std::string>()("Transform");

	bool Transform::IsClassType(const std::size_t classType) const
	{
		if(classType == type)
		{
			return true;
		}
		return IComponent::IsClassType(classType);
	}

	void Transform::Update()
	{
		//parent->GetComponent<Renderer>();
	}
}