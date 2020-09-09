#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int char_count = 0;
	int row_count = 0;
	int ch;

	FILE *fp = fopen(argv[1], "r");
	if(NULL == fp)
	{
		perror(argv[1]);
		return -1;
	}
	
	while(EOF != (ch = fgetc(fp)))
	{
		if('\n' == ch)
			row_count++;	
		char_count++;
	}
	printf("行为%d, 字符数为%d\n", row_count, char_count);
	fclose(fp);

	return 0;
}
