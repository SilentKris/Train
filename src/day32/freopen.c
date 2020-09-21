#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fp = freopen(argv[1], "w+", stdin);	

	printf("hello world!, %d\n", *fp);

	fclose(stdin);


	return 0;
}
