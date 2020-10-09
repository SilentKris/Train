#include <string.h>
#include <stdio.h>


int main()
{
	
	const char *buf1 = "happaz";
	const char *buf2 = "happy"; //前4个字符相同后,a < y，则strcmp认为buf1<buf2

	int ret = strcmp(buf1, buf2);

	printf("ret = %d\n", ret);
	return 0;
}
