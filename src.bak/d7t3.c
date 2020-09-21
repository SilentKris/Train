/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily7_test3.c
*   创 建 者:  dwl
*   创建日期：2020/08/17
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>

#define N 10

int main()
{
	int arr[N][N];
	int i, j;
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j <= i; j++)
		{
			if(i == 0 || j == 0 || i == j)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
			}
			 printf("%-5d", arr[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
