/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_homework24.c
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
	unsigned int Input, count = 0;
	unsigned int result, remainder;
	int bit_count,bit;
	printf("请输入一个整数:");
	scanf("%u", &Input);
	result = Input;
#if 0
	while(result != 0)
	{
		if((remainder = result%2))
			count++;
		result /= 2;
	}
#else 
	if(result != 0)
	{
		for(bit_count=31; bit_count >= 0; bit_count--)
		{
			bit = result & ((unsigned int)1 << bit_count);
			bit >>= bit_count;
			printf("%d", bit);
		}
		putchar('\n');
	}
#endif
	printf("该整数二进制形式中1的个数为%u\n", count);

	return 0;

}
