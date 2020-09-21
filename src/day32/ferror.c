
#include <stdio.h>
int main()
{
	FILE *fp;
	char c;
	fp = fopen("file.txt", "w");
	c = fgetc(fp);
	if( ferror(fp) )
	{
		printf("读取文件：file.txt 时发生错误\n");
	}
//	clearerr(fp);
	if( ferror(fp) )
	{
		printf("读取文件：file.txt 时发生错误\n");
	}
	fclose(fp);
	return(0);
}
