#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 256

char *GetLongestString(char *buf);

int main(int argc, char **argv)
{
	char buf[N];
	
	bzero(buf, sizeof(buf));

	fgets(buf, sizeof(buf), stdin);
	char *ret = GetLongestString(buf);

	puts(ret);

	return 0;
}

char *GetLongestString(char *buf)
{
	int len = strlen(buf);
	if(len == 0)
	{
		fprintf(stderr, "string is empty!\n");
		return buf;
	}
	int index, Max, count;
	char val;
	char *phead, *ptail;

	index =  count = 0;
	val = buf[0];
	phead = ptail = &buf[0];
	Max = 1;


	while(buf[index])
	{
		if(Max < count)
		{
			Max = count;
			phead = &buf[index-count];  //指向的是最长字符串的首位置
			ptail = &buf[index];  		//指向是最长字符串目前的尾位置的下一个
		}

		if(buf[index] == val)
		{
			count++;
			index++;
			continue;
		}
		val = buf[index];
		count=0;
	}
	
	*ptail = '\0';
	return phead;
}
