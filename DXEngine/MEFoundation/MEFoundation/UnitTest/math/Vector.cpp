#include "Include.h"


TEST(Vector, Equal)
{
	auto body = [](auto v)
	{
		using V = decltype(v);

		V a, b, c;
		RendomObjectsWithValuesForEqualTest<V>(a, b, c);
		EXPECT_EQ(true, a == b);
		EXPECT_EQ(false, a == c);
	};

	body(Vector2());
	body(Vector3());
	body(Vector4());
}

TEST(Vector, NotEqual)
{
    auto body = [](auto v)
    {
        using V = decltype(v);
        V a, b, c;
        RendomObjectsWithValuesForEqualTest<V>(a, b, c);
        EXPECT_EQ(false, a != b);
        EXPECT_EQ(true, a != c);
    };
    body(Vector2());
    body(Vector3());
    body(Vector4());
}

TEST(Vector, Add)
{
    auto body = [](auto v)
    {
        using V = decltype(v);
        V a = RendomObjectWithValues<V>();
        V b = RendomObjectWithValues<V>();
        V r = SumEachValueOfObject<V>(a, b);
        EXPECT_EQ(r, a + b);
        a += b;
        EXPECT_EQ(r, a);
    };
    body(Vector2());
    body(Vector3());
    body(Vector4());
}

TEST(Vector, Sub)
{
    auto body = [](auto v)
    {
        using V = decltype(v);
        V a = RendomObjectWithValues<V>();
        V b = RendomObjectWithValues<V>();
        V r = SubEachValueOfObject<V>(a, b);
        EXPECT_EQ(r, a - b);
        a -= b;
        EXPECT_EQ(r, a);
    };
    body(Vector2());
    body(Vector3());
    body(Vector4());
}

TEST(Vector, ScalarMultiply)
{
    auto body = [](auto v)
    {
        using V = decltype(v);
        V a = RendomObjectWithValues<V>();
        float s = RendomFloat();
        V r = MulEachValueOfObject<V>(a, s);
        EXPECT_EQ(r, a * s);
        a *= s;
        EXPECT_EQ(r, a);

        if (a != r)
            auto k = 1;
    };
    body(Vector2());
    body(Vector3());
    body(Vector4());
}

TEST(Vector, Dot)
{
    auto body = [](auto v)
    {
        using V = decltype(v);
        V a = RendomObjectWithValues<V>();
        V b = RendomObjectWithValues<V>();
        int dimension = sizeof(a) / sizeof(a.x);
        float r = 0.0f;
        for (unsigned int i = 0; i < dimension; ++i)
        {
            r += a[i] * b[i];
        }
        EXPECT_EQ(r, V::Dot(a, b));
    };
    body(Vector2());
    body(Vector3());
    body(Vector4());
}

TEST(Vector, Cross)
{
    Vector3 v1{ 1.f, 0.f, 0.f };
    Vector3 v2{ 0.f, 1.f, 0.f };
    Vector3 answer{ 0.f, 0.f, 1.f };
    EXPECT_EQ(answer, Vector3::Cross(v1, v2));
}
