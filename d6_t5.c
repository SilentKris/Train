/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily6_test5.c
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
	char ch_arr[50] = {0};
	int count = 0;
	char diff;
	
	diff = 'a' - 'A';
	gets(ch_arr); //gets 危险，不识别边界
	puts(ch_arr);
	while((ch_arr[count]!='\0') && (count < 50))
	{
		if(ch_arr[count]>='a'&& ch_arr[count] <= 'z')
			ch_arr[count] -= diff;
		else if(ch_arr[count]>='A' && ch_arr[count]<='Z')
			ch_arr[count] += diff;
		count++;
	}
	puts(ch_arr);
	printf("有效字符是%d\n", count);

	return 0;
}
