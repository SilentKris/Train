#include <stdio.h>
#define N 200

int *CaseCount(char s[], int Count[]);

int main()
{
	char s[N] = {0};
	int Count[2] = {0}, *p = NULL;

	gets(s);
	
	p = CaseCount(s, Count);

	printf("The number of lower case is %d\n", Count[0]);
	printf("The number of upper case is %d\n", Count[1]);
	return 0;
}

int *CaseCount(char s[], int Count[] )
{
	
	while(*s)
	{
		if(*s >= 'a' && *s <= 'z')
			Count[0]++;
		if(*s >= 'A' && *s <= 'Z')
			Count[1]++;
		s++;
	}
	return Count;
}
