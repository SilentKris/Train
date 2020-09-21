#include <stdio.h>

void dice(void)
{
	int d1, d2, d3, d4, d5, d6;
	d1 = d2 = d3 = d4 = d5 = d6 = 0;

	srand((unsigned)time(NULL));

			d1 = rand()%6+1;
			d2 = rand()%6+1;
			d3 = rand()%6+1;
			d4 = rand()%6+1;
			d5 = rand()%6+1;
			d6 = rand()%6+1;

		printf("d1 = %d\nd2 = %d\nd3 = %d\nd4 = %d\nd5 = %d\nd6 = %d\n",d1, d2, d3, d4, d5, d6);
}
