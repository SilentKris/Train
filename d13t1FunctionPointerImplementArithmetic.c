#include <stdio.h>


int Plus(int a, int b);
int Sub(int a, int b);
int Multi(int a, int b);
int Div(int a, int b);

int main(int argc, char **argv)
{
	int (*p[5])(int a, int b) = {Plus, Sub, Multi, Div};
	printf("%d\n", p[0](2, 1));
	printf("%d\n", p[1](2, 1));
	printf("%d\n", p[2](2, 1));
	printf("%d\n", p[3](2, 1));


	return 0;
}


int Plus(int a, int b)
{
	return a+b;
}

int Sub(int a, int b)
{
	return a-b;
}

int Multi(int a, int b)
{
	return a*b;

}

int Div(int a, int b)
{
	return a/b;
}
