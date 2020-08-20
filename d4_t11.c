/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily4_test11.c
*   创 建 者:  dwl
*   创建日期：2020/08/13
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>


int main()
{
	int count = 0, num = 0;
	printf("while循环实现\n");
	while(++count <= 100)
			num += count;
	printf("前100个数之和为%d\n", num);

	printf("for循环实现\n");
	for(count = 1, num = 0;count <= 100; count++)
			num += count;
	printf("前100个数之和为%d\n", num);
	printf("do……while实现\n");
	count = 1;
	num = 0;
	do 
	{	
		num += count;
	}while(++count <= 100);
	printf("前100个数之和为%d\n", num);

	return 0;
}
