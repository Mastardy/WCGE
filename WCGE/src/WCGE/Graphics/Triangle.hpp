﻿#pragma once

#include "../Core.hpp"

#include "../Core/Math/Math.hpp"

namespace WCGE {
	class WCGE_API Triangle
	{
	public:
		Triangle();
		void Create();
		void Draw() const;

	private:
		std::array<Math::Vector3, 3> vertices;
		unsigned int vertexArrayObject;
		unsigned int vertexBufferObject;
	};
}