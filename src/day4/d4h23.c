/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily4_homework23.c
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
	int row, column; //菱形的由几行几列的 * 组成
	unsigned int width; //该菱形的宽度
	int row_i, column_i;  //控制输出 * 的数量 
	int blank_i; //控制输出空格
	printf("请输入奇数层数：");
	scanf("%d", &row);
	if((row % 2) == 0)
	{
		printf("请输入奇数\n");
		return -1;
	}
	width = 2*(row-1)+1;
	for(row_i = 1; row_i <= row; row_i++)
	{
		if(row_i <= (row+1)/2)
			column = 2*(row_i-1)+1;
		else
			column = 2*(row-row_i)+1; 
		blank_i = (width - column)/2;
		for(column_i = 1; column_i <= (width-blank_i); column_i++)
		{
			if(column_i <= blank_i)
				putchar(' ');
			else
				putchar('*');
		
		}
		putchar('\n');
	}


	return 0;
}
