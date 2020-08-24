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
#define N 200

int main()
{
	char ch[N], t;
	int i, j;

	printf("Please input a string:");
	gets(ch);
	printf("原始字符串:\n");
	puts(ch);

	for(i=strlen(ch)-1; i>=0; i--)
		for(j=0; j<i; j++)
		{
			if(ch[j] > ch[j+1])
			{
				t = ch[j+1];
				ch[j+1] = ch[j];
				ch[j] = t;
			}
		}
	printf("排序完成后:\n");
	puts(ch);
	i = 0;
	j = 0;
	while(ch[i] != '\0')
	{
		t = ch[i];
		if(ch[j+1] == t)
		{
			ch[i] = ch[++j];
		}
		else
		{
			ch[++i] = ch[++j];
			
		}

	}
	printf("删除重复值后:\n");
	puts(ch);

	return 0;
}
