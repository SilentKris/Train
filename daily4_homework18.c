/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_homework18.c
*   创 建 者:  dwl
*   创建日期：2020/08/15
*   描    述：
*            
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <limits.h>

int main()
{
	unsigned int num;
	unsigned int sum = 1;

	printf("请输入想要计算的阶乘：");
	scanf("%u",&num);
	for(;num > 0; num--)
	{
			if(UINT_MAX/sum < num)
			{
				printf("溢出\n");
				return -1;
			}
			sum *= num;
			printf("sum = %u\n", sum);
	}
	printf("结果为 %u\n", sum);

	return 0;
}
