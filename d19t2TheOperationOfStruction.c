#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE)0)->MEMBER)

typedef struct Struction{
	char a;  //1 B 
	char b;  //3 B
	int c;   //4 B 
	double d;//8 B
	int e;

} Struct, *p;

int main(int argc, char **argv)
{
	Struct i;
	Struct *h;
	printf("the offset of d = %d\n", offsetof(p, d));
	printf("sizeof a = %d\n", (char *)&i.b - (char *)&i.a);
	printf("sizeof b = %d\n", (char *)&i.c - (char *)&i.b);
	printf("sizeof c = %d\n", (char *)&i.d - (char *)&i.c);
	printf("sizeof d = %d\n", (char *)&i.e - (char *)&i.d);
	printf("sizeof e = %d\n", (char *)&i+sizeof(i) - (char *)&i.e);


	return 0;
}

