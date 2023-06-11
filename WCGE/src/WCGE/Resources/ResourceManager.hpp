#pragma once

#include "../Core.hpp"

#include "../Graphics/Shader.hpp"
#include "../Graphics/Texture.hpp"

#include <map>
#include <string>

namespace WCGE
{
	class WCGE_API ResourceManager
	{
	public:
		static Graphics::Shader* LoadShader(const std::string& name, const char* vertexPath, const char* fragmentPath);
		static Graphics::Shader* GetShader(const std::string& name);
		static Graphics::Texture* LoadTexture(const std::string& name, const char* texturePath);
		static Graphics::Texture* GetTexture(const std::string& name);

	private:
		static std::map<size_t, Graphics::Shader> shaders;
		static std::map<size_t, Graphics::Texture> textures;
	};
}