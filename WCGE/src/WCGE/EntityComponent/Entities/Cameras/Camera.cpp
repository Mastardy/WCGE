#include "Camera.hpp"

namespace WCGE
{
	Camera* Camera::current = nullptr;

	Camera::Camera(const Vector3& position, const Vector3& up, const Vector3& rotation, const float& fov, const float& near, const float& far)
	{
		current = this;
	
		this->position = position;
		this->worldUp = up;
		this->rotation = rotation;
		this->fieldOfView = fov;

		this->near = near;
		this->far = far;
		
		UpdateCameraVectors();
	}

	Matrix4 Camera::GetViewMatrix() const
	{
		return Matrix4::LookAt(position, position + front, up);
	}

	// TODO: Ortho
	Matrix4 Camera::GetProjectionMatrix() const
	{
		const float aspect = 16.0f / 9.0f;

		const float g = 1.0f / tan(fieldOfView * 0.5f);
		const float k = far / (far - near);

		return {
			g/aspect, 0, 0, 0,
			0, g, 0, 0,
			0, 0, k, -near * k,
			0, 0, 1.0f, 0
		};
	}

	void Camera::UpdateCameraVectors()
	{
		front = Vector3(
			Cos(rotation.y * DEG2RAD) * Cos(rotation.x * DEG2RAD),
			Sin(rotation.x * DEG2RAD),
			Sin(rotation.y * DEG2RAD) * Cos(rotation.x * DEG2RAD)
		).Normalized();

		right = Vector3::Cross(front, worldUp).Normalized();
		up = Vector3::Cross(right, front).Normalized();
	}
	
	Camera* Camera::Current()
	{
		return current;
	}
}