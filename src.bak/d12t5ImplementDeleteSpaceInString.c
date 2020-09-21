#include <stdio.h>


char * DeleteSpace(char *str);

int main(int argc, char **argv)
{
	char str[200];
	
	
	gets(str);
	puts("********************");
	puts(DeleteSpace(str));


	return 0;
}

char * DeleteSpace(char *str)
{
	char *p, *q;
	p = q = str;
	while(*p)
	{
		if(*q != ' ')
			*p++ = *q;
		*q++;
	}
	
	return str;
}
