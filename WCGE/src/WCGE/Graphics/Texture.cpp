#include "Texture.hpp"
#include "../Core/Logging.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"

#include <glad/glad.h>

#include <format>

namespace WCGE::Graphics
{
	Texture::Texture() : textureID{0} {}

	void Texture::Create(const char* imagePath)
	{
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		stbi_set_flip_vertically_on_load(true);

		int width, height, nrChannels;
		unsigned char* data = stbi_load(imagePath, &width, &height, &nrChannels, 0);

		if(data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			Logging::Error(std::format("Failed to Create Image at {}", imagePath));
		}

		stbi_image_free(data);
	}

	void Texture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, textureID);
	}
}