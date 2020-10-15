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
	int temp ;

	/***************三数取中**************/
	int m = low + (high - low) / 2;
	if(L->r[low] > L->r[high])
		swap(L, low, high);  //保证low端最小
	if(L->r[m] > L->r[high]) //保证high最大
		swap(L, high, m);
	if(L->r[m] > L->r[low]) 
		swap(L, m, low);  // 此时low为中间值
	/*********************************/
	pivotkey = L->r[low]; //用第一个位置记录枢轴的值
	printf("%-3d", pivotkey);
	//temp = pivotkey;  //备份枢轴关键字，替换比交换的复杂度更小，等排序完成再将pivotkey 赋值给 low：
	while(low < high)
	{
		while(low<high && L->r[high]>=pivotkey)
			high--;
		L->r[low] = L->r[high];  //采用替换而不是交换
		while(low<high && L->r[low] <= pivotkey)
			low++;
		L->r[high] = L->r[low];
	}
	L->r[low] = pivotkey; //因为low位一直是与其他位重复的，且最后一定是大小值的中间位置，所以应该给赋值 pivotkey,

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
