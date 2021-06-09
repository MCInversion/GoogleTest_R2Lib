#include "Vector2.h"
#include "Matrix2.h"

#include <cmath>

bool Vector2::operator==(const Vector2& vec) const
{
	if (m_Coords[X_COORD] != vec.m_Coords[X_COORD])
		return false;

	return (m_Coords[Y_COORD] == vec.m_Coords[Y_COORD]);
}

bool Vector2::EqualsWithTolerance(const Vector2& vec) const
{
	const double epsilon = COORD_TOLERANCE;
	if (std::fabs(m_Coords[X_COORD] - vec.m_Coords[X_COORD]) > epsilon)
		return false;

	return (std::fabs(m_Coords[Y_COORD] - vec.m_Coords[Y_COORD]) < epsilon);
}

bool Vector2::operator!=(const Vector2& vec) const
{
	if (*this == vec)
		return false;
	else
		return true;
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	m_Coords[X_COORD] += vec.m_Coords[X_COORD];
	m_Coords[Y_COORD] += vec.m_Coords[Y_COORD];
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
	m_Coords[X_COORD] -= vec.m_Coords[X_COORD];
	m_Coords[Y_COORD] -= vec.m_Coords[Y_COORD];
	return *this;
}

Vector2& Vector2::operator*=(const Matrix2& matrix)
{
	return Set(
		matrix.Elem(e2x2_MatrixCoordID::MAT2_11) * m_Coords[X_COORD] + matrix.Elem(e2x2_MatrixCoordID::MAT2_12) * m_Coords[Y_COORD],
		matrix.Elem(e2x2_MatrixCoordID::MAT2_21) * m_Coords[X_COORD] + matrix.Elem(e2x2_MatrixCoordID::MAT2_22) * m_Coords[Y_COORD]
	);
}

Vector2& Vector2::operator*=(const double& scalar)
{
	m_Coords[0] *= scalar;
	m_Coords[1] *= scalar;

	return *this;
}

Vector2 Vector2::operator*(const double& scalar) const
{
	return Vector2(
		m_Coords[0] * scalar,
		m_Coords[1] * scalar);
}

Vector2 Vector2::operator*(const Matrix2& matrix) const
{
	Vector2 result(*this);
	result *= matrix;
	return result;
}


Vector2 Vector2::operator/(const double& scalar) const
{
	return Vector2(
		m_Coords[0] / scalar,
		m_Coords[1] / scalar);
}

Vector2& Vector2::operator/=(const double& scalar)
{
	m_Coords[0] /= scalar;
	m_Coords[1] /= scalar;

	return *this;
}

Vector2& Vector2::operator=(const Vector2& vec)
{
	if (this == &vec)
		return *this;

	Set(vec);
	return *this;
}

Vector2 Vector2::operator+(const Vector2& vec) const
{
	Vector2 result(*this);
	result += vec;
	return result;
}

Vector2 Vector2::operator-(const Vector2& vec) const
{
	Vector2 result(*this);
	result -= vec;
	return result;
}

double Vector2::GetLengthSquared() const
{
	return (
		m_Coords[X_COORD] * m_Coords[X_COORD] +
		m_Coords[Y_COORD] * m_Coords[Y_COORD]);
}

double Vector2::GetLength() const
{
	double dx2 = m_Coords[X_COORD] * m_Coords[X_COORD];
	double dy2 = m_Coords[Y_COORD] * m_Coords[Y_COORD];
	return sqrt(dx2 + dy2);
}

Vector2& Vector2::Normalize()
{
	if (IsZero())
	{ // Vector2::Normalize: Attempting to normalize a zero-length vector!
		return *this;
	}

	double oldLength = GetLength();

	Set(
		m_Coords[X_COORD] / oldLength,
		m_Coords[Y_COORD] / oldLength
	);

	return *this;
}

double Vector2::DotProduct(const Vector2& vec) const
{
	return m_Coords[X_COORD] * vec.m_Coords[X_COORD]
		 + m_Coords[Y_COORD] * vec.m_Coords[Y_COORD];
}

double Vector2::CrossProduct(const Vector2& vec) const
{
	return m_Coords[X_COORD] * vec.m_Coords[Y_COORD] - m_Coords[Y_COORD] * vec.m_Coords[X_COORD];
}

Vector2& Vector2::Negate()
{
	m_Coords[X_COORD] = -m_Coords[X_COORD];
	m_Coords[Y_COORD] = -m_Coords[Y_COORD];

	return *this;
}

Vector2& Vector2::DirectProduct(const Vector2& vec)
{
	m_Coords[X_COORD] *= vec.m_Coords[X_COORD];
	m_Coords[Y_COORD] *= vec.m_Coords[Y_COORD];
	return *this;
}

Vector2 Vector2::DirectProduct(const Vector2& vec) const
{
	Vector2 result(*this);
	result.m_Coords[X_COORD] *= vec.m_Coords[X_COORD];
	result.m_Coords[Y_COORD] *= vec.m_Coords[Y_COORD];
	return result;
}

Vector2 Vector2::Project(const Vector2& vec) const
{
	Vector2 result;
	if (IsZero())
	{ // Vector2::Project: Attempting to project onto a zero-length vector!
		return *this;
	}

	result = (*this) * (vec.DotProduct(*this) / DotProduct(*this));
	return *this;
}

Vector2& Vector2::ApplyAngle(const double& angle)
{
	const double c = cos(angle);
	const double s = sin(angle);
	return Set(
		c * m_Coords[X_COORD] - s * m_Coords[Y_COORD],
		s * m_Coords[X_COORD] + c * m_Coords[Y_COORD]
	);
}
