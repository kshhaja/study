#include "Vector4.h"
#include "defines.h"
#include <math.h>

Vector4::Vector4(const float* v)
{
    x = v[0];
    y = v[1];
    z = v[2];
    w = v[3];
}

Vector4::Vector4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vector4::operator float* ()
{
    return &x;
}

Vector4::operator const float* () const
{
    return &x;
}

float& Vector4::operator [] (unsigned int i)
{
    return *(&x + i);
}

const float& Vector4::operator [] (unsigned int i) const
{
    return *(&x + i);
}

Vector4& Vector4::operator += (const Vector4& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;

    return *this;
}

Vector4& Vector4::operator -= (const Vector4& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;

    return *this;
}

Vector4& Vector4::operator *= (float f)
{
    x *= f;
    y *= f;
    z *= f;
    w *= f;

    return *this;
}

Vector4& Vector4::operator /= (float f)
{
    if (EPSILON <= fabs(f))
    {
        x /= f;
        y /= f;
        z /= f;
        w /= f;
    }

    return *this;
}

Vector4 Vector4::operator + () const
{
    return Vector4(+x, +y, +z, +w);
}

Vector4 Vector4::operator - () const
{
    return Vector4(-x, -y, -z, -w);
}

Vector4 Vector4::operator + (const Vector4& v) const
{
    return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vector4 Vector4::operator - (const Vector4& v) const
{
    return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}

Vector4 Vector4::operator * (float f) const
{
    return Vector4(x * f, y * f, z * f, w * f);
}

Vector4 Vector4::operator / (float f) const
{
    if (EPSILON <= fabs(f))
        return Vector4(x / f, y / f, z / f, w / f);

    return Vector4(x, y, z, w);
}

Vector4 operator * (float f, const Vector4& v)
{
    return Vector4(f * v.x, f * v.y, f * v.z, f * v.w);
}

bool Vector4::operator == (const Vector4& v) const
{
    return ((x == v.x) && (y == v.y) && (z == v.z) && (w == v.w));
}

bool Vector4::operator != (const Vector4& v) const
{
    return ((x != v.x) || (y != v.y) || (z != v.z) || (w != v.w));
}

void Vector4::Set(float _x, float _y, float _z, float _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

float Vector4::Length() const
{
    return sqrt(x * x + y * y + z * z + w * w);
}

float Vector4::LengthSqr() const
{
    return (x * x + y * y + z * z + w * w);
}

bool Vector4::IsZero() const
{
    return ((x == 0.0f) && (y == 0.0f) && (z == 0.0f) && w == 0.0f);
}

Vector4& Vector4::Normalize()
{
    float m = Length();

    if (m > 0.0f) m = 1.0f / m;
    else m = 0.0f;

    x *= m;
    y *= m;
    z *= m;
    w *= m;

    return *this;
}

float Vector4::Dot(const Vector4& a, const Vector4& b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}