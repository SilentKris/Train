#include <stdio.h>


typedef enum{Link, Thread} Ponter;
typedef struct {
	int data;
	Ponter LTag;
}test;
int main(int argc, char **argv)
{
	test a;
	printf("a.LTag = %d\n", a.LTag);


	return 0;
}
