/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_homework21.c
*   创 建 者:  dwl
*   创建日期：2020/08/15
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>

int main()
{
	char Input, Num_count = 0;
	printf("Please input character: ");
	while((Input = getchar()) != '\n')
			if(Input >= '0' && Input <= '9')
					Num_count++;
	printf("The number of digits is %d\n", Num_count);

	return 0;
	
}
