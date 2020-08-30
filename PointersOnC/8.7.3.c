#include <stdio.h>

int main()
{
		int actual_data[ 20 ] = {10, 32, 2};
		int *data = actual_data - 1;

		printf(" *data = %d\n", data[-1]);
		printf(" *data = %d\n", data[-0]);
		printf(" *data = %d\n", data[1]);
		printf(" *data = %d\n", data[2]);
		printf(" *data = %d\n", data[-20000000]);

		return 0;
}
