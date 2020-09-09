#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
	int row_count=0;
	char s[3];
	FILE *fp = fopen(argv[1], "r");
	if(NULL == fp)
	{
		perror(argv[1]);
		return -1;
	}

	while(fgets(s, sizeof(s)-1, fp) != NULL)
	{
		if('\n' == s[strlen(s)-1])
			row_count++;
	}


	printf("row_count = %d\n", row_count);

	return 0;
}
