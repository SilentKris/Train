/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily6_homework8.c
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
	int arr[MAX] = {0};
	int Num, m, Max_time, count, times=1;
	printf("请输入10个数字：\n");
	for(count=0; count<MAX; count++)
	{
		scanf("%d", &arr[count]);
	}

	Num = arr[0];
	Max_time = 1;
	for(count=0; count<MAX-1; count++)
	{
		m = arr[count];
		if(arr[count+1] == m)
		{
			times += 1;
			printf("m =%d, times = %d\n", m, times);
		}
		if(arr[count+1] != m || (MAX-1)==(count+1))
		{
			if(times > Max_time)
			{
				Num = m;
				Max_time = times;
			}
			times = 1;
		}

	}
	printf("出现次数最多的数字是%d, 出现次数是%d次\n", Num, Max_time);

	return 0;
}
