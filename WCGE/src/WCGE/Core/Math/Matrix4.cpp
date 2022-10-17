#include "Matrix4.hpp"
#include "Util.hpp"
#include <stdexcept>
#include <sstream>

namespace WCGE::Math
{
	const Matrix4 Matrix4::zero = Matrix4(0);
	const Matrix4 Matrix4::identity = Matrix4(1, 0, 0, 0,
											  0, 1, 0, 0,
											  0, 0, 1, 0,
											  0, 0, 0, 1);

	Matrix4::Matrix4() : Matrix4(0) {}

	Matrix4::Matrix4(float value)
	{
		for(int i = 0; i < 16; i++)
		{
			data[i] = value;
		}
	}

	Matrix4::Matrix4(const Matrix4& other)
	{
		for(int i = 0; i < 16; i++)
		{
			data[i] = other.data[i];
		}
	}

	Matrix4::Matrix4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
	{
		data[0] = m00;
		data[1] = m01;
		data[2] = m02;
		data[3] = m03;
		data[4] = m10;
		data[5] = m11;
		data[6] = m12;
		data[7] = m13;
		data[8] = m20;
		data[9] = m21;
		data[10] = m22;
		data[11] = m23;
		data[12] = m30;
		data[13] = m31;
		data[14] = m32;
		data[15] = m33;
	}

	Matrix4& Matrix4::operator=(const Matrix4& other)
	{
		for(int i = 0; i < 16; i++)
		{
			data[i] = other.data[i];
		}
		return *this;
	}

	float Matrix4::operator[](int i) const
	{
		if(i < 0 || i > 15) throw std::out_of_range("Matrix4[] index out of range!");
		return data[i];
	}

	bool Matrix4::operator==(const Matrix4& other) const
	{
		for(int i = 0; i < 16; i++)
		{
			if(data[i] != other.data[i]) return false;
		}
		return true;
	}

	bool Matrix4::operator!=(const Matrix4& other) const
	{
		return !(*this == other);
	}

	Matrix4 Matrix4::operator+(const Matrix4& other) const
	{
		Matrix4 mat4;
		for(int i = 0; i < 16; i++)
		{
			mat4.data[i] = data[i] + other.data[i];
		}
		return mat4;
	}

	Matrix4& Matrix4::operator+=(const Matrix4& other)
	{
		*this = *this + other;
		return *this;
	}

	Matrix4 Matrix4::operator-(const Matrix4& other) const
	{
		Matrix4 mat4;
		for(int i = 0; i < 16; i++)
		{
			mat4.data[i] = data[i] - other.data[i];
		}
		return mat4;
	}

	Matrix4& Matrix4::operator-=(const Matrix4& other)
	{
		*this = *this - other;
		return *this;
	}

	Matrix4 Matrix4::operator*(const Matrix4& other) const
	{
		Matrix4 mat4;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				for(int k = 0; k < 4; k++)
				{
					mat4.row_col[i][j] += row_col[i][k] * other.row_col[k][j];
				}
			}
		}
		return mat4;
	}

	Matrix4& Matrix4::operator*=(const Matrix4& other)
	{
		*this = *this * other;
		return *this;
	}

	Matrix4 Matrix4::operator*(float scalar) const
	{
		Matrix4 mat4;
		for(int i = 0; i < 16; i++)
		{
			mat4.data[i] = data[i] * scalar;
		}
		return mat4;
	}

	Matrix4& Matrix4::operator*=(float scalar)
	{
		*this = *this * scalar;
		return *this;
	}

	float Matrix4::Determinant() const
	{
		float m00 = data[5] * data[10] * data[15] - data[5] * data[11] * data[14] -
			data[9] * data[6] * data[15] + data[9] * data[7] * data[14] +
			data[13] * data[6] * data[11] - data[13] * data[7] * data[10];

		float m10 = -data[4] * data[10] * data[15] + data[4] * data[11] * data[14] +
			data[8] * data[6] * data[15] - data[8] * data[7] * data[14] -
			data[12] * data[6] * data[11] + data[12] * data[7] * data[10];

		float m20 = data[4] * data[9] * data[15] - data[4] * data[11] * data[13] -
			data[8] * data[5] * data[15] + data[8] * data[7] * data[13] +
			data[12] * data[5] * data[11] - data[12] * data[7] * data[9];

		float m30 = -data[4] * data[9] * data[14] + data[4] * data[10] * data[13] +
			data[8] * data[5] * data[14] - data[8] * data[6] * data[13] -
			data[12] * data[5] * data[10] + data[12] * data[6] * data[9];

		return data[0] * m00 + data[1] * m10 + data[2] * m20 + data[3] * m30;
	}

	Matrix4 Matrix4::Inverse() const
	{
		float m00 = data[5] * data[10] * data[15] - data[5] * data[11] * data[14] -
			data[9] * data[6] * data[15] + data[9] * data[7] * data[14] +
			data[13] * data[6] * data[11] - data[13] * data[7] * data[10];

		float m10 = -data[4] * data[10] * data[15] + data[4] * data[11] * data[14] +
			data[8] * data[6] * data[15] - data[8] * data[7] * data[14] -
			data[12] * data[6] * data[11] + data[12] * data[7] * data[10];

		float m20 = data[4] * data[9] * data[15] - data[4] * data[11] * data[13] -
			data[8] * data[5] * data[15] + data[8] * data[7] * data[13] +
			data[12] * data[5] * data[11] - data[12] * data[7] * data[9];

		float m30 = -data[4] * data[9] * data[14] + data[4] * data[10] * data[13] +
			data[8] * data[5] * data[14] - data[8] * data[6] * data[13] -
			data[12] * data[5] * data[10] + data[12] * data[6] * data[9];

		float m01 = -data[1] * data[10] * data[15] + data[1] * data[11] * data[14] +
			data[9] * data[2] * data[15] - data[9] * data[3] * data[14] -
			data[13] * data[2] * data[11] + data[13] * data[3] * data[10];

		float m11 = data[0] * data[10] * data[15] - data[0] * data[11] * data[14] -
			data[8] * data[2] * data[15] + data[8] * data[3] * data[14] +
			data[12] * data[2] * data[11] - data[12] * data[3] * data[10];

		float m21 = -data[0] * data[9] * data[15] + data[0] * data[11] * data[13] +
			data[8] * data[1] * data[15] - data[8] * data[3] * data[13] -
			data[12] * data[1] * data[11] + data[12] * data[3] * data[9];

		float m31 = data[0] * data[9] * data[14] - data[0] * data[10] * data[13] -
			data[8] * data[1] * data[14] + data[8] * data[2] * data[13] +
			data[12] * data[1] * data[10] - data[12] * data[2] * data[9];

		float m02 = data[1] * data[6] * data[15] - data[1] * data[7] * data[14] -
			data[5] * data[2] * data[15] + data[5] * data[3] * data[14] +
			data[13] * data[2] * data[7] - data[13] * data[3] * data[6];

		float m12 = -data[0] * data[6] * data[15] + data[0] * data[7] * data[14] +
			data[4] * data[2] * data[15] - data[4] * data[3] * data[14] -
			data[12] * data[2] * data[7] + data[12] * data[3] * data[6];

		float m22 = data[0] * data[5] * data[15] - data[0] * data[7] * data[13] -
			data[4] * data[1] * data[15] + data[4] * data[3] * data[13] +
			data[12] * data[1] * data[7] - data[12] * data[3] * data[5];

		float m32 = -data[0] * data[5] * data[14] + data[0] * data[6] * data[13] +
			data[4] * data[1] * data[14] - data[4] * data[2] * data[13] -
			data[12] * data[1] * data[6] + data[12] * data[2] * data[5];

		float m03 = -data[1] * data[6] * data[11] + data[1] * data[7] * data[10] +
			data[5] * data[2] * data[11] - data[5] * data[3] * data[10] -
			data[9] * data[2] * data[7] + data[9] * data[3] * data[6];

		float m13 = data[0] * data[6] * data[11] - data[0] * data[7] * data[10] -
			data[4] * data[2] * data[11] + data[4] * data[3] * data[10] +
			data[8] * data[2] * data[7] - data[8] * data[3] * data[6];

		float m23 = -data[0] * data[5] * data[11] + data[0] * data[7] * data[9] +
			data[4] * data[1] * data[11] - data[4] * data[3] * data[9] -
			data[8] * data[1] * data[7] + data[8] * data[3] * data[5];

		float m33 = data[0] * data[5] * data[10] - data[0] * data[6] * data[9] -
			data[4] * data[1] * data[10] + data[4] * data[2] * data[9] +
			data[8] * data[1] * data[6] - data[8] * data[2] * data[5];

		float det = data[0] * m00 + data[1] * m10 + data[2] * m20 + data[3] * m30;

		if(det == 0)
		{
			throw std::out_of_range{
				"Matrix4 - Cannot do inverse when the determinant is zero."};
		}

		Matrix4 ret{m00, m01, m02, m03, m10, m11, m12, m13,
					m20, m21, m22, m23, m30, m31, m32, m33};

		return ret * (1.0f / det);
	}

	Matrix4 Matrix4::Transpose() const
	{
		Matrix4 mat4(*this);
		std::swap(mat4.data[1], mat4.data[4]);
		std::swap(mat4.data[2], mat4.data[8]);
		std::swap(mat4.data[3], mat4.data[12]);
		std::swap(mat4.data[6], mat4.data[9]);
		std::swap(mat4.data[7], mat4.data[13]);
		std::swap(mat4.data[11], mat4.data[14]);
		return mat4;
	}

	bool Matrix4::IsIdentity() const
	{
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(data[(static_cast<std::array<float, 16Ui64>::size_type>(i) << 2) + j] != static_cast<float>(i == j) || data[(static_cast<std::array<float, 16Ui64>::size_type>(j) << 2) + i] != static_cast<float>(i == j))
				{
					return false;
				}
			}
		}
		return true;
	}

	bool Matrix4::IsZero() const
	{
		for(int i = 0; i < 16; i++)
		{
			if(data[i] != 0) return false;
		}
		return true;
	}

	Matrix4 Matrix4::Translate(const Vector3& translation)
	{
		return Matrix4(1, 0, 0, translation.x,
					   0, 1, 0, translation.y,
					   0, 0, 1, translation.z,
					   0, 0, 0, 1);
	}

	Matrix4 RotateX(float value)
	{
		float cos = Cos(value);
		float sin = Sin(value);
		return Matrix4(1, 0, 0, 0,
					   0, cos, sin, 0,
					   0, -sin, cos, 0,
					   0, 0, 0, 1);
	}

	Matrix4 RotateY(float value)
	{
		float cos = Cos(value);
		float sin = Sin(value);
		return Matrix4(cos, 0, -sin, 0,
					   0, 1, 0, 0,
					   sin, 0, cos, 0,
					   0, 0, 0, 1);
	}

	Matrix4 RotateZ(float value)
	{
		float cos = Cos(value);
		float sin = Sin(value);
		return Matrix4(cos, sin, 0, 0,
					   -sin, cos, 0, 0,
					   0, 0, 1, 0,
					   0, 0, 0, 1);
	}

	Matrix4 Matrix4::Rotate(const Vector3& rotation)
	{
		return RotateX(rotation.x) * RotateY(rotation.y) * RotateZ(rotation.z);
	}

	Matrix4 Matrix4::Scale(const Vector3& scale)
	{
		return Matrix4(scale.x, 0, 0, 0,
					   0, scale.y, 0, 0,
					   0, 0, scale.z, 0,
					   0, 0, 0, 1);
	}

	Matrix4 Matrix4::Transform(const Vector3& translation, const Vector3& rotation, const Vector3& scale)
	{
		return Translate(translation) * Rotate(rotation) * Scale(scale);
	}

	std::string Matrix4::ToString()
	{
		std::stringstream ss;
		ss << data[0] << ' ' << data[1] << ' ' << data[2] << ' ' << data[3] << '\n' << data[4] << ' ' << data[5] << ' ' << data[6] << ' ' << data[7] << '\n' << data[8] << ' ' << data[9] << ' ' << data[10] << ' ' << data[11] << '\n' << data[12] << ' ' << data[13] << ' ' << data[14] << ' ' << data[15] << '\n';
		return ss.str();
	}
}