/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_test2.c
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
	unsigned char count = 0;

	while(count != 200)
	{
		if((count % 10) == 0)	
			putchar('\n');
		printf("%-5d", ++count);
	}
	putchar('\n');
	putchar('\n');
	putchar('\n');


	return 0;
}
