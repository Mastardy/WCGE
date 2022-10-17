#pragma once

#include "../Core.hpp"
#include "../Core/Math/Math.hpp"

namespace WCGE::Graphics
{
	class WCGE_API Texture
	{
	public:
		Texture() : textureID{0} {}
		Texture(const char* imagePath);
		void Bind();
	private:
		unsigned int textureID;
	};
}