#include "Matrix3.hpp"
#include <stdexcept>
#include <algorithm>

namespace WCGE::Math
{
	const Matrix3 Matrix3::zero = Matrix3();
	const Matrix3 Matrix3::identity = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);

	Matrix3::Matrix3() : data{0, 0, 0, 0, 0, 0, 0, 0, 0} {}

	Matrix3::Matrix3(float value) : data{value, value, value, value, value, value, value, value, value} {}

	Matrix3::Matrix3(const Matrix3& other) : data{other.data} {}

	Matrix3::Matrix3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) : data{m00, m01, m02, m10, m11, m12, m20, m21, m22} {}

	Matrix3& Matrix3::operator=(const Matrix3& other)
	{
		data = other.data;
		return *this;
	}

	float Matrix3::operator[](int i) const
	{
		if(i < 0 || i > 9)
		{
			throw std::out_of_range("Vector2[] - Index out of range.");
		}
		return data[i];
	}

	bool Matrix3::operator==(const Matrix3& other)
	{
		for(int i = 0; i < 9; i++)
		{
			if(data[i] != other.data[i]) return false;
		}
		return true;
	}
	
	bool Matrix3::operator!=(const Matrix3& other)
	{
		return !(other == *this);
	}
	
	Matrix3 Matrix3::operator+(const Matrix3& other) const
	{
		Matrix3 mat3;
		for(int i = 0; i < 9; i++)
		{
			mat3.data[i] = data[i] + other.data[i];
		}
		return mat3;
	}

	Matrix3& Matrix3::operator+=(const Matrix3& other)
	{
		*this = *this + other;
		return *this;
	}

	Matrix3 Matrix3::operator-(const Matrix3& other) const
	{
		Matrix3 mat3;
		for(int i = 0; i < 9; i++)
		{
			mat3.data[i] = data[i] - other.data[i];
		}
		return mat3;
	}

	Matrix3& Matrix3::operator-=(const Matrix3& other)
	{
		*this = *this - other;
		return *this;
	}

	Matrix3 Matrix3::operator*(const Matrix3& other) const
	{
		Matrix3 mat3;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				for(int k = 0; k < 3; k++)
				{
					mat3.row_col[i][j] = row_col[i][k] * other.row_col[k][j];
				}
			}
		}
		return mat3;
	}

	Matrix3& Matrix3::operator*=(const Matrix3& other)
	{
		*this = *this * other;
		return *this;
	}

	Matrix3 Matrix3::operator*(float scalar) const
	{
		return *this * Matrix3(scalar);
	}

	Matrix3& Matrix3::operator*=(float scalar)
	{
		*this = *this * scalar;
		return *this;
	}

	float Matrix3::Determinant() const
	{
		return (data[0] * ((data[4] * data[8]) - (data[5] * data[7]))) - (data[1] * ((data[3] * data[8]) - (data[5] * data[6]))) + (data[2] * ((data[3] * data[7]) - (data[4] * data[6])));
	}
	
	Matrix3 Matrix3::Transpose() const
	{
		Matrix3 mat3(*this);

		std::swap(mat3.data[1], mat3.data[3]);
		std::swap(mat3.data[2], mat3.data[6]);
		std::swap(mat3.data[5], mat3.data[7]);

		return mat3;
	}
	
	bool Matrix3::IsIdentity() const
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(row_col[i][j] != static_cast<float>(i == j) || row_col[j][i] != static_cast<float>(i == j))
				{
					return false;
				}
			}
		}

		return true;
	}
	
	bool Matrix3::IsZero() const
	{
		for(int i = 0; i < 9; i++)
		{
			if(data[i] != 0) return false;
		}

		return true;
	}
}