#include <stdio.h>

int main(int argc, char **argv)
{
	char c;
	while((c = getchar()) != 'h')
	{
		putchar(c);
	}
	ungetc(c, stdin);
	c = getchar();
	putc(c, stdout);


	return 0;
}


