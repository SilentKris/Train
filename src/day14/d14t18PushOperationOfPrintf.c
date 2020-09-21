#include <stdio.h>

int main(int argc, char **argv)
{
	int a = 10;
	printf("%d, %d, %d, %d\n", a++, a--, ++a, --a);

	int arr[] = {6, 7, 8, 9, 10};
	int *ptr = arr;
	*(ptr++) += 123;

	printf("%d, %d\n", *ptr, *(++ptr));
	

	return 0;
}
