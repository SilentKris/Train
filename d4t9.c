/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_test9.c
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
	int a, b;
	for(a = 1; a <= 9; a++)
	{
			for(b = 1; b <= a; b++)
					printf("%d*%d=%-3d", b, a, a*b);
			putchar('\n');
	}

	return 0;

}
