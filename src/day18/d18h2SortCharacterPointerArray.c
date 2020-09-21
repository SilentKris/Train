#include <stdio.h>
#include <string.h>
#define N 4
#define M 100

void  Inv_array(char *str[], int n);
char *Inv_string(char *);

int main()
{
	int i=0;
	char *str1[N] = {NULL};
	char str2[N][M] = {0};
	while(i<N)
	{
		gets(str2[i++]);
	}
	puts("********************");
	for(i=0; i<N; i++)
	{
		str1[i] = Inv_string(str2[i]);
	}
	Inv_array(str1, N);
	for(i=0; i<N; i++)
		puts(str1[i]);

	return 0;
}

void Inv_array(char *str[], int n)
{
	int i;
	char *temp;
	
	for(i=0; i<n/2; i++)
	{
		temp = str[i];
		str[i] = str[n-1-i];
		str[n-1-i] = temp;
	}
}

char * Inv_string(char *s2)
{
	int len, i;
	char temp;

	len = strlen(s2);
	
	for(i=0; i<len/2; i++)
	{
		temp = s2[i];
		s2[i] = s2[len-1-i];
		s2[len-1-i] = temp;
	}
	return s2;
}



