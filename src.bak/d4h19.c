/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_homework19.c
*   创 建 者:  dwl
*   创建日期：2020/08/15
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>

int main()
{
	
	unsigned int count = 4, sum, num, s=1;
	
	for(sum = 0; count > 0; count--)
	{
			for(num = count, s = 1; num > 0; num--)
					s *= num;
			sum += s;
	}
	printf("sum = 1! + 2! + 3! + 4! = %d\n", sum);
	
	
	
	return 0;
}
