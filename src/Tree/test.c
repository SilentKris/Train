#include <stdio.h>

typedef struct test{
	int i;
	struct test *p;
}test;

test *k;
int main(int argc, char **argv)
{

	if(!k->p) 
		printf("The value is NULL\n");
	else 
		puts("It has value!\n");
	

	return 0;
}
