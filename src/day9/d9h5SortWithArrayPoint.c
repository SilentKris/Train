#include <stdio.h>
#include <stdlib.h>
#define N 5

void Sort(int arr[], int n);

int main(int argc, char **argv)
{
	int arr[N][N];
	int (*p)[N];
	int i, j;
	srand(time(NULL));

	p = arr;

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			arr[i][j] = rand() % 100;
			printf("%-3d", arr[i][j]);
		}
		putchar('\n');
	}
	while(p < arr + N){
		Sort(*p++, 5);
	}

	printf("排序后\n");

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%-3d", arr[i][j]);
		}
		putchar('\n');
	}
		return 0;
	
}


void Sort(int arr[], int n){
	int i, j, t;

	for(i = 0; i < n; i++)
		for(j = 0; j < n-i-1; j++){
			if(arr[j + 1] < arr[j]){
				t = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = t;
			}
		}

}
