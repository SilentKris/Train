#include <stdio.h>

#if 0
 int a ;
static a; 这里会报错
#endif
int a = 10;
int main()
{
	printf("a = %d\n",a);
	return 0;
}
