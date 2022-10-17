#include "ResourceManager.hpp"

namespace WCGE
{
	std::map<size_t, Graphics::Shader> ResourceManager::shaders;
	std::map<size_t, Graphics::Texture> ResourceManager::textures;

	Graphics::Shader* ResourceManager::LoadShader(const std::string& name, const char* vertexPath, const char* fragmentPath)
	{
		shaders.insert(std::make_pair(std::hash<std::string>()(name), Graphics::Shader(vertexPath, fragmentPath)));
		return &(shaders.at(std::hash<std::string>()(name)));
	}

	Graphics::Shader* ResourceManager::GetShader(const std::string& name)
	{
		return &(shaders.at(std::hash<std::string>()(name)));
	}

	Graphics::Texture* ResourceManager::LoadTexture(const std::string& name, const char* texturePath)
	{
		textures.insert(std::make_pair(std::hash<std::string>()(name), Graphics::Texture(texturePath)));
		return &(textures.at(std::hash<std::string>()(name)));
	}

	Graphics::Texture* ResourceManager::GetTexture(const std::string& name)
	{
		return &(textures.at(std::hash<std::string>()(name)));
	}
}