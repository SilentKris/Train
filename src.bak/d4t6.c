/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_test6.c
*   创 建 者:  dwl
*   创建日期：2020/08/12
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>


int main()
{
	unsigned int num = 0, count = 0;
	for(; num <= 100; num++)
	{
		if(num % 7 == 0)
		{
				printf("7的倍数为%d\n",num);
				count++;
		}
	}
	printf("综上，7的倍数共%d个\n",count);
	return 0;
}

