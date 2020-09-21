/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：dail5_test1.c
*   创 建 者:  dwl
*   创建日期：2020/08/16
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>

int main()
{
	unsigned int Num, m, n;
	unsigned int Count;

	printf("Please input a Number:");
	scanf("%u",&Num);
	
	for(m=1,n=Num; m<=(Num-m); m++)
	{
		n = Num - m;
		printf(" %3u,%3u;\n",m, n);
	}


	return 0;
}
