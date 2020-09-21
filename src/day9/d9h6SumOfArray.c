#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	int arr[5][3];
	int (*p)[3];
	int i, j, sum = 0;
	
	srand(time(NULL));
	p = arr;

	for(i = 0; i < 5; i++){
		for(j = 0; j < 3; j++){
			arr[i][j] = rand()%100;
			printf("%-3d", arr[i][j]);
		}
		putchar('\n');
	}


	printf("*********************************\n");
	while(p < arr + 5){
		sum = (*p)[0] + (*p)[1]+ (*p)[2];
		printf("第%d行的和为%d\n", p - arr, sum);
		p++;
		sum = 0;
	}


	return 0;
}
