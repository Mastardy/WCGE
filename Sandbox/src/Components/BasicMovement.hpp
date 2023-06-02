#pragma once

#include "WCGE/EntityComponent/IComponent.hpp"

#include "WCGE/Core/Time.hpp"

using namespace WCGE;

class BasicMovement : public IComponent
{
public:
	static const std::size_t type;
	virtual bool IsClassType(std::size_t classType) const override;

	BasicMovement(Entity* parent);

	virtual void Update() override;
};