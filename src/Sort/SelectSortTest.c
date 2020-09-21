#include <stdio.h>
#include <stdlib.h>
#define N 10

int *Sort(int arr[], int len);
int main(int argc, char **argv)
{
	int arr[N], count=0;
	int *p;
	srand(time(NULL));
	
	while(count < N)
		arr[count++] = rand()%1000;
	p = Sort(arr, N);
	while(count--)
		printf("%d\t", *p++);
	putchar('\n');

	return 0;
}


int *Sort(int arr[], int len)
{
	int MinIndex;
	int i, j, t;
	for(i=0; i<len-1; i++)
	{
		MinIndex = i;
		for(j=i+1; j<len; j++)
		{
			if(arr[j] < arr[MinIndex])
			{
				MinIndex = j;
			}
		}
		t = arr[i];
		arr[i] = arr[MinIndex];
		arr[MinIndex] = t;
	}

	return arr;
}

