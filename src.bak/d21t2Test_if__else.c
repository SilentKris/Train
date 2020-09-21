#include <stdio.h>


int main()
{
	int i=22;

	if(i > 22)
		i--;
	else
		printf("i的值是%d\n", i);
	printf("i的值是%d(不是else输出的)\n", i);



	return 0;
}
