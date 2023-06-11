#pragma once

#include "../Core.hpp"

namespace WCGE::Graphics
{
	class WCGE_API Texture
	{
	public:
		Texture() : textureID{0} {}
		Texture(const char* imagePath);
		void Bind() const;
	private:
		unsigned int textureID;
	};
}