#include <stdio.h>
#include <string.h>
#include <errno.h>
#define N 2999

int main(int argc, char **argv)
{
	int count = 3000;
	char *status;	
	char s[N] = {0};
	FILE *fp = fopen(argv[1], "w+");

	for(; count>0; count--)
	{
		fputc('1', fp);
	}

	rewind(fp);
	puts(s);
	while(1)
	{
		status = fgets(s, N+1, fp); //没有1024的限制
		if(feof(fp) != 0)
			break;
	}
	puts(s);
	printf("This is %ld characters\n", ftell(fp));
	if(NULL == status)
	{
		perror(argv[1]);
		printf("获取失败\n");
	}
	printf("feof = %d\n", feof(fp));
	printf("数组长度为%d\n", strlen(s));

	fclose(fp);


	return 0;
}
