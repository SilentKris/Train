#include <stdio.h>

#define min(x,y) ({typeof(x) _x = (x); typeof(y) _y = (y); (void)(&_x == &_y); _x < _y ? _y : _x;})

#define my_min(x, y) (x < y ? x : y)


int main(int argc, char **argv)
{
	int c;
	typeof(c)  a = 8; typeof(c) b = 8;
	int Max = min(a++, b);
	int Max_1 = my_min(a--, b--);

	printf("Max = %d, Max_1 = %d\n", Max, Max_1);
	
	return 0;
}
