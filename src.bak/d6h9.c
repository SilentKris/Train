/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily6_homework9.c
 *   创 建 者:  dwl
 *   创建日期：2020/08/17
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include <stdio.h>
#define MAX 50

int main()
{
	char ch1_arr[MAX] = {0};
	char ch2_arr[MAX] = {0};
	char count1=0, count2=0;

	
	gets(ch1_arr);
	printf("原始字符串：");
	puts(ch1_arr);
	while( ch1_arr[count1] != '\0')
	{
		if(ch1_arr[count1] == ' ')
			count1++;
		ch2_arr[count2] = ch1_arr[count1];
		count1++;
		count2++;
	}
	printf("去空格字符串：");
	puts(ch2_arr);

	return 0; 
}
