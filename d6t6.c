/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily6_test6.c
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
	int count = 0;
	char dest[64]= {"hello"};
	char src[64] = {"wrold"};

	puts(dest);
	puts(src);

	while(src[count] != '\0' && count < 64)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0'; 
	printf("复制完成，共完成%d 个字符的复制！\n", count);
	puts(dest);
	puts(src);

	return 0;
}
