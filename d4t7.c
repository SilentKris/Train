/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_test7.c
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
	int num;
	int a, b, c;

	for(num = 100; num <= 999; num++)
	{
		      c = num % 10;
		      b = num / 10 % 10;
		      a = num /100;

		if(num == (a*a*a + b*b*b + c*c*c))
				printf("水仙花数为:%d\n", num);
	}
	return 0;
}
