/*
 排序结果：
 左上角为最小，右下角为最大
*/


#include <stdio.h>
#include <stdlib.h>

#define N 12
#define M 10
int main()
{
	int arr[M][N];
	int i, j, t, count_i, count_j, temp;

	srand(time(NULL));
/**************************赋值*******************************/
	for(count_i=0; count_i<M; count_i++)
	{
		for(count_j=0; count_j<N; count_j++)
		{
			arr[count_i][count_j] = rand()%100;
			printf("%-4d", arr[count_i][count_j]);
		}
		putchar('\n');
	}
	puts("*******************************************");
/*************************行列排序***************************/
	for(t=0; t < M; t++)
		for(i = 0; i < N; i++ )
			for(j = 0; j < N-i-1; j++)
			{
				if(arr[t][j+1] < arr[t][j])
				{
					temp = arr[t][j+1];
					arr[t][j+1] = arr[t][j];
					arr[t][j] = temp;
				}
			}
	for(t=0; t < N; t++)
		for(i = 0; i < M; i++ )
			for(j = 0; j < M-i-1; j++)
			{
				if(arr[j+1][t] < arr[j][t])
				{
					temp = arr[j+1][t];
					arr[j+1][t] = arr[j][t];
					arr[j][t] = temp;
				}
			}
/*****************************遍历打印************************/
	for(count_i=0; count_i<M; count_i++)
	{
		for(count_j=0; count_j<N; count_j++)
		{
			printf("%-4d", arr[count_i][count_j]);
		}
		putchar('\n');
	}

}
