#include <stdio.h>
#include <stdbool.h>

void JudgeSpecialNumber(int num);


int main(int argc, char **argv)
{
	int num;
	printf("请输入一个整数: ");
	scanf("%d", &num);

	JudgeSpecialNumber(num);


	return 0;
}

bool PerfectNumber(int num)
{
	int i = num, sum=0;
	while(--i >= 1)
	{
		if(0 == num % i)
			sum += i;
	}
	if(num == sum)
		return true;
	else 
		return false;
}

bool Prime(int num)
{
	int i = num;
	while(--i > 1)
		if(0 == num % i)
			return false;
	return true;
}

bool Daffodils(int num)
{
	int i, mid[3],  sum=0;
	mid[0] = num / 100;
	mid[1] = num % 100 / 10;
	mid[2] = num % 10;
	for(i=0; i<3; i++)
	{
		sum += mid[i] * mid[i] * mid[i];
	}
	if(sum == num)
		return true;
	else 
		return false;

}

bool OddOrEven(int num)
{
	if(num % 2)
		return true;
	else 
		return false;
}

void JudgeSpecialNumber(int num)
{
	if(PerfectNumber(num))
		printf("该数为完数\n");
	if(Prime(num))
		printf("该数为素数\n");
	if(Daffodils(num))
		printf("该数为水仙花数\n");
	if(OddOrEven(num))
		printf("该数为奇数\n");
	else
		printf("该数为偶数\n");

}
