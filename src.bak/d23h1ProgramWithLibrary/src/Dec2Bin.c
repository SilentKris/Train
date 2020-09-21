#include <stdio.h>

void Dec2Bin(void)
{
	int bit, i, num;
	printf("\n******十进制数转换成二进制数*********\n");
	printf("请输出要进行转换的数字:");
	scanf("%d", &num);
	for(i=31; i>=0; i--)
	{
		bit = num & (1<<i);
		bit >>= i;
		printf("%d", bit);
	}
	putchar('\n');
}

