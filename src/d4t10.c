/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_test10.c
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
	int a,b,c;
	int sum, count=0;
	for(a = 1;a <= 4; a++)
		for(b = 1; b <= 4; b++)
			for(c = 1;c <= 4; c++)
				if(a != b && a != c && b != c)
				{
						sum = a*100 + b*10 + c;
						count ++;
						printf("该数为%d \n", sum);
				}
	printf("能够组成%d个数\n", count);
	return 0;
}
