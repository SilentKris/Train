#include <stdio.h>

int SumOfFactorial(int);

int main(int argc, char **argv)
{
	int i, sum;
	printf("请输入要计算的阶乘和\n");	
	scanf("%d", &i);

	sum = SumOfFactorial(i);
	printf("阶乘和为%d\n", sum);
		return 0;
}

int SumOfFactorial(int n)
{
	int i=1, sum=n;
	
	while(i < n)
	{
		sum *= i++;
		
	}
	if(n > 1)
		sum += SumOfFactorial(n-1);
	return sum;
}
