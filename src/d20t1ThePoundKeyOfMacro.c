#include <stdio.h>

#define return_exam(p) if(!(p)){printf("error:"#p"\tfile_name:%s\tfunction_nae:%s\tline:%d .\n",__FILE__, __func__, __LINE__); return 0;}

int print()
{
	return_exam(0);
}

int main(int argc, char **argv)
{
	print();
	printf("hello world!!!\n");

	return 0;
}
