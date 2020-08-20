/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：test.c
*   创 建 者:  dwl
*   创建日期：2020/08/19
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>

int main()
{
	void *p = NULL;
	union
	{
	int a = 10;
	char b = "hello";
	float c = 1.0;
		
	};

	printf(" p = %d\n", sizeof(*p));
	printf("*p = %d\n", *(int *)p);

	return 0;
}
