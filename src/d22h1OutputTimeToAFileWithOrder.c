#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>

#define N 200

int main(int argc, char **argv)
{
	time_t t[N];
	time_t tim;
	int count = 1;

	FILE *fp = fopen(argv[1], "w+");
	if(NULL == fp)
	{
		perror(argv[1]);
		return -1;
	}

	fp = freopen(argv[1], "w+" , stdout);

	while(1)
	{

		tim = time(NULL);

		printf("%d	", count++);

		printf("%d年%d月%d日%d:%d:%d\n",localtime(&tim)->tm_year+1900,localtime(&tim)->tm_mon,localtime(&tim)->tm_mday,localtime(&tim)->tm_hour,localtime(&tim)->tm_min,localtime(&tim)->tm_sec);
		fflush(stdout);
		sleep(1);
	}
	fclose(fp);

	return 0;
}
