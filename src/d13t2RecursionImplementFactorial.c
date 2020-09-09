#include <stdio.h>

int main(int argc, char **argv)
{
	int n;
	scanf("%d",&n);

	printf("%d\n", Factorial(n));
	

	return 0;
}


int Factorial(int n)
{
	int sum=n;

	if(n > 1)
		sum *=	Factorial(n-1);
	
	else 
		sum = 1;

	return sum;

}
