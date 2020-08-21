#include <stdio.h>
#include <stdlib.h>

#define N 20

void Swap(int tree[], int a, int b);
void Heapify(int tree[], int n, int i);
void Heap_built(int tree[], int n);
void Heap_sort(int tree[], int n);


int main(int argc, char **argv)
{
	int arr[N], i=N;
	int *p = arr;
	srand(time(NULL));
	while(i)
		arr[--i] = rand()%100;
	Heap_sort(arr, N);
	while(i++ < N)
		printf("%d\t", *p++);
	putchar('\n');


	return 0;
}

void Swap(int tree[], int a, int b)
{
	int temp;
	temp = tree[a];
	tree[a] = tree[b];
	tree[b] = temp;
}

void Heapify(int tree[], int n, int i)
{
	if(i >= n){
	return ;
	}

	int c1 = 2 * i + 1;
	int c2 = 2 * i + 2;
	int max = i;
	if(c1 < n && tree[c1] > tree[max]){
		max = c1;
	}
	if(c2 < n && tree[c2] > tree[max]){
		max = c2;
	}
	if(max != i){
		Swap(tree, max, i);
		Heapify(tree, n, max);
	}

}

void Heap_built(int tree[], int n){
	int last_node = n - 1;
	int parent = (last_node - 1) / 2;
	int i;

	for(i = parent; i >= 0; i--){
		Heapify(tree, n, i);
	}

}

void Heap_sort(int tree[], int n){
	int i;
	Heap_built(tree, n);
	for(i = n-1; i >= 0; i--){
		Swap(tree, i, 0);
		Heapify(tree, i, 0);
	}
}
