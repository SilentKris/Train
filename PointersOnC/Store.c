#include <stdio.h>

int main()
{
	int a =212;
	char *p = (char*)&a;
	printf("%d\n",*p);
	printf("%#X\n", a);
	return 0;
}
