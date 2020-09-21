#include <stdio.h>
#include <stdlib.h>


int  *Sort(int *, int);

int main()
{
	int arr[10], *p;
	int i=10;
	srand(time(NULL));


	while(i)
	{
		arr[--i] = rand()%100;
	}
	p = Sort(arr, 10);

	while(i != 10)
		printf("%d\t", p[i++]);


	return 0;
}

int *Sort(int a[], int len)
{
	int MinIndex, temp;
	int i, j=0;
	for(i = 0; i < len-1; i++)
	{
		MinIndex = i;
		for(j = i+1; j < len; j++)
		{
			if(a[j] < a[MinIndex])	
				MinIndex = j;
		}
		temp = a[i];
		a[i] = a[MinIndex];
		a[MinIndex] = temp;
	}
	return a;
}

