#include <stdio.h>

typedef struct Struction{
	char a; 
	int b;
	char c;
	short d;
	int e;

} Struct;

int main(int argc, char **argv)
{
	Struct i;
	printf("sizeof a = %d\n", (char *)&i.b - (char *)&i.a);
	printf("sizeof b = %d\n", (char *)&i.c - (char *)&i.b);
	printf("sizeof c = %d\n", (char *)&i.d - (char *)&i.c);
	printf("sizeof d = %d\n", (char *)&i.e - (char *)&i.d);
	printf("sizeof e = %d\n", (char *)&i+sizeof(i) - (char *)&i.e);


	return 0;
}

