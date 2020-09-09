/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily6_test8.c
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
	
	while((dest[count] == src[count]) && (dest[count] == '\0' && src[count] == '\0'));
	count++;
	count--;
	if(dest[count] == src[count])
	{
		printf("两字符串相等\n");
		return 0;
	}
       else if ((dest[count] == '\0' && src[count] != '\0') && (dest[count] != '\0' && src[count] == '\0'))
	{
		printf("两字符串不相等\n");
		return 1;
	}

}

