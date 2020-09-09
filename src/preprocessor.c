#include <stdio.h>

//FILE:进行编译的源文件名
//文件当前的行号
//文件被编译的日期
//文件被编译的时间
//是否遵循ANSI C，是为1

int main(int argc, char **argv)
{

	printf("%s, %d, %s, %s, %d\n", __FILE__, __LINE__, __DATE__, __TIME__, __STDC__);

	return 0;
}
