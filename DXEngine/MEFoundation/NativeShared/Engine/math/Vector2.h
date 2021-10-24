#pragma once

class Vector2
{
public:
	Vector2() : x(0), y(0)
	{
	}

	Vector2(const float*);

	Vector2(float x, float y);

	Vector2(const class Vector2&);

	operator float* ();
	operator const float* () const;

	float& operator [] (unsigned int i);
	const float& operator [] (unsigned int i) const;

	Vector2& operator += (const Vector2&);
	Vector2& operator -= (const Vector2&);
	Vector2& operator *= (float);
	Vector2& operator /= (float);

	Vector2 operator + () const;
	Vector2 operator - () const;

	Vector2 operator + (const Vector2&) const;
	Vector2 operator - (const Vector2&) const;
	Vector2 operator * (float) const;
	Vector2 operator / (float) const;

	friend Vector2 operator * (float, const Vector2&);

	bool operator == (const Vector2&) const;
	bool operator != (const Vector2&) const;

	void Set(float x, float y);
	float Length() const;
	float LengthSqr() const;
	bool IsZero() const;
	Vector2& Normalize();

	static float Dot(const Vector2& a, const Vector2& b);

	float x, y;
};