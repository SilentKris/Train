#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;

	for(; i < 5; i++)
	{
		if(3 == i)	
			break;
	}
	printf("i = %d\n", i);


	return 0;
}
