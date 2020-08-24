#include <stdio.h>
#include <string.h>
int main()
{
	char s[64] = {"hello world mone student"};
	char *p[4] = {0};
	int i = 0, j = 0;

	if(s[0] != ' ')
	{
		p[j] = &s[0];
		i++;
		j++;
	}
	
	while(s[i] != '\0')
	{
		if(s[i] != ' ' && (s[i-1] == '\0' || s[i-1] == ' '))
		{
			p[j] = &s[i];
			j++;
		}
		if(s[i] == ' ' && s[i-1] != ' ')
		{
			s[i] = '\0';
		}
		if(s[i+1] != '\0')
			i++;
		else
			break;
		
	}
	for(i=0; i<4; i++)
		puts(p[i]);

	return 0;

}
