/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily5_homework4.c
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
	int Num, bit, bit_count;
	int Sum=0, count;
	int mul;
	printf("Please input the Num:");
	scanf("%d", &Num);
	printf("Please input the lenght:");
	scanf("%d", &bit);
	for(; bit > 0; bit--)
	{
		if(1 == bit_count)
			Sum += Num;
		else
		{
			for(bit_count = bit; bit_count>=1; bit_count--)
			{
				for(mul = Num, count = 1; count < bit_count; count++)
				{
					mul *= 10;
					printf("mul = %d\n", mul);
				}
				Sum += mul;
			}
		}
	}
	printf("总数是%d\n", Sum);

	return 0;
}
