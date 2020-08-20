/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily6_test4.c
 *   创 建 者:  dwl
 *   创建日期：2020/08/17
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include <stdio.h>

#define MAX 5

int main()
{
	int arr[MAX], count;
	int i, j, t;
	
	printf("请输入要进行排序的元素：");
	for(count = 0; count <MAX; count++)
		scanf("%d", &arr[count]);
	
	for(i = MAX-1; i > 0; i-- )
		for(j = 0; j < i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				t = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = t;
			}
		}
	for(count = 0; count < MAX; count++)
		printf("%d ", arr[count]);
	
	putchar('\n');

	return 0;

}
