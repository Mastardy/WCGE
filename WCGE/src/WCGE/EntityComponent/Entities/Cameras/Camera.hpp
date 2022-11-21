#pragma once

#include "../../../Core.hpp"

#include "../../Entity.hpp"
#include "../../../Core/Math/Math.hpp"

using namespace WCGE::Math;

namespace WCGE
{
	class WCGE_API Camera : public Entity
	{
	public:

		Vector3 position;
		Vector3 front;
		Vector3 up;
		Vector3 right;
		Vector3 worldUp;

		Vector3 rotation;
		
		float fieldOfView;

		float near;
		float far;

		Camera(const Vector3& position = Vector3(1.0f, 0.0f, 0.0f), const Vector3& up = Vector3(0.0f, 1.0f, 0.0f), const Vector3& rotation = Vector3(0.0f, -90.0f, 0.0f), const float& fov = 90.0f, const float& near = 0.01f, const float& far = 1000.0f);
		
		Matrix4 GetViewMatrix();
		Matrix4 GetProjectionMatrix();

		static Camera* Current();

	protected:
		static Camera* current;

	private:
		void UpdateCameraVectors();
	};
}