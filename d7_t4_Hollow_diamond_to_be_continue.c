/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：d7_t4.c
 *   创 建 者:  dwl
 *   创建日期：2020/08/18
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include <stdio.h>
#define N 1
#define M (2*N-1)
int main()
{

	char arr[M][N];
	int i, j, count;
	int blank, width;

	for(i=1; i<(M/2+1); i++)
	{
		width = 2 * i - 1;
		blank = (N - width) / 2;
		printf("width = %d, blank = %d\n", width, blank);
		for(j=0; j<(N); j++)
		{
			if(j==blank || j==N-blank)
				arr[i][j] = '*' ;
			else 
				arr[i][j] = ' ';
		}

	}
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			putchar(arr[i][j]);

		}
		putchar('\n');
	}



	return 0;
}
