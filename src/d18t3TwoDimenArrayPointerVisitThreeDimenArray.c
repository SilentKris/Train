#include <stdio.h>

int main(int argc, char **argv)
{
	int *q[10][10] = {0};
	int *(*p)[10] = {0};
	int a = 10;
	p = q;

	p[2][2] = &a;

	printf("q[2][2] = %p, *q[2][2] = %d\n", q[2][2], *q[2][2]);



	return 0;
}
