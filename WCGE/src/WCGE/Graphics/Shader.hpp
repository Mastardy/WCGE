#pragma once

#include "../Core.hpp"

namespace WCGE
{
	class WCGE_API Shader
	{
	public:
		Shader();

		void Create(const char* vertexPath, const char* fragmentPath);

		static const char* GetShaderCode(const char* shaderPath);
		static unsigned int CompileShader(const char* shaderCode, const int shaderType);

		void Use() const;
	private:
		unsigned int programID;
	};
}