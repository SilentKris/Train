#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 50

bool My_strcmp(char str1[], char str2[]);
void Pos_Sort(char str[]);
void Inv_Sort(char str[]);

int main()
{
	char str1[N], str2[N], flag;

	gets(str1);
	gets(str2);

	flag = My_strcmp(str1, str2);
	if(flag)
	{
		Pos_Sort(str1);
		Inv_Sort(str2);
	}
	else
	{
		Pos_Sort(str2);
		Inv_Sort(str1);
	}

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

void Pos_Sort(char str[])
{
	int i=0, j=0;
	char temp;
	for(; i < strlen(str); i++)
		for(; j < strlen(str) - i - 1; j++)
		{
			if(str[j+1] < str[j])
			{
				temp = str[j+1];
				str[j+1] = str[j];
				str[j] = temp;
			}
		}
	puts(str);
}
void Inv_Sort(char str[])
{
	int i=0, j=0;
	char temp;
	for(; i < strlen(str); i++)
		for(; j < strlen(str) - i - 1; j++)
		{
			if(str[j+1] > str[j])
			{
				temp = str[j+1];
				str[j+1] = str[j];
				str[j] = temp;
			}
		}
	puts(str);
}

