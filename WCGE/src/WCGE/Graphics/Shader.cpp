#include "Shader.hpp"

#include "../Core/Logging.hpp"

#include <glad/glad.h>

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

namespace WCGE::Graphics
{
	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
		std::string vertexShaderCode = GetShaderCode(vertexPath);
		std::string fragmentShaderCode = GetShaderCode(fragmentPath);

		const unsigned int vertexShader = CompileShader(vertexShaderCode.c_str(), GL_VERTEX_SHADER);
		const unsigned int fragmentShader = CompileShader(fragmentShaderCode.c_str(), GL_FRAGMENT_SHADER);

		programID = glCreateProgram();
		glAttachShader(programID, vertexShader);
		glAttachShader(programID, fragmentShader);
		glLinkProgram(programID);

		int success;
		glGetProgramiv(programID, GL_LINK_STATUS, &success);
		if (!success)
		{
			char infoLog[512];
			glGetProgramInfoLog(programID, 512, nullptr, infoLog);
			Logging::Error(infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	std::string Shader::GetShaderCode(const char* shaderPath)
	{
		std::vector<std::string> shaderCode;
		std::ifstream shaderFile;
		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		std::stringstream shaderStream;

		try
		{
			shaderFile.open(shaderPath);

			shaderStream << shaderFile.rdbuf();

			shaderFile.close();
		}
		catch (std::ifstream::failure&)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_READ\n" << std::endl;
		}

		int i = 0;

		std::string line;

		while (getline(shaderStream, line))
		{
			if (line.rfind("#include", 0) == 0)
			{
				std::string includePath = "./Shaders/" + line.substr(10, line.size() - 11);
				shaderCode.push_back(GetShaderCode(includePath.c_str()));
			}
			else
			{
				shaderCode.push_back(line + '\n');
			}
			
			i++;
		}

		std::string finalShaderCode;

		for (i = 0; i < shaderCode.size(); i++)
		{
			finalShaderCode += shaderCode[i];
		}

		return finalShaderCode;
	}

	unsigned int Shader::CompileShader(const char* shaderCode, const int shaderType)
	{
		const unsigned int shader = glCreateShader(shaderType);
		glShaderSource(shader, 1, &shaderCode, nullptr);
		glCompileShader(shader);

		int success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			char infoLog[512];
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			Logging::Error(infoLog);
		}

		return shader;
	}


	void Shader::Use() const
	{
		glUseProgram(programID);
	}

	void Shader::SetBool(const std::string& name, const bool value) const
	{
		glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
	}

	void Shader::SetInt(const std::string& name, const int value) const
	{
		glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
	}

	void Shader::SetFloat(const std::string& name, const float value) const
	{
		glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
	}

	void Shader::SetUInt(const std::string& name, const unsigned int value) const
	{
		glUniform1ui(glGetUniformLocation(programID, name.c_str()), value);
	}

	void Shader::SetBool2(const std::string& name, const bool value, const bool value2) const
	{
		glUniform2i(glGetUniformLocation(programID, name.c_str()), value, value2);
	}

	void Shader::SetInt2(const std::string& name, const int value, const int value2) const
	{
		glUniform2i(glGetUniformLocation(programID, name.c_str()), value, value2);
	}

	void Shader::SetFloat2(const std::string& name, const float value, const float value2) const
	{
		glUniform2f(glGetUniformLocation(programID, name.c_str()), value, value2);
	}

	void Shader::SetUInt2(const std::string& name, const unsigned int value, const unsigned int value2) const
	{
		glUniform2ui(glGetUniformLocation(programID, name.c_str()), value, value2);
	}

	void Shader::SetBool3(const std::string& name, const bool value, const bool value2, const bool value3) const
	{
		glUniform3i(glGetUniformLocation(programID, name.c_str()), value, value2, value3);
	}

	void Shader::SetInt3(const std::string& name, const int value, const int value2, const int value3) const
	{
		glUniform3i(glGetUniformLocation(programID, name.c_str()), value, value2, value3);
	}

	void Shader::SetFloat3(const std::string& name, const float value, const float value2, const float value3) const
	{
		glUniform3f(glGetUniformLocation(programID, name.c_str()), value, value2, value3);
	}

	void Shader::SetUInt3(const std::string& name, const unsigned int value, const unsigned int value2,
		const unsigned int value3) const
	{
		glUniform3ui(glGetUniformLocation(programID, name.c_str()), value, value2, value3);
	}

	void Shader::SetBool4(const std::string& name, const bool value, const bool value2, const bool value3,
		const bool value4) const
	{
		glUniform4i(glGetUniformLocation(programID, name.c_str()), value, value2, value3, value4);
	}

	void Shader::SetInt4(const std::string& name, const int value, const int value2, const int value3,
		const int value4) const
	{
		glUniform4i(glGetUniformLocation(programID, name.c_str()), value, value2, value3, value4);
	}

	void Shader::SetFloat4(const std::string& name, const float value, const float value2, const float value3,
		const float value4) const
	{
		glUniform4f(glGetUniformLocation(programID, name.c_str()), value, value2, value3, value4);
	}

	void Shader::SetUInt4(const std::string& name, const unsigned int value, const unsigned int value2, const unsigned int value3,
		const unsigned int value4) const
	{
		glUniform4ui(glGetUniformLocation(programID, name.c_str()), value, value2, value3, value4);
	}

	void Shader::SetMatrix4x4(const std::string& name, const Math::Matrix4& mat4)
	{
		glUniformMatrix4fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, mat4.data.data());
	}
}