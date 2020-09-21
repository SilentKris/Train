/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_test3.c
*   创 建 者:	farsight
*   创建日期：2020/08/12
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>

int main()
{
	int num = 0;
	int count = 0;
	do
	{
		if(num % 3 == 0)
		{
			printf("%-5d", num);
			count++;
		}
	}while(++num <= 200);
	putchar('\n');
	printf("200以内3的倍数共%d个!\n",count);

	
	return 0;
}
