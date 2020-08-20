/*=============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily6_homework4.c
 *   创 建 者:  dwl
 *   创建日期：2020/08/17
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include <stdio.h>
#include <string.h>
#define LEN 50


int main()
{
	char ch_arr[LEN], length, diff, locate = 0;

	printf("Please input a string:");
	gets(ch_arr);

	length = strlen(ch_arr);
	printf("该字符串有%d 个\n", length);

	while(locate != (length/2+1))
	{
		diff = ch_arr[locate]- ch_arr[length-locate-1];
		if(diff!=-32 && diff!=32 && diff!=0)
			break;
		locate++;
	}
	if(locate == (length/2+1))
		printf("该字符串为回文数列\n");
	else
		printf("该字符串非回文数列\n");


	return 0;

}
