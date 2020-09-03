#include <stdio.h>

int main(int argc, char **argv)
{
	char (*q)[100] = NULL;
	char  s[10][100], i=0;
	q = s;

	while(i < 10)
	{
		gets(*q);
		puts(*(q++));
		i++;
	}

	return 0;
}
