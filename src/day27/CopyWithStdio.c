#include <stdio.h>
#include <string.h>

#define N 200


int main(int argc, char **argv)
{
	FILE *fp_r, *fp_w;
	char s[N] = {0}, *p;
	int size_w;
	
	
	fp_r = fopen(argv[1], "r");
	if(NULL == fp_r)
	{
		perror(argv[1]);
		return -1;
	}
	fp_w = fopen(argv[2], "w+");
	if(NULL == fp_w)
	{
		perror(argv[2]);
		return -1;
	}
	
	while(1)
	{
		p = fgets(s, sizeof(s)-1, fp_r);

		if(NULL == p)
		{
			fclose(fp_r);
			fclose(fp_w);
			return 0;
		}
	
		size_w = fputs(s, fp_w);
		
			
	}
}
