#include <stdio.h>
#include <string.h>

#define N 256

int my_strcmp(char *buf1, char *buf2);

int main(int argc, char **argv)
{
	char buf1[N] = "hel";
	char buf2[N] = "x";

	int ret = my_strcmp(buf1, buf2);

	printf("ret = %d\n", ret);

	return 0;
}


int my_strcmp(char *buf1, char *buf2)
{
	int i = 0;
	int flag = 0;
	while(buf1[i])
	{
		if(buf1[i] == buf2[i])
		{
			i++;
			flag = 1;
		}
		else
		{
			if(flag)
				return 1;
			else 
				return -1;
		}
	}
	if(buf2[i] != '\0')
		return -1;
	else 
		return 0;

}
