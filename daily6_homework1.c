#include <stdio.h>
#define MAX 10

int main()
{
	int score[MAX] = {0};
	int i, j, t, count, sum = 0;
	double ave;

	printf("请输入该青年的评分：\n");
	for(count = 0; count <MAX; count++)
		scanf("%d", &score[count]);

	
	for(i = MAX-1; i > 0; i-- )
		for(j = 0; j < i; j++)
		{
			if(score[j] > score[j+1])
			{
				t = score[j+1];
				score[j+1] = score[j];
				score[j] = t;
			}
		}
	for(count = 1; count < MAX-2; count++)
	{
		sum += score[count];
	}
	ave = (double)sum/8;
	printf("去掉一个最高分%d,去掉一个最低分%d,该青年的平均分为%lf\n", score[9], score[0], ave);

	return 0;

}

