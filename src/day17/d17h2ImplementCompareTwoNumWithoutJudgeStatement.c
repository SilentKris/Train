#include <stdio.h>

int Compare(int Num1, int Num2);

int main(int argc, char **argv)
{
	int Num1, Num2, Max;
	scanf("%d%d", &Num1, &Num2);

	Max = Compare(Num1, Num2);
	printf("The Max Num is %d\n", Max);

	return 0;
}

int Compare(int Num1, int Num2)
{
	int Max, result;
	
	result = Num1 - Num2;
	Max = Num1;
	result = (unsigned int)result >> 31;
#if 0	
	while(result)
	{
		Max = Num2;
		result--;
	}
	return Max;
#else 
	return (result ^ 1)*Num1 + (result ^ 0)*Num2;
#endif
}
