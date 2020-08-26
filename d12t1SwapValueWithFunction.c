#include <stdio.h>

void Swap(int *, int *);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	Swap(&a, &b);
	printf("%d %d\n", a, b);

	return 0;
}

void Swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
