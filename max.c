/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：max.c
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
	int a, b, c;
	int max;
	printf("请输入3个不相等的整形实数，以空格隔开：");
	scanf("%d %d %d", &a, &b, &c);
	
	if(a > b)
			if(a > c)
					max = a;
			else 
					max = c;
	else
			if(b > c)
					max = b;
			else 
					max = c;
	printf("最大值为%d\n", max);

	return 0;
}
