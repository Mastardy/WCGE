#pragma once

#include "WCGE/Core/Math/Math.hpp"

#include "WCGE/EntityComponent/Entity.hpp"
#include "WCGE/EntityComponent/IComponent.hpp"

#include "WCGE/Input/Input.hpp"
#include "WCGE/Core/Time.hpp"
#include "WCGE/EntityComponent/Components.hpp"

using namespace WCGE;

class BasicMovement : public IComponent
{
public:
	static const std::size_t type;
	virtual bool IsClassType(const std::size_t classType) const override;

	BasicMovement(Entity* parent);

	virtual void Update() override;
};