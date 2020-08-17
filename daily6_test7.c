/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily6_test7.c
 *   创 建 者:  dwl
 *   创建日期：2020/08/17
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include <stdio.h>

int main()
{
	int count1 = 0, count2=0;
	char dest[64]= {"hello"};
	char src[64] = {"wrold"};
	
	puts(dest);
	puts(src);

	while(dest[count1++] != '\0');
	count1--;
	while(dest[count1++] = src[count2++]);
	
	puts(dest);
	puts(src);

	return 0;
	
}
