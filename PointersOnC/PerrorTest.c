#include <stdio.h>
#include <errno.h>

int main()
{
	FILE *f;
	f = fopen("ke", "r");
	if(f == NULL)
		perror("errno");

	return 0;


}
