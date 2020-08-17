/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：calc.c
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
	int a, b;
	int answer, remainder;
	printf("请输入被除数：");
	scanf("%d", &a);
	printf("请输入除数：");
	scanf("%d", &b);
	answer = a / b;
	remainder = a % b;
	printf("计算结果：%d / %d = %d……%d\n",a, b, answer, remainder);

	return 0;
}
