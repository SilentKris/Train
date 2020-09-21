#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fp;
	fp = fopen("xclipmanual", "r+");

	if(NULL == fp)
	{
		perror("xclip");
		return -1;
	}

	fprintf(stdout, "nihao");
	fclose(fp);

	while(1);


	return 0;
}
