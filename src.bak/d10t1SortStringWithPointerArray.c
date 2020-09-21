#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *p[5] = {"hello", "world", "hi", "student", "good morning" };
	char *temp;
	int i, j;

	for(i=0; i<5; i++)
	{
		for(j=0; j<4-i; j++)
		{
			if(strlen(p[j+1]) < strlen(p[j]))
			{
					temp = p[j+1];
					p[j+1] = p[j];
					p[j] = temp;
			}
		}
		puts(p[j]);
	}


	return 0;
}
