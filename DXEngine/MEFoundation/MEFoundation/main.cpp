#include <Vector2.h>

void main()
{
	Vector2* v2 = new Vector2(0, 0);
	auto b = v2->IsZero();

	delete v2;
}