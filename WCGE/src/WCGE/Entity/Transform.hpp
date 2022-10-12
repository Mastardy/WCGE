#pragma once

#include "../Core.hpp"
#include "../Core/Math/Math.hpp"

#include "IComponent.hpp"

namespace WCGE
{
	class WCGE_API Transform : public IComponent
	{
	public:
		static const std::size_t type;
		virtual bool IsClassType(const std::size_t classType) const override;

		Transform(Entity* parent) : IComponent(parent) { name = "Transform"; }
		void Update() override;

	//private:
		Math::Vector3 position;
		Math::Vector3 rotation;
		Math::Vector3 scale;
	};
}