#define MAX(a, b) (((a) > (b)) ? (a) : (b))


#ifdef USE_MACRO
// original code
int main()
{
	int num1 = 1;
	int num2 = 2;

	int max1 = MAX(num1, num2);
	int max2 = MAX(num1, num2);
	return max1;
}
#endif


// substituted code
// gcc -E -Wp,-P,-C,-CC macro.cpp
/*
int main()
{
	int num1 = 1;
	int num2 = 2;
	int max1 = (((num1) > (num2)) ? (num1) : (num2));
	int max2 = (((num1) > (num2)) ? (num1) : (num2));
	return max1;
}
*/