#include <stdio.h>

#define N 256

int GetIndex(char *buf, char val);

int main(int argc, char **argv)
{
	char buf[N] = "hello world!";
	int index;

	index = GetIndex(buf, 'w');
	printf("the %c is the %d charactor in \"%s\"\n", 'w', index, buf);

	return 0;
}

int GetIndex(char *buf, char val)
{
	int index=0;

	while(buf[index])
	{
		if(buf[index] == val)
			return index;
		index++;
	}

	fprintf(stderr, "The value is not exist!\n");
	return -1;
}
