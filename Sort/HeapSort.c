#include <stdio.h>

void swap(int *, int, int);
//heapify 是从上往下n代表树中有多少个节点
void heapify(int tree[], int n, int i);// 
void build_heap(int tree[], int n);
void heap_sort(int tree[], int n);

int main(int argc, char **argv)
{
	int tree[] = {2, 5, 3, 1, 10, 4};
	int n = 6;

//	build_heap(tree, n);i
	//	heapify(tree, n, 0);
	heap_sort(tree, n);
	int i = 0;
	for(i  = 0; i < n; i++)
		printf("%d\n",tree[i]);	

	return 0;
}
// tree 为数组
// n 为数组元素个数-1（即数组尾部索引值）
// i 为父节点的索引值
//max为一个最小二叉树单元中数值最大的索引值
void heapify(int tree[], int n, int i){
	int c1 = 2 * i + 1;
	int c2 = 2 * i + 2;
	int max = i;
	if(i >= n){
		return ;
	}
	//如果子节点的索引值没有超过数组元素个数，并且子节点的值大于父节点的值，那么将索引值放到manx中
	if(c1 < n && tree[c1] > tree[max]){ 
		max = c1;	
	}

	if(c2 < n && tree[c2] > tree[max]){
		max = c2;	
	}

	if(max != i){
		swap(tree, max, i);
		heapify(tree, n, max);
	}

}

void swap(int tree[], int max, int i)
{
	int temp;
	temp = tree[max];
	tree[max] = tree[i];
	tree[i] = temp;
}

void build_heap(int tree[], int n){
	int last_node = n -1;
	int parent = (last_node -1) / 2;
	int i;
	for(i = parent; i >=0; i--)
		heapify(tree, n, i);
}
void heap_sort(int tree[], int n){
	build_heap(tree, n);
	int i;
	for(i = n - 1; i >= 0; i--){
		swap(tree, i, 0);
		heapify(tree, i, 0);
	}

}

