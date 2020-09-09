#include <stdio.h>
#include <string.h>
#include <errno.h>


int main(int argc, char **argv)
{
	FILE *fp;

	fp = fopen(argv[1], "r");
	if(NULL == fp)
	{
		perror(argv[1]);
		return -1;
	}

	int fmp;
	while(EOF != (fmp = fgetc(fp)))
	{
		fputc(fmp, stdout);
	}

	printf("输出结束\n");

	fclose(fp);


	return 0;
}
