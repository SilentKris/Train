#include <stdio.h>

typedef union {
	char a[4];
	int b;
}t;

int main(int argc, char **argv)
{
	t i;
	i.b = 10;

	

	printf("%d, %d\n",i.a[0], i.b);


	return 0;
}
