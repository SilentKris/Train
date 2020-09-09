/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：daily5_homework5.c
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
	double m = 2.0, n = 1.0, t, sum;
	unsigned int count;
	for(sum=0, count=0; count<20; count++)
	{
		sum += m / n;
		t = m ;
		m = n + m;
		n = t;
	}
	printf("前20项之和为%lf\n", sum);


	return 0;
}
