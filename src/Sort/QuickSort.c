#include <stdio.h>

typedef struct SqList{
	int *r;
	int length;
}SqList;

void QuickSort(SqList *L);
void QSort(SqList *L, int low, int high);
void swap(SqList *L, int a, int b);
int Partition(SqList *L, int low, int high);
void Traverse(SqList *L);

int main(int argc, char **argv)
{
	SqList list;
	SqList *L = &list;
	int num[] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
	L->r = num;
	L->length = sizeof(num)/sizeof(int)-1;
	QuickSort(L);
	Traverse(L);

	return 0;
}
void QuickSort(SqList *L)
{
	QSort(L, 0, L->length);
}

void QSort(SqList *L, int low, int high)
{
	int pivot;
	if(low < high)
	{
		pivot = Partition(L, low, high); 

		QSort(L, low, pivot-1);
		QSort(L, pivot+1, high);
	}
}

int Partition(SqList *L, int low, int high)
{
	int pivotkey;
	pivotkey = L->r[low]; //该语句是整个快排的性能瓶颈，如果这个枢轴选取的是极大或者极小值，则该快排的时间复杂度为最高
	while(low < high)
	{
		while(low<high && L->r[high]>=pivotkey)
			high--;
		swap(L, low, high);
		while(low<high && L->r[low] <= pivotkey)
			low++;
		swap(L, low, high);
	}

	return low;
}
void swap(SqList *L, int a, int b)
{
	int temp;
	temp = L->r[a];
	L->r[a] = L->r[b];
	L->r[b] = temp;
}
void Traverse(SqList *L)
{
	int i;
	for(i = 0; i < L->length; i++)
	{
		printf("%-3d", L->r[i]);
	}
	putchar('\n');
}
