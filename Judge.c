/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Judge.c
*   创 建 者:	farsight
*   创建日期：2020/08/12
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>

void Judge(char);

int main()
{
	char a;

	a = getchar();

	Judge(a);

	return 0;
}

void Judge(char a)
{
	if( a  >= 65 &&  a  <= 90)
			printf("您输入的 是大写字母！\n");
	else if( a  >= 97 &&  a  <= 122)
			printf("您输入的 是小写字母!\n ");
	else if( a  >= 48 &&  a  <= 57)
			printf("您输入的 是数字！\n");
	else 
			printf("您输入的 是其他字符!\n");
}
