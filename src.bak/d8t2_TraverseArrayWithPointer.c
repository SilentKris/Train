/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：d8_t2_TraverseArrayWithPointer.c
*   创 建 者:  dwl
*   创建日期：2020/08/20
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>


int main()
{
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = arr;

	while((p-arr) < 10)
		printf("%d\t", *p++);
	putchar('\n');


	return 0;
}
