
#include <stdio.h>
#include <string.h>

#define N 200

int chnum(char *);

int main(int argc, char **argv)
{
	printf("请输入只包含整数字符的字符串，若有负号，请置于第一位: ");
	char ch[N];
	int Result;
	gets(ch);
	puts(ch);
	
	Result = chnum(ch);

	printf("The result in Dec is %d\n", Result);

	return 0;
}


int chnum(char ch[])
{
	int len, i, sum = 0;
	char *q;

	len = strlen(ch);
	q = ch;

	while(*q != '\0'){
		if(*q - 48 >=0 && *q - 48 <= 9){
			*q -= 48;
		}

		q++;
	}

	for(i=0; i<len; i++)
	{
		if( 0 == i && ch[0] != '-')
		{
			sum = ch[0];
		}
		if( 0 != i && ch[0] != '-')
		{
			sum *= 10;
			sum += ch[i];
		}
		if( ch[0] == '-')
		{
			if(1 == i)
				sum = ch[1];
			else
			{
				sum *= 10;
				sum += ch[i];
			}
		}
		
	}
	if(ch[0] == '-')
		sum *= -1;

	return sum;

}


