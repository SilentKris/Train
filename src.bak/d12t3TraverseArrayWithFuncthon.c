#include <stdio.h>
#include <stdlib.h>


 void rand_arr(int a[], int n);
 void Sort_arr(int a[], int n);
void printf_arr(int a[], int n);

int main(int argc, char **argv)
{

	int a[10];

	rand_arr(a, 10);
	printf_arr(a, 10);

	puts("******************************");

	Sort_arr(a, 10);
	printf_arr(a, 10);


	return 0;
}

void rand_arr(int a[], int n)
{
	int i;
	srand(time(NULL));
	for(i=0; i<n; i++)
	{
		a[i] = rand()%100;
	}
}

void Sort_arr(int a[], int n)
{
	int i, j, temp;

	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i; j++)
		{
			if(a[j+1] < a[j])
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void printf_arr(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%-3d", a[i]);
	}
	putchar('\n');
}
