#include <stdio.h>
#include <stdlib.h>


int  Bubble_Sort(int arr[], int n);

int main(int argc, char **argv)
{
	int (*q[1])(int *, int), arr[10], i;
	srand(time(NULL));
	q[0] = Bubble_Sort;

	for(i=0; i<10; i++)
	{
		arr[i] = rand()%100;
		printf("%-3d", arr[i]);
	}
	puts("\n************************************");
	q[0](arr, 10);

	for(i=0; i<10; i++)
	{
		printf("%-3d", arr[i]);
	}
	
	putchar('\n');
	

	return 0;
}

int Bubble_Sort(int arr[], int n)
{
	int i, j, temp;
	for(i=0; i<n; i++)
		for(j=0; j<n-1-i; j++)
		{
			if(arr[j+1] > arr[j])
			{
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	return 0;
}
