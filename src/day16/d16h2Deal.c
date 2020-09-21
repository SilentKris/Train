#include <stdio.h>
#include <stdlib.h>

#define N 20

void Color(int);
int main(int argc, char **argv)
{
	int arr[N] = {0}, Num, random, count=0; 
	int s[N][4] = {0}, cal_count=0; 
	srand(time(NULL));

	while(1)
	{
		Num = rand()%13+1;  //创建 1-13 的随机数

		random = rand()%4; //创建花色的随机数

		//当某一张牌出现少于四次且该牌花色没有重复进行如下操作
		if((arr[Num] + 1 <= 4) && s[Num][random] != 1)
		{
			arr[Num]++;

			printf("给你发的第%d 张牌是", ++count);
			Color(random);	
			printf("%d\n", Num);

			s[Num][random] = 1;

			if(52 == count) 
			{
				printf("发牌结束\n");
				return 0;
			}
		}
	}
}

void Color(int num)
{
	switch(num)
	{
		case 0: printf("黑桃");break;
		case 1: printf("红桃");break;
		case 2: printf("方块");break;
		case 3: printf("梅花");break;
	}
}
