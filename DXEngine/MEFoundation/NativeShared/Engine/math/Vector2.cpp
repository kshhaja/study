#include "Vector2.h"
#include "defines.h"
#include <math.h>

Vector2::Vector2(const float* v)
{
	x = v[0];
	y = v[1];
}

Vector2::Vector2(const Vector2& v)
{
	x = v.x;
	y = v.y;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::operator float* ()
{
	return &x;
}

Vector2::operator const float* () const
{
	return &x;
}

float& Vector2::operator [] (unsigned int i)
{
	return *(&x + i);
}

const float& Vector2::operator [] (unsigned int i) const
{
	return *(&x + i);
}

Vector2& Vector2::operator += (const Vector2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Vector2& Vector2::operator -= (const Vector2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

Vector2& Vector2::operator *= (float f)
{
	x *= f;
	y *= f;

	return *this;
}

Vector2& Vector2::operator /= (float f)
{
	if (EPSILON <= fabs(f))
	{
		x /= f;
		y /= f;
	}

	return *this;
}

Vector2 Vector2::operator + () const
{
	return Vector2(+x, +y);
}

Vector2 Vector2::operator - () const
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator + (const Vector2& v) const
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator - (const Vector2& v) const
{
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator * (float f) const
{
	return Vector2(x * f, y * f);
}

Vector2 Vector2::operator / (float f) const
{
	if (EPSILON <= fabs(f))
		return Vector2(x / f, y / f);
	return Vector2(x, y);
}

Vector2 operator *(float f, const Vector2& v)
{
	return Vector2(v.x * f, v.y * f);
}

bool Vector2::operator == (const Vector2& v) const
{
	return ((x == v.x) && (y == v.y));
}

bool Vector2::operator != (const Vector2& v) const
{
	return ((x != v.x) || (y != v.y));
}

void Vector2::Set(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector2::Length() const
{
	return sqrt(x*x + y*y);
}

float Vector2::LengthSqr() const
{
	return (x*x + y*y);
}

bool Vector2::IsZero() const
{
	return ((x == 0.0f) && (y == 0.0f));
}

Vector2& Vector2::Normalize()
{
	float m = Length();
	if (m > 0.0f)
		m = 1.0f / m;
	else
		m = 0.0f;

	x *= m;
	y *= m;

	return *this;
}

float Vector2::Dot(const Vector2& a, const Vector2& b)
{
	return (a.x * b.x) + (a.y * b.y);
}
