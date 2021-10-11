#include "Matrix.h"
#include <memory>

Matrix4::Matrix4()
{
    memset(&_11, 0, sizeof(float) * 16);
    _11 = _22 = _33 = _44 = 1.0f;
}

Matrix4::Matrix4(bool indentityMatrix)
{
    if (indentityMatrix)
    {
        memset(&_11, 0, sizeof(float) * 16);
        _11 = _22 = _33 = _44 = 1.0f;
    }
}

Matrix4::Matrix4(const float* _m)
{
    float* p = m[0];
    for (int i = 0; i < 16; i++) *(p + i) = _m[i];
}

Matrix4::Matrix4(float __11, float __12, float __13, float __14,
    float __21, float __22, float __23, float __24,
    float __31, float __32, float __33, float __34,
    float __41, float __42, float __43, float __44)
{
    _11 = __11;	_12 = __12;	_13 = __13;	_14 = __14;
    _21 = __21;	_22 = __22;	_23 = __23;	_24 = __24;
    _31 = __31;	_32 = __32;	_33 = __33;	_34 = __34;
    _41 = __41;	_42 = __42;	_43 = __43;	_44 = __44;
}
Matrix4::operator float* ()
{
    return &_11;
}

Matrix4::operator const float* () const
{
    return &_11;
}

Matrix4& Matrix4::operator += (const Matrix4& a)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            m[i][j] += a.m[i][j];

    return *this;
}

Matrix4& Matrix4::operator -= (const Matrix4& a)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            m[i][j] -= a.m[i][j];

    return *this;
}

Matrix4& Matrix4::operator *= (const Matrix4& a)
{
    Matrix4 t(false);
    Multiply(*this, a, t);
    *this = t;

    return *this;
}

Matrix4& Matrix4::operator *= (float f)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            m[i][j] *= f;

    return *this;
}

Matrix4& Matrix4::operator /= (float f)
{
    if (EPSILON <= fabs(f))
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                m[i][j] /= f;

    return *this;
}

Matrix4 Matrix4::operator + (const Matrix4& a) const
{
    return Matrix4(
        _11 + a._11, _12 + a._12, _13 + a._13, _14 + a._14,
        _21 + a._21, _22 + a._22, _23 + a._23, _24 + a._24,
        _31 + a._31, _32 + a._32, _33 + a._33, _34 + a._34,
        _41 + a._41, _42 + a._42, _43 + a._43, _44 + a._44);
}

Matrix4 Matrix4::operator - (const Matrix4& a) const
{
    return Matrix4(
        _11 - a._11, _12 - a._12, _13 - a._13, _14 - a._14,
        _21 - a._21, _22 - a._22, _23 - a._23, _24 - a._24,
        _31 - a._31, _32 - a._32, _33 - a._33, _34 - a._34,
        _41 - a._41, _42 - a._42, _43 - a._43, _44 - a._44);
}

Matrix4 Matrix4::operator * (const Matrix4& a) const
{
    Matrix4 ret(false);
    Multiply(*this, a, ret);

    return ret;
}

Matrix4 Matrix4::operator * (float f) const
{
    Matrix4 ret(*this);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            ret.m[i][j] *= f;

    return ret;
}

Matrix4 Matrix4::operator / (float f) const
{
    Matrix4 ret(*this);

    if (EPSILON <= fabs(f))
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                ret.m[i][j] /= f;

    return ret;
}

Matrix4 operator * (float f, const Matrix4& a)
{
    Matrix4 ret(a);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            ret.m[i][j] *= f;

    return ret;
}

bool Matrix4::operator == (const Matrix4& a) const
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (m[i][j] != a.m[i][j]) return 0;

    return 1;
}

bool Matrix4::operator != (const Matrix4& a) const
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (m[i][j] != a.m[i][j]) return 1;

    return 0;
}

void Matrix4::Set(
    float __11, float __12, float __13, float __14,
    float __21, float __22, float __23, float __24,
    float __31, float __32, float __33, float __34,
    float __41, float __42, float __43, float __44)
{
    _11 = __11;	_12 = __12;	_13 = __13;	_14 = __14;
    _21 = __21;	_22 = __22;	_23 = __23;	_24 = __24;
    _31 = __31;	_32 = __32;	_33 = __33;	_34 = __34;
    _41 = __41;	_42 = __42;	_43 = __43;	_44 = __44;
}

void Matrix4::Set(float* entries)
{
    memcpy(&_11, entries, sizeof(float) * 16);
}

float* Matrix4::Get()
{
    return &_11;
}

Matrix4& Matrix4::Zero()
{
    _11 = _22 = _33 = _44 = _12 = _13 = _14 = _21 = _23 = _24 = _31 = _32 = _34 = _41 = _42 = _43 = 0.0f;

    return *this;
}

Matrix4& Matrix4::Identity()
{
    // 만들고보니.. 기존 행렬을 identity로 만들어야 하는 경우가 있을것인가..?
    // static함수로 빼는게 낫지않을까..?

    memset(&_11, 0, sizeof(float) * 16);
    _11 = _22 = _33 = _44 = 1.0f;

    return *this;
}

Matrix4& Matrix4::Transpose()
{
    float temp;

    temp = _12; _12 = _21; _21 = temp;
    temp = _13;	_13 = _31; _31 = temp;
    temp = _14;	_14 = _41; _41 = temp;
    temp = _23;	_23 = _32; _32 = temp;
    temp = _24;	_24 = _42; _42 = temp;
    temp = _34;	_34 = _43; _43 = temp;

    return *this;
}


bool Matrix4::Invert()
{
    //  Numerical Methods for Scientists and Engineers, J. D. Hoffman,
    //  McGraw-Hill, 1992, Section 1.3. 참고.

    int i, j, k, maxValue;
    double aTemp;
    Matrix4 bVector(MatrixIdentity());

    for (i = 0; i < 4; i++)
    {
        maxValue = i;
        for (j = i + 1; j < 4; j++)   // Partial pivot (swap rows) if necessary
            if (fabs(m[j][i]) > fabs(m[maxValue][i])) maxValue = j;

        if (maxValue != i)
        {
            for (k = i; k < 4; k++)
            {
                aTemp = m[i][k];
                m[i][k] = m[maxValue][k];
                m[maxValue][k] = aTemp;
            }
            for (k = 0; k < 4; k++)
            {
                aTemp = bVector.m[i][k];
                bVector.m[i][k] = bVector.m[maxValue][k];
                bVector.m[maxValue][k] = aTemp;
            }
        }

        for (j = i + 1; j < 4; j++)
        {
            double aFactor = m[j][i] / m[i][i];
            for (k = 4 - 1; k >= i; k--)
            {
                if (fabs(m[i][i]) < EPSILON)
                {
                    // invertg: i: %d j: %d k: %d pivot element cannot be zero!",i,j,k
                    return 0;
                }
                m[j][k] -= m[i][k] * aFactor;
            }
            for (k = 4 - 1; k >= 0; k--)
                bVector.m[j][k] -= bVector.m[i][k] * aFactor;
        }
    }

    // Backsubstitute the augmented b vectors to obtain the inverse
    int col, row;
    double aSum;

    for (col = 0; col < 4; col++)
    {
        for (j = 4 - 1; j >= 0; j--)
        {
            aSum = 0.0;
            if (j != 4 - 1)
            {
                for (k = j + 1; k < 4; k++)
                {
                    aSum += (m[j][k] * bVector.m[k][col]);
                }
            }
            if (fabs(m[j][j]) < EPSILON)
            {
                // invertg: Zero Diagonal Not Allowed. Exiting
                return 0;
            }
            bVector.m[j][col] = (bVector.m[j][col] - aSum) / m[j][j];
        }
    }

    // Copy the inverse into m
    for (col = 0; col < 4; col++)
        for (row = 0; row < 4; row++)
            m[row][col] = bVector.m[row][col];

    return 1;
}

float Matrix4::ScaleX() const
{
    return Vector3(_11, _12, _13).Length();
}

float Matrix4::ScaleY() const
{
    return Vector3(_21, _22, _23).Length();
}

float Matrix4::ScaleZ() const
{
    return Vector3(_31, _32, _33).Length();
}

const Vector4 DefaultMultiplyOperator(const Matrix4& m, const Vector4& v)
{
    Vector4 t = Vector4(0.0f, 0.0f, 0.0f, 0.0f);

    t.x = v.x * m._11 + v.y * m._21 + v.z * m._31 + v.w * m._41;
    t.y = v.x * m._12 + v.y * m._22 + v.z * m._32 + v.w * m._42;
    t.z = v.x * m._13 + v.y * m._23 + v.z * m._33 + v.w * m._43;
    t.w = v.x * m._14 + v.y * m._24 + v.z * m._34 + v.w * m._44;

    return t;
}

const Vector3 Matrix4::operator * (const Vector3& v) const
{
    Vector4 t = Vector4(v.x, v.y, v.z, 1.0f);
    t = *this * t;
    return Vector3(t.x, t.y, t.z);
}

const Vector2 Matrix4::operator * (const Vector2& v) const
{
    Vector4 t = Vector4(v.x, v.y, 1.0f, 1.0f);
    t = *this * t;
    return Vector2(t.x, t.y);
}
