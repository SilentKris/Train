/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：calc_en.c
*   创 建 者:	farsight
*   创建日期：2020/08/12
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>


int main()
{
	int option;
	int a, b, answer;
	printf("请选择需要使用的功能：\n");
	printf("\t1.加法\n\r\t2.减法\n\r\t3.乘法\n\r\t4.除法\n\r\t5.取余\n");

	scanf("%d", &option);
	
	printf("请输入要进行计算的数值：");
	scanf("%d %d",&a, &b);
	switch(option)
	{
		case 1:answer = a + b;printf("%d + %d = %d\n", a, b, answer);break;
		case 2:answer = a - b;printf("%d - %d = %d\n", a, b, answer);break;
		case 3:answer = a * b;printf("%d * %d = %d\n", a, b, answer);break;
		case 4:answer = a / b;printf("%d / %d = %d\n", a, b, answer);break;
		case 5:answer = a % b;printf("%d %% %d = %d\n", a, b, answer);break;
		default:printf("该计算器无此功能，抱歉！！！\n");
	}

	return 0;
}
