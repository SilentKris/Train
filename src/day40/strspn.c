#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	char buf1[100] = "hello world";
	char buf2[100] = "?";

	int i = strspn("wd", buf1);

	printf("i = %d, strlen(buf1) = %d\n", i, strlen(buf1));


	return 0;
}
