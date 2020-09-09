#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
	time_t t;
	 
	t = time(NULL);

	printf("t = %s\n", &t);


	return 0;
}
