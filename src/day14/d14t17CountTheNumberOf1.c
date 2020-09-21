#include <stdio.h>

int main(int argc, char **argv)
{
	int x;
	printf("请输入想计算的整数：");
	scanf("%d", &x);

	printf("%d中 1 的个数为%d\n", x, Count(x));


	return 0;
}

int Count(int x)
{
	int count;

	while(x)
	{
		count++;
		x = x & (x-1);
	}

	return count;
}
