#pragma once

#include "VectorUtils.h"

// forward declarations:
class Matrix2;

class Vector2
{
public:
    Vector2() = default;

	Vector2(const Vector2& vec)
	{
		Set(vec);
	}

	Vector2(const double& x, const double& y)
	{
		Set(x, y);
	}

	bool operator==(const Vector2& vec) const;

	bool EqualsWithTolerance(const Vector2& vec) const;

	bool operator!=(const Vector2& vec) const;

	Vector2& operator=(const Vector2& vec);

	Vector2& operator+=(const Vector2& vec);

	Vector2& operator-=(const Vector2& vec);

	Vector2 operator+(const Vector2& vec) const;

	Vector2 operator-(const Vector2& vec) const;

	Vector2 operator*(const double& scalar) const;

	Vector2& operator*=(const double& scalar);

	Vector2 operator/(const double& scalar) const;

	Vector2& operator/=(const double& scalar);

	Vector2& operator*=(const Matrix2& matrix);

	Vector2 operator*(const Matrix2& matrix) const;

	const double& X() const
	{
		return m_Coords[X_COORD];
	}

	const double& Y() const
	{
		return m_Coords[Y_COORD];
	}

	double& X()
	{
		return m_Coords[X_COORD];
	}

	double& Y()
	{
		return m_Coords[Y_COORD];
	}

	Vector2& Set(const Vector2& vec)
	{
		return Set(vec.m_Coords[X_COORD], vec.m_Coords[Y_COORD]);
	}

	Vector2& Set(const double& x, const double& y)
	{
		m_Coords[X_COORD] = x;
		m_Coords[Y_COORD] = y;
		return *this;
	}

	bool IsZero() const
	{
		return (m_Coords[X_COORD] == 0.)
			&& (m_Coords[Y_COORD] == 0.)
			? true : false;
	}

	double GetLengthSquared() const;

	double GetLength() const;

	Vector2& Normalize();

	double DotProduct(const Vector2& vec) const;

	double CrossProduct(const Vector2& vec) const;

	Vector2& Negate();

	Vector2& DirectProduct(const Vector2& vec);

	Vector2 DirectProduct(const Vector2& vec) const;

	Vector2 Project(const Vector2& vec) const;

	Vector2& ApplyAngle(const double& angle);

private:
	double m_Coords[GEOMETRY_DIMENSION2]{};
};