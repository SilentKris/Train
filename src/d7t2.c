/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily7_test2.c
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
	int i, j, count;
	int Sum;
	srand(time(NULL));

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			arr[i][j] = rand()%1000;
			printf("%-5d ", arr[i][j]);
		}
		putchar('\n');
		putchar('\n');
	}
	
	for(i = 0, Sum = 0; i < N; i++)
	{
		for(j = 0; j <= i; j++)
		{
			Sum += arr[i][j];
			printf("%d", arr[i][j]);
			if(j < i)
			putchar('+');
		}
		putchar('+');


	}
	putchar('=');
	printf("%d\n", Sum);

	return 0;
}
