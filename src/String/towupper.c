#include <stdio.h>
#include <wctype.h>
int main(int argc, char **argv)
{
 	const char *buf = "hello";
	char  b[] = towupper();
	
	puts(b);
	return 0;
}
