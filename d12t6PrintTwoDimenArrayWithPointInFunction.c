#include <stdio.h>



void print(int (*q)[10], int n);

int main(int argc, char **argv)
{
	int a[10][10];

	 print(a, 10);

	return 0;
}


void print(int (*q)[10], int n)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<10; j++)
		{
			q[i][j] = rand()%100;
			printf("%-3d", q[i][j]);
		}
		putchar('\n');
	}
}

