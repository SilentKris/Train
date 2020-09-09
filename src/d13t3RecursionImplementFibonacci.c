#include <stdio.h>

int main(int argc, char **argv)
{

	int n;
	scanf("%d", &n);
	printf("%d\n", Fa(n));

	return 0;
}


int Fa(int n)
{
	if(n ==1 || n ==2)
		return 1;
	else 
		return Fa(n-1) + Fa(n-2);
}
