#include <stdio.h>
#define N 20

int *MaxValueArray(int a[], int n);
int main(int argc, char **argv)
{
	int *Max,  arr[N];

	Max = MaxValueArray(arr, N);

	printf("最大数为%d, 地址为%p\n",*Max, Max);


	return 0;
}

int *MaxValueArray(int a[], int n)
{
	int i, Max = 0;
	srand(time(NULL));

	for(i=0; i<n; i++)
	{
		a[i] = rand()%100;
		printf("%-3d", a[i]);

		if(a[Max] < a[i])
			Max = i;
	}
	putchar('\n');
	return &a[Max];
}
