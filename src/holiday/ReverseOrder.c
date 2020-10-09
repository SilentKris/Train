#include <stdio.h>
#include <string.h>

#define N 256

char *ReverseOrder(char *buf);

int main(int argc, char **argv)
{
	char buf[N] = "12345678";

	ReverseOrder(buf);

	puts(buf);


	return 0;
}

char *ReverseOrder(char *buf)
{
	int len = strlen(buf);
	
	if(0 == len)
	{
		fprintf(stderr, "string is empty!\n");
		return buf;
	}

	char *ptail, *phead;
	phead = &buf[0];
	ptail = &buf[len-1];
	while(phead < ptail)
	{
		*phead ^= *ptail;
		*ptail ^= *phead;
		*phead ^= *ptail;
		
		phead++;
		ptail--;

	}
	return buf;
}
