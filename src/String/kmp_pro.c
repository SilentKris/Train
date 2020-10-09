#include <stdio.h>
#include <string.h>

#define N 256
void get_next(char *buf, int *next);
void get_pos(char *buf1, char *buf2);

/*相对于原版的kmp算法，升级版的kmp算法在性能上有了提升，简化了next数组，对于与前缀元素重复的后缀字符，也将其对应的next值改为和对应前缀的next值相同的值*/



int main()
{
	int i = 0;
	char buf1[N];
	char buf2[N];
	int next[N];
	bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));

	fgets(buf1, sizeof(buf1), stdin);
	fgets(buf2, sizeof(buf2), stdin);

	get_pos(buf1, buf2);

	return 0;
}

void get_next(char *buf, int *next)
{
	int len = strlen(buf);
	int i = 0;
	int j = -1;
	next[i] = -1;

	while(i < len)
	{
		if(j == -1 || buf[i] == buf[j])
		{
			++i;
			++j;
#if 0
			next[i] = j; //原版kmp算法
#endif
			if(buf[i] != buf[j])  //升级版kmp算法
				next[i] = j;
			else
				next[i] = next[j];
		}
		else 
			j = next[j];
	}
}


void get_pos(char *buf1, char *buf2)
{
	int next[N];
	int i = 0, j;
	get_next(buf2, next);

	int len1 = strlen(buf1)-1;
	int len2 = strlen(buf2)-1;

	i = j = -1;

	while(i < len1 && j < len2)
	{
		if(j == -1 || buf1[i] == buf2[j])
		{
			++i;
			++j;

		}
		else
			j = next[j];
	}
	if(i == len1 && j < len2)
		printf("匹配失败\n");
	else
		printf("位置为%d\n", i - len2);


}
