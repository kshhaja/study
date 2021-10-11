#pragma once

class Vector4
{
public:
	Vector4() :x(0), y(0), z(0), w(0) {};
	Vector4(const float*);
	Vector4(float x, float y, float z, float w);

	operator float* ();
	operator const float* () const;

	float& operator [] (unsigned int i);
	const float& operator [] (unsigned int i) const;

	Vector4& operator += (const Vector4&);
	Vector4& operator -= (const Vector4&);
	Vector4& operator *= (float);
	Vector4& operator /= (float);

	Vector4 operator + () const;
	Vector4 operator - () const;

	Vector4 operator + (const Vector4&) const;
	Vector4 operator - (const Vector4&) const;
	Vector4 operator * (float) const;
	Vector4 operator / (float) const;

	friend Vector4 operator * (float, const Vector4&);

	bool operator == (const Vector4&) const;
	bool operator != (const Vector4&) const;

	void  Set(float x, float y, float z, float w);
	float Length() const;
	float LengthSqr() const;
	bool  IsZero() const;
	Vector4& Normalize();

	float x, y, z, w;
};