#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *fp;
	fp = fopen("1.txt", "w+");

	if(NULL == fp)
	{
		perror("fopen fail");
		return -1;
	}
	printf("fopen ok before\n");

	freopen("1.txt", "w+", stdout);

	printf("after 1 here\n");
	printf("append\n");

	freopen("/dev/tty", "w+", stdout);

	printf("after 2  22\n");


	fclose(fp);
	return 0;
}
