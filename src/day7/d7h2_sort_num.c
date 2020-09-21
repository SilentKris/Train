/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：d7_h2_sort_num.c
 *   创 建 者:  dwl
 *   创建日期：2020/08/18
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 2
int main()
{
	int arr[N] = {0};
	int sort[M][N];
	int i, j, t, count_i, count_j, count;
	srand(time(NULL));

	for(count=0; count<N; count++)
		arr[count] = rand()%100;

	for(i = N-1; i >= 0; i-- )
		for(j = 0; j < i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				t = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = t;
			}
		}

	for(count=0, count_i=0, count_j=0; count<N; count++)
	{
		if(arr[count]%2)
			sort[0][count_i++] = arr[count];
		else
			sort[1][count_j++] = arr[count];
	}

	for(i=0; i<M; i++)
	{
		if(i == 0)
			for(j=0; j<count_i; j++)
				printf("%-3d", sort[i][j]);
		else
			for(j=0; j<count_j; j++)
				printf("%-3d", sort[i][j]);

		putchar('\n');
	}
	putchar('\n');

	return 0;
}
