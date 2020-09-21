/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：d7_h3_sort_string1.c
*   创 建 者:  dwl
*   创建日期：2020/08/19
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#define N 40

int main()
{
	int i, j;
	char ch[N] = {0}, t;
	printf("Please input a string:");
	gets(ch);
	puts(ch);

	for(i=N-1; i>=0; i--)
		for(j=0; j<i; j++)
		{
			if(ch[j] > ch[j+1])
			t = ch[j+1];
			ch[j+1] = ch[j];
			ch[j] = t;
		}
	puts(ch);


	
	return 0;
}
