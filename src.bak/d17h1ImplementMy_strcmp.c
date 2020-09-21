#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 50

bool My_strcmp(char str1[], char str2[]);

int main()
{
	char str1[N], str2[N], flag;
	
	gets(str1);
	gets(str2);

	flag = My_strcmp(str1, str2);
	if(flag) 
		printf("两字符串相同\n");
	else 
		printf("两字符串不同\n");
	return 0;
}

bool My_strcmp(char str1[], char str2[])
{

	if(strlen(str1) == strlen(str2))
	{
		while(*str1++ == *str2++)
			if(*str1 == '\0')
				return true;
		return false;
	}

	else
		return false;
}
