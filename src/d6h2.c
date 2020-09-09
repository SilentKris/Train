/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily6_homework2.c
*   创 建 者:  dwl
*   创建日期：2020/08/17
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>

#define MAX 100

int main()
{
	int Num_i, Num_j, Pr_count=0, Nu_count ;
	int Pr_num[MAX];

	for(Num_i = 101; Num_i <= 500; Num_i++)
	{
		for(Num_j = 2; Num_j < Num_i; Num_j++)
		{
			if(!(Num_i % Num_j))
				break;	
		}
		if(Num_j == Num_i)
			Pr_num[Pr_count++] = Num_i;
	}

	
	printf("满足要求的素数有%d 个\n", Pr_count);

	for(Nu_count = 0; Nu_count <Pr_count; Nu_count++)
		printf("%-4d", Pr_num[Nu_count]);
	putchar('\n');


	return 0;
}
