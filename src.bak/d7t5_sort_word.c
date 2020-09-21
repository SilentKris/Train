/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：d7_t5_sort_word.c
*   创 建 者:  dwl
*   创建日期：2020/08/18
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>

int main()
{
	char a[6][20] = {"hello", "wrold", "ni hao", "chengdu", "good", "huaqing"};
	char b[20];
	int i;
	
	for(i=0; i<3; i++)
	{
		strcpy(b, a[i]);
		strcpy(a[i], a[4-i]);
		strcpy(a[4-i], b);
	}
	for(i=0; i<5; i++)
	{
		puts(a[i]);
	}



	return 0;
}
