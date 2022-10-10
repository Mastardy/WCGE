#pragma once

#include "../Core.hpp"

#include "../Core/Math/Math.hpp"

namespace WCGE {
	class WCGE_API Triangle
	{
	public:
		Triangle();
		void Create();
		void Draw() const;
		std::array<Math::Vector3, 3> vertices;
	private:

		unsigned int vertexArrayObject;
		unsigned int vertexBufferObject;
	};
}