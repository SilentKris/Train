/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_test8.c
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
	char row, line;
	for(line = 1; line <=9; line++)
	{
		for(row = 1; row <= line; row++)
		{
			putchar('*');
		}
		putchar('\n');
	}
}
