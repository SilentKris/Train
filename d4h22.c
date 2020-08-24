/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily4_homework22.c
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
		unsigned int Input,Odd_count = 0, Enum_count = 0;
		unsigned int Odd_sum = 0, Enum_sum = 0;
		double Odd_ave,  Enum_ave;
		printf("请输入字符：");
		while((Input=getchar()-48) != 0)
		{
				if(Input > 0 && Input <= 9)
				{
						if(Input % 2)
						{
								Odd_sum += Input;
								Odd_count++;
						}
						else
						{
								Enum_sum += Input;
								Enum_count++;
						}
				}
				if((Input + 48) == '\n')
					printf("未检测到0，请继续输入字符：");
		}
		Odd_ave = (double)Odd_sum / Odd_count;
		Enum_ave = (double)Enum_sum / Enum_count;
		printf("输入偶数有%d 个，平均值为%lf;\n输入奇数有%d 个，平均值为%lf\n", Enum_count, Enum_ave, Odd_count, Odd_ave);
		return 0;
}
