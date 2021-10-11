#pragma once
#include <math.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "defines.h"

class Matrix4
{
public:
	Matrix4();
	Matrix4(bool identityMatrix);
	Matrix4(const float* m);
	Matrix4(
		float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34,
		float _41, float _42, float _43, float _44);

	float& operator () (unsigned int row, unsigned int col);
	float operator() (unsigned int row, unsigned int col) const;

	operator float* ();
	operator const float* () const;

	Matrix4& operator += (const Matrix4&);
	Matrix4& operator -= (const Matrix4&);
	Matrix4& operator *= (const Matrix4&);
	Matrix4& operator *= (float);
	Matrix4& operator /= (float);

	Matrix4 operator + () const;
	Matrix4 operator - () const;

	Matrix4 operator + (const Matrix4&) const;
	Matrix4 operator - (const Matrix4&) const;
	Matrix4 operator * (const Matrix4&) const;
	Matrix4 operator * (float) const;
	Matrix4 operator / (float) const;

	friend Matrix4 operator * (float, const Matrix4&);
	inline const Vector4 operator * (const Vector4& v) const
	{
		Vector4 t = Vector4(0.0f, 0.0f, 0.0f, 0.0f);

		t.x = v.x * _11 + v.y * _21 + v.z * _31 + v.w * _41;
		t.y = v.x * _12 + v.y * _22 + v.z * _32 + v.w * _42;
		t.z = v.x * _13 + v.y * _23 + v.z * _33 + v.w * _43;
		t.w = v.x * _14 + v.y * _24 + v.z * _34 + v.w * _44;

		return t;
	}

	const Vector3 operator* (const Vector3& v) const;
	const Vector2 operator* (const Vector2& v) const;

	bool operator == (const Matrix4&) const;
	bool operator != (const Matrix4&) const;

	void Set(
		float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34,
		float _41, float _42, float _43, float _44);
	void Set(float* entries);

	float* Get();

	Matrix4& Zero();
	Matrix4& Identity();
	Matrix4& Transpose();
	bool Invert();

	float ScaleX() const;
	float ScaleY() const;
	float ScaleZ() const;

	union
	{
		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4];
	};

	// statics
	static Matrix4 MatrixIdentity()
	{
		return Matrix4(true);
	}

	inline static void Multiply(const Matrix4& a, const Matrix4& b, Matrix4& ret)
	{
		for (int k = 0; k < 4; ++k)
		{
			for (int i = 0; i < 4; ++i)
			{
				ret.m[i][k] = a.m[0][k] * b.m[i][0] + a.m[1][k] * b.m[i][1] + a.m[2][k] * b.m[i][2] + a.m[3][k] * b.m[i][3];
			}
		}
	}

	static Matrix4 Translate(float x, float y, float z)
	{
		Matrix4 ret;

		ret.Identity();
		ret._41 = x;
		ret._42 = y;
		ret._43 = z;
		
		return ret;
	}

	static Matrix4 RotateX(float rad)
	{
		Matrix4 ret;
		double sinA, cosA;

		sinA = sin(rad);
		cosA = cos(rad);

		ret._11 = 1.0f; ret._21 = 0.0f; ret._31 = 0.0f; ret._41 = 0.0f;
		ret._12 = 0.0f; ret._22 = cosA; ret._32 = -sinA; ret._42 = 0.0f;
		ret._13 = 0.0f; ret._23 = sinA; ret._33 = cosA; ret._43 = 0.0f;
		ret._14 = 0.0f; ret._24 = 0.0f; ret._34 = 0.0f; ret._44 = 1.0f;

		return ret;
	}

	static Matrix4 RotateY(float rad)
	{
		Matrix4 ret;
		double sinA, cosA;

		sinA = sin(rad);
		cosA = cos(rad);

		ret._11 = cosA; ret._21 = 0.0f; ret._31 = sinA; ret._41 = 0.0f;
		ret._12 = 0.0f; ret._22 = 1.0f; ret._32 = 0.0f; ret._42 = 0.0f;
		ret._13 = -sinA; ret._23 = 0.0f; ret._33 = cosA; ret._43 = 0.0f;
		ret._14 = 0.0f; ret._24 = 0.0f; ret._34 = 0.0f; ret._44 = 1.0f;
	}

	static Matrix4 RotateZ(float rad)
	{
		Matrix4 ret;
		float sinA, cosA;

		sinA = sin(rad);
		cosA = cos(rad);

		ret._11 = cosA; ret._21 = -sinA; ret._31 = 0.0f; ret._41 = 0.0f;
		ret._12 = sinA; ret._22 = cosA; ret._32 = 0.0f; ret._42 = 0.0f;
		ret._13 = 0.0f; ret._23 = 0.0f; ret._33 = 1.0f; ret._43 = 0.0f;
		ret._14 = 0.0f; ret._24 = 0.0f; ret._34 = 0.0f; ret._44 = 1.0f;

		return ret;
	}

	static Matrix4 Rotate(float ax, float ay, float az, float rad)
	{
		Matrix4 ret;
		float sinA, cosA, invCosA;
		float x = 0.0f, y = 0.0f, z = 0.0f;

		sinA = sin(rad);
		cosA = cos(rad);
		invCosA = 1.0f - cosA;

		float len = sqrt(ax * ax + ay * ay + az * az);

		if (len >= EPSILON)
		{
			x = ax / len;
			y = ay / len;
			z = az / len;
		}

		ret._11 = (invCosA * x * x) + (cosA);
		ret._12 = (invCosA * x * y) - (sinA * z);
		ret._13 = (invCosA * x * z) + (sinA * y);
		ret._14 = 0.0f;

		ret._21 = (invCosA * x * y) + (sinA * z);
		ret._22 = (invCosA * y * y) + (cosA);
		ret._23 = (invCosA * y * z) - (sinA * x);
		ret._24 = 0.0f;

		ret._31 = (invCosA * x * z) - (sinA * y);
		ret._32 = (invCosA * y * z) + (sinA * x);
		ret._33 = (invCosA * z * z) + (cosA);
		ret._34 = 0.0f;

		ret._41 = 0.0f;
		ret._42 = 0.0f;
		ret._43 = 0.0f;
		ret._44 = 1.0f;

		return ret;
	}

	static Matrix4 Scale(float x, float y, float z, float w)
	{
		Matrix4 ret;

		ret.Identity();
		ret._11 = x;
		ret._22 = y;
		ret._33 = z;
		ret._44 = w;

		return ret;
	}

	static Matrix4 LookAt(const Vector3& pos, const Vector3& up, const Vector3& target)
	{
		Matrix4 ret;

		Vector3 f = target - pos;
		f.Normalize();

		Vector3 upNorm = up;
		upNorm.Normalize();

		Vector3 s = Vector3::Cross(f, upNorm);
		Vector3 u = Vector3::Cross(s, f);

		ret._11 = s.x; ret._21 = s.y; ret._31 = s.z; ret._41 = -pos.x;
		ret._12 = u.x; ret._22 = u.y; ret._32 = u.z; ret._42 = -pos.y;
		ret._13 = -f.x; ret._23 = -f.y; ret._33 = -f.z; ret._43 = -pos.z;
		ret._14 = 0.0f; ret._24 = 0.0f; ret._34 = 0.0f; ret._44 = 1.0f;

		return ret;
	}
	
	// 더 해 볼것.
	static Matrix4 Perspective();
	static Matrix4 Ortho();
};