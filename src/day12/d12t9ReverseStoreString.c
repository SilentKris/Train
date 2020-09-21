#include <stdio.h>
#define N 200
char *Reverse(char dest[], char src[]);

int main(int argc, char **argv)
{
	char new[N];
	char old[N] = "hello world!";
	puts(old);	
	puts( Reverse(new, old));

	return 0;
}

char *Reverse(char dest[], char src[])
{
	char *a = src;
	char *b = dest;

	while(*(++src));

	while(src > a)
		*dest++ = *--src;
	*dest = '\0';

	return b;
}
