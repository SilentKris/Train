/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：d8_t1_strcpy_point.c
*   创 建 者:  dwl
*   创建日期：2020/08/20
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#define N 100

int main()
{
	char a[N] = "Hello ";
	char b[N];
	char *p;
	int i=0, count;

	p = a;
	count = strlen(a);


	while(p <= &a[count])
	{
		b[i++] = *(p++);
	}
	puts(b);

	return 0;
}
