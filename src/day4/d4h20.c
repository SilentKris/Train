/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：daily4_homework20.c
 *   创 建 者:  dwl
 *   创建日期：2020/08/15
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include <stdio.h>

int main()
{
		unsigned int Pnum, Pnum_count = 0, Inc_count, Sum;
		unsigned int Divisor;
		for(Inc_count = 1; Inc_count <= 1000; Inc_count++)
		{
				for(Sum=0, Divisor = Inc_count-1; Divisor > 0; Divisor-- )
						if( Inc_count % Divisor == 0)
								Sum += Divisor;
				if( Sum == Inc_count)
				{
						Pnum = Inc_count;
						Pnum_count++;
						printf("第%u 个完数是：%u\n", Pnum_count, Pnum);
				}


		}			
		return 0;
}
