#include <stdio.h>
static int a=10;
printf("a = %d\n", a);
int main(int argc, char **argv)
{

	printf("b = %d\n", b);
	{
		static int b = 19;
	}

	return 0;
}
