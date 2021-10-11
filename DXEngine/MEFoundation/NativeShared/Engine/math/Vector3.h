#pragma once

class Vector3
{
public:
	Vector3() : x(0), y(0), z(0)
	{

	}

	Vector3(const float*);
	Vector3(float x, float y, float z);

	operator float* ();
	operator const float* () const;

	float& operator [] (unsigned int i);
	const float& operator [] (unsigned int i) const;

	Vector3& operator += (const Vector3&);
	Vector3& operator -= (const Vector3&);
	Vector3& operator *= (float);
	Vector3& operator /= (float);

	Vector3 operator + () const;
	Vector3 operator - () const;

	Vector3 operator + (const Vector3&) const;
	Vector3 operator - (const Vector3&) const;
	Vector3 operator * (float) const;
	Vector3 operator / (float) const;

	friend Vector3 operator * (float, const class Vector3&);

	bool operator == (const Vector3&) const;
	bool operator != (const Vector3&) const;

	void Set(float x, float y, float z);
	float Length() const;
	float LengthSqr() const;
	bool IsZero() const;
	Vector3& Normalize();

	static float Dot(const Vector3& a, const Vector3& b);
	static Vector3 Cross(const Vector3& a, const Vector3& b);

	float x, y, z;
};