#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(int argc, char **argv)
{
	int arr[5][5];
	int *p[5];
	int i, j, row, temp;
	srand(time(NULL));


	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			arr[i][j] = rand()%100;
			p[i] = arr[i];
		}
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			printf("%-3d", arr[i][j]);
		putchar('\n');
	}

	for(i=0; i<N; i++)
		for(j=0; j<N-1-i; j++)
			for(row=0; row<N; row++)
			{
				if(*(p[j+1]+row) < *(p[j]+row))
				{
					temp = *(p[j+1]+row);
					*(p[j+1]+row) = *(p[j]+row);
					*(p[j]+row) = temp;
				}
			}

	printf("***************************\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			printf("%-3d", arr[i][j]);
		putchar('\n');
	}

	return 0;
}
