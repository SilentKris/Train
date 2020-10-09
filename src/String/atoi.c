#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	const char *buf = "10dsda0fa0a";//atoi只识别数字，遇到字母结束

	int ret = atoi(buf);

	printf("ret = %d\n", ret);


	return 0;
}
