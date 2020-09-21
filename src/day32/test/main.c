#include "common.h"


int main(int argc, char **argv)
{
	int a = 12; int b = 23;

	printf("a + b = %d\n", add(a, b));
	printf("a - b = %d\n", sub(a, b));
	printf("a * b = %d\n", multi(a, b));
	printf("a / b = %d\n", div(a, b));

	return 0;
}
