/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：d7_h5_cmp_string.c
*   创 建 者:  dwl
*   创建日期：2020/08/19
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#define N 200

int main()
{
	char ch1[N], ch2[N];
	int i=0, j=0, count=0;

	
	printf("Please input a long string:\n");
	gets(ch1);
	printf("Please input 2-bit string you want to search:\n");
	gets(ch2);

	printf("The long string:");
	puts(ch1);
	printf("You want to search:");
	puts(ch2);

	while(ch1[i] != '\0')
	{
		if(ch1[i]==ch2[0] && ch1[i+1]==ch2[1])
		{
			count++;
		}
		i++;
	}

	printf("字符串ch1包含ch2的数量是%d\n", count);

	return 0;
}
