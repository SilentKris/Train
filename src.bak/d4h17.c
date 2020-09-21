/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily4_homework17.c
 *   创 建 者:  dwl
 *   创建日期：2020/08/14
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include <stdio.h>

int main()
{
		unsigned int year;
		char flag = 0, m;
		printf("请输入要判断的年份: ");
		while(!flag)
		{
				flag = scanf("%u", &year);
				while(getchar() != '\n');
				if(!flag)
						printf("您输入的格式不正确，请重新输入:");
		}

		if(!(year % 4))
				if(!(year % 100) && !(year % 400))

						printf("%u 不是闰年\n", year);
				else 
						printf("%u 是闰年\n", year);
		else 
				printf("%u 不是闰年\n", year);

		return 0;

}
