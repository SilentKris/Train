#include <stdio.h>

int My_strlen(char *);

int main(int argc, char **argv)
{
	char s[20] = "hello world!";
	int count;

	count = My_strlen(s);

	printf("This string include %d charactor\n", count);


	return 0;
}

int My_strlen(char a[])
{
	char *p;
	int count=0;
	
	p = a;
	while(*p != 0)
	{
		count++;
		p++;
	}
	return count;

}
