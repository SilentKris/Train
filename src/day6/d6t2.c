/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily6_test2.c
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
	int Pos_order[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int Rev_order[10] = {0};
	int count = 9;

	for(; count >=0; count--)
	{
		Rev_order[9-count] = Pos_order[count];
	}
	for(count = 0; count < 10; count++)
		printf("%d ", Pos_order[count]);
			putchar('\n');
	for(count = 0; count < 10; count++)
		printf("%d ", Rev_order[count]);
	putchar('\n');

	return 0;

}
