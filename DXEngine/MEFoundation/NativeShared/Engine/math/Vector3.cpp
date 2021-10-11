#include "Vector3.h"
#include "defines.h"
#include <memory>

Vector3::Vector3(const float* v)
{
    x = v[0];
    y = v[1];
    z = v[2];
}

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::operator float* ()
{
    return &x;
}
Vector3::operator const float* () const
{
    return &x;
}

float& Vector3::operator [] (unsigned int i)
{
    return *(&x + i);
}

const float& Vector3::operator [] (unsigned int i) const
{
    return *(&x + i);
}

Vector3& Vector3::operator += (const Vector3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

Vector3& Vector3::operator -= (const Vector3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}

Vector3& Vector3::operator *= (float f)
{
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

Vector3& Vector3::operator /= (float f)
{
    if (EPSILON <= fabs(f))
    {
        x /= f;
        y /= f;
        z /= f;
    }

    return *this;
}

Vector3 Vector3::operator + () const
{
    return Vector3(+x, +y, +z);
}

Vector3 Vector3::operator - () const
{
    return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator + (const Vector3& v) const
{
    return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator - (const Vector3& v) const
{
    return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator * (float f) const
{
    return Vector3(x * f, y * f, z * f);
}

Vector3 Vector3::operator / (float f) const
{
    if (EPSILON <= fabs(f))
        return Vector3(x / f, y / f, z / f);

    return Vector3(x, y, z);
}

Vector3 operator * (float f, const Vector3& v)
{
    return Vector3(f * v.x, f * v.y, f * v.z);
}

bool Vector3::operator == (const Vector3& v) const
{
    return memcmp(this, &v, sizeof(Vector3)) == 0;
}

bool Vector3::operator != (const Vector3& v) const
{
    return memcmp(this, &v, sizeof(Vector3)) != 0;
}

void Vector3::Set(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3::Length() const
{
    return sqrt(x * x + y * y + z * z);
}

float Vector3::LengthSqr() const
{
    return (x * x + y * y + z * z);
}

bool Vector3::IsZero() const
{
    return ((x == 0.0f) && (y == 0.0f) && (z == 0.0f));
}

Vector3& Vector3::Normalize()
{
    float m = Length();

    if (m > 0.0f) m = 1.0f / m;
    else m = 0.0f;

    x *= m;
    y *= m;
    z *= m;

    return *this;
}

float Vector3::Dot(const Vector3& a, const Vector3& b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
{
    return Vector3(
        (a.y * b.z) - (a.z * b.y), 
        (a.z * b.x) - (a.x * b.z), 
        (a.x * b.y) - (a.y * b.x)
    );
}
