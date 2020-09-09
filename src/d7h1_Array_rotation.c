/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：d7_h1_Array_rotation.c
*   创 建 者:  dwl
*   创建日期：2020/08/18
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <stdlib.h>
#define N 4


int main()
{
	int arr1[N][N];
	int arr2[N][N];
	int i, j, t, mid;

	srand(time(NULL));
	

	printf("旋转前\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			arr1[i][j] = rand()%100;
			printf("%-3d", arr1[i][j]);
		}
		putchar('\n');
	}
	
	mid = N / 2;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			arr2[3-j][i] = arr1[i][j];
		}		

	printf("旋转后：\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%-3d", arr2[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
