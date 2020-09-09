#include <stdio.h>
#include <stdlib.h>
#define N 20
int main()
{
	int arr[N][N];
	int (*q)[N];
	int count, i=N, j=N;
	q = arr;
	srand(time(NULL));

	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			arr[i][j] = rand()%100;
	while(q < arr+N)
	{
		for(i=0; i<N; i++)
			printf("%-3d ", (*q)[i]);
		q++;
		putchar('\n');
	}


	return 0;
}
