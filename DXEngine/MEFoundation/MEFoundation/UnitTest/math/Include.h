#pragma once

#include <Vector2.h>
#include <Vector3.h>
#include <Vector4.h>
#include <Matrix.h>

#include "gtest/gtest.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <random>
#include <limits>
#include <algorithm>

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_real_distribution<float> dis(-100, 100);

template<class T>
float DegreeToRadian(T degree)
{
    return degree * static_cast<T>(M_PI) / 180.f;
}

template<class T>
float RadianToDegree(T radian)
{
    return radian * 180.f / static_cast<T>(M_PI);
}

static float RendomFloat()
{
    return dis(gen);
}

template<class T>
T RendomObjectWithValues()
{
    T r;
    int len = sizeof(r) / sizeof(r.x);
    for (unsigned int i = 0; i < len; ++i)
    {
        r[i] = RendomFloat();
    }
    return r;
}

template<class T>
void RendomObjectsWithValuesForEqualTest(T& a, T& b, T& c)
{
    a = RendomObjectWithValues<T>();
    b = a;
    c = RendomObjectWithValues<T>();
    while (&a.x == &c.x)
        c = RendomObjectWithValues<T>();
}

template<class T>
T SumEachValueOfObject(const T& a, const T& b)
{
    T r;
    int len = sizeof(r) / sizeof(r.x);
    for (unsigned int i = 0; i < len; ++i)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

template<class T>
T SubEachValueOfObject(const T& a, const T& b)
{
    T r;
    int len = sizeof(r) / sizeof(r.x);
    for (unsigned int i = 0; i < len; ++i)
    {
        r[i] = a[i] - b[i];
    }
    return r;
}

template<class T>
T MulEachValueOfObject(const T& a, float s)
{
    T r;
    int len = sizeof(r) / sizeof(r.x);
    for (unsigned int i = 0; i < len; ++i)
    {
        r[i] = a[i] * s;
    }
    return r;
}

// return true if the difference between a and b is less than absEpsilon, or within relEpsilon percent of the larger of a and b 
template<class F>
bool ApproximatelyEqualAbsRel(F a, F b, F absEpsilon, F relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero. 
    double diff = std::fabs(a - b);
    if (diff <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm 
    return diff <= ((std::fabs(a) < std::fabs(b) ? std::fabs(b) : std::fabs(a)) * relEpsilon);
}
