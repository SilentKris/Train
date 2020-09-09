#include <stdio.h>

 void Dec2Bin(int num);


int main(int argc, char **argv)
{
	int num;
	printf("请输入要进行转换的数字：");
	scanf("%d", &num);
	Dec2Bin(num);
	

	return 0;
}

void Dec2Bin(int num)
{
	 int bit, i;
	for(i=31; i>=0; i--)
	{
		bit = num & (1<<i);
		bit >>= i;
		printf("%d", bit);
	}
	putchar('\n');
}
