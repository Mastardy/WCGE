#pragma once

#include "../Core.hpp"

#include <string>

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

		void SetBool(const std::string& name, const bool value) const;
		void SetInt(const std::string& name, const int value) const;
		void SetFloat(const std::string& name, const float value) const;
		void SetUInt(const std::string& name, const unsigned int value) const;

		void SetBool2(const std::string& name, const bool value, const bool value2) const;
		void SetInt2(const std::string& name, const int value, const int value2) const;
		void SetFloat2(const std::string& name, const float value, const float value2) const;
		void SetUInt2(const std::string& name, const unsigned int value, const unsigned int value2) const;

		void SetBool3(const std::string& name, const bool value, const bool value2, const bool value3) const;
		void SetInt3(const std::string& name, const int value, const int value2, const int value3) const;
		void SetFloat3(const std::string& name, const float value, const float value2, const float value3) const;
		void SetUInt3(const std::string& name, const unsigned int value, const unsigned int value2, const unsigned int value3) const;

		void SetBool4(const std::string& name, const bool value, const bool value2, const bool value3, const bool value4) const;
		void SetInt4(const std::string& name, const int value, const int value2, const int value3, const int value4) const;
		void SetFloat4(const std::string& name, const float value, const float value2, const float value3, const float value4) const;
		void SetUInt4(const std::string& name, const unsigned int value, const unsigned int value2, const unsigned int value3, const unsigned int value4) const;

	private:
		unsigned int programID;
	};
}