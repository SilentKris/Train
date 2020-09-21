/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily6_homework7.c
 *   创 建 者:  dwl
 *   创建日期：2020/08/17
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include <stdio.h>
#define MAX 10

int main()
{

	int arr[MAX] = {1, 20, 36, 38, 50, 52};
	int Insert, head, tail, swap, count;

	printf("请输入要插入的数值：");
	scanf("%d",&Insert);

	printf("排序前的数组为：\n");
	for(count = 0; count < MAX; count++)
	{
		printf("%-5d", arr[count]);
	}
	putchar('\n');
	
	for(head = 0; head < MAX; head++)
	{
		if(Insert <= arr[head] || (head>0 && (arr[head-1]>arr[head])))
		{
			for(tail = MAX-1; tail > head; tail--)
			{
				arr[tail] = arr[tail-1];
			}
			arr[head] = Insert;
			break;
		}

			
	}
	printf("排序后的数组为：\n");
	for(count = 0; count < MAX; count++)
	{
		printf("%-5d", arr[count]);
	}
	putchar('\n');
	
	return 0;
}
