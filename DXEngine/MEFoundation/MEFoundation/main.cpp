#include <Vector2.h>
#include <gtest/gtest.h>

#define USE_UNIT_TEST 1

int main(int argc, char** argv)
{
#if USE_UNIT_TEST
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#else
	Vector2* v2 = new Vector2(50, 0);
	auto b = v2->IsZero();

	auto aa = sizeof(*v2[0]);
	auto a2 = sizeof(v2);
	auto a3 = sizeof(*v2);
	float a4 = 0.0;
	auto a5 = sizeof(&v2);

	auto k = *v2;
	auto k1 = *v2[0];
	auto k2 = &v2;
	auto k3 = v2;
	float* u = (float*)v2;
	auto z = sizeof(*v2) / sizeof(*v2[0]);
	*v2[0] = 5.0f;
	auto zz = &v2->x;

	Vector2 vvaa;
	auto z1 = vvaa.x;
	auto z2 = &vvaa.x;
	delete v2;
#endif
}