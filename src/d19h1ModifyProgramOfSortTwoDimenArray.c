#include <stdio.h>
#include <stdlib.h>

#define M 3
void buf_order(int (*p)[M]);

int main()
{
	int buf[M][M] = {0};
	int i, j;
	srand(time(NULL));

	for(i=0; i<M; i++)
	{
		for(j=0; j<M; j++)
		{
			buf[i][j] = rand()%100;
			printf("%-3d", buf[i][j]);
		}
	}
	puts("\n******************");
	buf_order(buf);

	for(i=0; i<M; i++)
	{
		for(j=0; j<M; j++)
		{
			printf("%-3d", buf[i][j]);
		}
	}
	putchar('\n');

	return 0;
}	


void buf_order(int (*p)[M])
{
	int i = 0;
	int j = 0;

	for(i = 0; i < M * M; i++)
		for(j = 0; j < M * M - 1 - i; j++)
		{
			if((*p)[j] > (*p)[j+1])
			{
				(*p)[j] ^= (*p)[j+1];
				(*p)[j+1] ^= (*p)[j];
				(*p)[j] ^= (*p)[j+1];
			}
		}
}



