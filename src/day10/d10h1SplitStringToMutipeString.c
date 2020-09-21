#include <stdio.h>
#include <string.h>
#define N 200

int main(int argc, char **argv)
{
	char *s[4];
	char ch[N];
	char *p = ch;
	int i = 0, flag=0;

	gets(ch);
	while(*p == ' ' || *p == '\0')
		p++;
	while(1)
	{
		if(*p != ' ')
		{
			s[i] = p;
			while(*p != ' ' && *p != '\0')
				p++;
			if(*p != '\0')
			{
				*p++ = '\0';
				i++;
			}
			else
			{
				for(i = 0; i < 4; i++)
					puts(s[i]);
				return 0;
			}
		}

	}

}
