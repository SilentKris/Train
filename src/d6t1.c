/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily6_test1.c
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
	unsigned int array[32]={0};
	unsigned int Num;
	int count = 31;
	char bit;

	printf("请输入一个整数:");
	scanf("%u", &Num);
	while(Num)
	{
		bit = Num % 2;
		Num /= 2;
		array[count] = bit;
		count--;
	}
	for(count = 0; count <32; count++)
		printf("%d", array[count]);
	putchar('\n');

	return 0;
}
