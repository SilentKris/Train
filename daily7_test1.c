/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily7_test1.c
*   创 建 者:  dwl
*   创建日期：2020/08/17
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#define N 3

int main()
{
	int arr[N][N] = {1,2,3,4,5,6,7,8,9};
	int count, sum;

	for(count = 0, sum = 0; count < N; count++)
	{ 
		sum += arr[count][count];
	}
	printf("主对角线之和为%d\n", sum);

	return 0;

}
