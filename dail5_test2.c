/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：dail5_test2.c
*   创 建 者:  dwl
*   创建日期：2020/08/17
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>

#define month1 31
#define month3 31
#define month4 30
#define month5 31
#define month6 30
#define month7 31
#define month8 31
#define month9 30
#define month10 31
#define month11 30
#define month12 31

int main()
{
	unsigned int year, month, day, day_sum = 0;
	unsigned int month2;

	printf("Please input year.month.day:");
	scanf("%u.%u.%u", &year, &month, &day);

	if(!(year%4) || !(year%400))
	{	
		month2 = 29;		
	}
	else 
		month2 = 28;
	switch(month)
	{
		case 12: 
		case 11: day_sum += month11;
		case 10: day_sum += month10;
		case 9 : day_sum += month9;
		case 8 : day_sum += month8;
		case 7 : day_sum += month7;
		case 6 : day_sum += month6;
		case 5 : day_sum += month5;
		case 4 : day_sum += month4;
		case 3 : day_sum += month3;
		case 2 : day_sum += month2;
		case 1 : day_sum += month1;break;
		default:printf("是不是傻，没有这个月份!!!\n");
	}
	day_sum += day;
	printf("day_sum = %u\n", day_sum);
	
	return 0;
}
