
#include <stdio.h>
#include <stdlib.h>

#define N 100
void rand_arr(int a[], int n);
void Sort_arr(int a[], int n);
void printf_arr(int a[], int n);
int *prime_num(int n1, int n2);
int sum_arr(int a[], int n);

int a[N];

void TheOperationOnArray(void)
{	

	int *p = NULL;
	
	rand_arr(a, N);
	puts("本次要操作的长度为100的数组是:\n");
	printf_arr(a, N);

	puts("************************************************");

	Sort_arr(a, N);
	puts("排序后为:\n");
	printf_arr(a, N);

	puts("************************************************");
	puts("数组各元素之和为:\n");
	printf("sum = %d\n", sum_arr(a, N));

	puts("************************************************");
	puts("2 - 200 之间素数为:\n");
	p = prime_num(2, 200);

	printf_arr(p, p[0]);


	return ;
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
		printf("%-5d", a[i]);
	}
	putchar('\n');
}

int sum_arr(int a[], int n)
{
	int sum = 0, i;
	for(i = 0; i < n; i++)
	{
		sum += a[i];
	}	
	return sum;

}

int *prime_num(int n1, int n2)
{

	int i, j, count=0;
	i = j = n1;


	for(i=n1; i<=n2; i++)
	{
		for(j=i-1; j>1; j--)
		{
			if(!(i % j))
				break;
		}
		if(1 == j)
			a[++count] = i;
	}
	a[0] = count;

	return a;
}
