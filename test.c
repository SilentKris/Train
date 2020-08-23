#include <stdio.h>
#include <string.h>
int main()
{
	char arr[10];
	char *p; 

	printf("arr = %p\n", arr);
	printf("&arr = %p\n", &arr);
	printf("arr + 1 = %p\n", arr+1);
	printf("&arr + 1 = %p\n", &arr + 1);

	
	return 0;

}
