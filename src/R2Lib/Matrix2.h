#pragma once

#include  "VectorUtils.h"

// forward declarations:
class Vector2;

class Matrix2
{
public:
	Matrix2() = default;

	Matrix2(const Matrix2& mat)
	{
		Set(mat);
	}

	Matrix2(
		const double& m11, const double& m12,
		const double& m21, const double& m22)
	{
		Set(
			m11, m12,
			m21, m22
		);
	}

	bool operator==(const Matrix2& mat) const;

	bool EqualsWithTolerance(const Matrix2& mat) const;

	bool operator!=(const Matrix2& mat) const;

	Matrix2& operator=(const Matrix2& mat);

	Matrix2& operator+=(const Matrix2& mat);

	Matrix2& operator-=(const Matrix2& mat);

	Matrix2 operator+(const Matrix2& mat) const;

	Matrix2 operator-(const Matrix2& mat) const;

	Matrix2& operator*=(const Matrix2& mat);

	Matrix2& operator*=(Vector2& vec);

	Matrix2& Multiply(const double& scalar);

	Matrix2& operator*=(const double& scalar);

	Matrix2& Multiply(const Matrix2& mat);

	Matrix2& Premultiply(const Matrix2& mat);

	Matrix2 operator*(const Matrix2& mat) const;

	Matrix2& operator*(const double& scalar);

	Matrix2 operator*(const double& scalar) const;

	Matrix2& Set(
		const double& m11, const double& m12,
		const double& m21, const double& m22)
	{
		m_Coords[MAT2_11] = m11; m_Coords[MAT2_12] = m12;
		m_Coords[MAT2_21] = m21; m_Coords[MAT2_22] = m22;
		return *this;
	}

	Matrix2& SetToIdentity();

	Matrix2& Set(const Matrix2& mat)
	{
		return Set(
			mat.m_Coords[MAT2_11], mat.m_Coords[MAT2_12],
			mat.m_Coords[MAT2_21], mat.m_Coords[MAT2_22]
		);
	}

	double Elem(const e2x2_MatrixCoordID& index) const
	{
		return m_Coords[index];
	}

	bool IsIdentity() const;

	Matrix2& Transpose();

	Matrix2 Transpose() const;

	double Determinant() const;

	Matrix2& Inverse();

	Matrix2 Inverse() const;

private:

	double m_Coords[GEOMETRY_DIMENSION_2x2] = {
		1.0, 0.0,
		0.0, 1.0
	};
};