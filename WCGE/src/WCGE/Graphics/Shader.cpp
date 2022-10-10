#include "Shader.hpp"

#include <glad/glad.h>

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

namespace WCGE
{
	Shader::Shader()
	{
		programID = 0;
	}
	
	void Shader::Create(const char* vertexPath, const char* fragmentPath)
	{
		const char* vertexShaderCode = GetShaderCode(vertexPath);
		const char* fragmentShaderCode = GetShaderCode(fragmentPath);

		const unsigned int vertexShader = CompileShader(vertexShaderCode, GL_VERTEX_SHADER);
		const unsigned int fragmentShader = CompileShader(fragmentShaderCode, GL_FRAGMENT_SHADER);

		programID = glCreateProgram();
		glAttachShader(programID, vertexShader);
		glAttachShader(programID, fragmentShader);
		glLinkProgram(programID);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	const char* Shader::GetShaderCode(const char* shaderPath)
	{
		std::string shaderCodeStr;
		std::ifstream shaderFile;
		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			shaderFile.open(shaderPath);
			std::stringstream shaderStream;

			shaderStream << shaderFile.rdbuf();

			shaderFile.close();

			shaderCodeStr = shaderStream.str();
		}
		catch (std::ifstream::failure& e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_READ\n" << e.code() << std::endl;
		}

		const char* shaderCode = shaderCodeStr.c_str();

		return shaderCode;
	}

	unsigned int Shader::CompileShader(const char* shaderCode, const int shaderType)
	{
		const unsigned int shader = glCreateShader(shaderType);
		glShaderSource(shader, 1, &shaderCode, nullptr);
		glCompileShader(shader);
		return shader;
	}


	void Shader::Use() const
	{
		glUseProgram(programID);
	}
}