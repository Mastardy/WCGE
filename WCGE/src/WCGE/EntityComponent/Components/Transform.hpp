#pragma once

#include "../../Core.hpp"
#include "../../Core/Math/Math.hpp"

#include "../IComponent.hpp"

namespace WCGE
{
	class WCGE_API Transform : public IComponent
	{
	public:
		static const std::size_t type;
		virtual bool IsClassType(const std::size_t classType) const override;

		Transform(Entity* parent);
		Transform(Entity* parent, const Math::Vector3& position, const Math::Vector3& rotation, const Math::Vector3& scale);

		void Update() override;

		void Translate(const Math::Vector3& translation);
		void Translate(float xTranslation, float yTranslation, float zTranslation);

		void Rotate(const Math::Vector3& rotation);
		void Rotate(float xRotation, float yRotation, float zRotation);

		void Scale(float scalar);
		void Scale(const Math::Vector3& scalar);
		void Scale(float xScalar, float yScalar, float zScalar);

	//private:
		Math::Vector3 position;
		Math::Vector3 rotation;
		Math::Vector3 scale;
	};
}