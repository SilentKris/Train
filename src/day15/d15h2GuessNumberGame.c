#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	srand(time(NULL));
	int Num,input;
	printf("欢迎来到猜数游戏！按c开始，按q退出 ");
	input = getchar();

	if('c' == input)
		while(1)
		{
			Num = rand()%10;
			while(1)
			{
				printf("请输入你的答案：");
			
				input = getchar() - '0';
				while(getchar() != '\n');
				if(input < Num)
					printf("小了\n");
				else if(input  > Num)
					printf("大了\n");
				else if(input == Num)
				{
					printf("答对了\n");
					break;
				}
			}
		
			printf("是否继续？按c继续，按q退出");
			input = getchar();
			if( 'q' == input)
				return 0;
		}
	if('q' == input)
		return 0;
}


