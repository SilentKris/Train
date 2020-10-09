#include <stdio.h>
#include <string.h>
int ctoi(char *buf);

int main(int argc, char **argv)
{
	int sum;

	char buf[5] = "1231";
	sum = ctoi(buf);

	printf("sum = %d\n", sum);
	
	return 0;
}

int ctoi(char *buf)
{
	int len, i, sum;
	len = strlen(buf);
	sum = buf[0] - '0';
	for(i=1; i<len; i++)
	{
		sum = sum*10 + (buf[i] - '0');
	}

	return sum;
}
