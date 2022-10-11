#pragma once

#include "../Core.hpp"
#include "../Core/Math/Math.hpp"

namespace WCGE::Graphics
{
	class WCGE_API Texture
	{
	public:
		Texture();
		void Create(const char* imagePath);
		void Bind();
	private:
		unsigned int textureID;
	};
}