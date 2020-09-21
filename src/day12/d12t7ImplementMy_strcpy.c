#include <stdio.h>
#define N 200
char *MyStrcpy(char *dest, char *src);


int main(int argc, char **argv)
{
	char a[N] = "hello world.";
	char b[N] = "hello student.";

	

	puts(MyStrcpy(a, b));


	return 0;
}

char *MyStrcpy(char *dest, char *src)
{
	char *a;
	a = dest;

	while(*dest++ = *src++);
	
	return a;
}
