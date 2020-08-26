#include <stdio.h>

void Sort(int *, int *, int *);
void Swap(int *, int *);

int main(int argc, char **argv)
{

	int a = 2, b = 1, c = 3;
	Sort(&a, &b, &c);

	printf("a = %d, b = %d, c = %d\n", a, b, c);

	return 0;
}


void Sort(int *a, int *b, int *c)
{
	if(*a < *b)
		Swap(a, b);
	if(*a < *c)
		Swap(a, c);
	if(*b < *c)
		Swap(b, c);



}

void Swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;


}
