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
		
	private:
		struct Vertex
		{
			Math::Vector3 position;
			Math::Vector3 color;
		};
		std::array<Vertex, 3> vertices;
		unsigned int vertexArrayObject;
		unsigned int vertexBufferObject;
	};
}