/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：d7_h3_sort_string.c
 *   创 建 者:  dwl
 *   创建日期：2020/08/19
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include <stdio.h>
#include <string.h>
#define N 20

int main()
{
	char str[6][N] = {"hello", "world", "ni hao", "chengdu", "good", "huaqing"};
	char t;
	int i, j, count;
	for(count=0; count<6; count++)
		for(i =(strlen(str[count])-1); i>=0; i--)
			for(j=0; j<i; j++)
			{
				if(str[count][j] > str[count][j+1])
				{
					t = str[count][j+1];
					str[count][j+1] = str[count][j];
					str[count][j] = t;
				}
			}
	for(i=0; i<6; i++)
		puts(str[i]);
	return 0;
}
