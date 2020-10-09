#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 128


int BinSearch(int *p, int len, int key);

int main(int argc, char **argv)
{
	int i=0, pos;
	int a[N]; 
	srand((int)time(NULL));	

	for(; i<N; i++)
	{
		a[i] = rand()%100;
		printf("%-3d", a[i]);
	}
	putchar('\n');
	pos = BinSearch(a, N, 1);

	if(pos == -1)
		printf("所要查询的值不存在!\n");
	else
		printf("该值的位置是%d\n", pos);
	return 0;
}

//二分查找
int BinSearch(int *p, int len, int key)
{
	if(p == NULL || len <= 0)
		return -1;
	int low = 0; // 记录第一个元素的下标
	int high = len-1; //记录最后一个元素的下标
	int mid; //记录中间位置元素的下标

	while(low <= high)
	{
		mid = (low + high) / 2; //记录中间元素的位置
		if(key > p[mid]) // 如果key大于p[mid]，则key位于mid右边
			low = mid + 1; 
		else if(key < p[mid]) //如果key小于p[mid]，则移动high
			high = mid - 1;
		else 
			return mid;
	}
	return -1;
}
