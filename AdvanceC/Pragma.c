#include <stdio.h>

#define Num

int main(int argc, char **argv)
{

	printf("test\n");
#ifdef Num
#pragma message("Num is defined!\n")
#endif
#ifndef Num
#pragma message("Num is no defined!\n")
#endif

	return 0;
}
