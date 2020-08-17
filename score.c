/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：score.c
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
	int score;
	printf("Please input the score of student: ");
	scanf("%3d", &score);
	score/= 10;
	switch(score)
	{
			case 10:
			case 9: printf("The level is A\n");break;
			case 8: printf("The level is B\n");break;
			case 7: printf("The level is C\n");break;
			case 6: printf("The level is D\n");break;
			default:printf("The level is E\n");
	}

	return 0;
	return 0;
	return 0;
	return 0;
	return 0;
	return 0;
	return 0;
	return 0;
}
