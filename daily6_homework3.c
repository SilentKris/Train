#include <stdio.h>
#define MAX 5


int main()
{
	int arr[MAX], Num = MAX;
	int Min=0, Max=0, Min_index, Max_index;
	int count;

	printf("请输入%d个数字：", Num);
	for(count = 0; count < MAX; count++)
		scanf("%d", &arr[count]);

#if 0

	if(arr[0] >= arr[1])
	{
		Max = arr[0];
		Max_index = 0;
		Min = arr[1];
		Min_index = 1;
	}	
	else
	{
		Min = arr[0];
		Min_index = 0;
		Max = arr[1];
		Max_index = 1;
	}
	for(count = 2; count < MAX; count++)
	{
		if(arr[count] > Max)
		{
			Max = arr[count];
			Max_index = count;
		}
		else if(arr[count] < Min)
		{
			Min = arr[count];
			Min_index = count;
		}
	}
#else
	for(count=0; count<MAX; count++)
	{
		if(arr[Max] < arr[count])
			Max = count;
		if(arr[Min] > arr[count])
			Min= count;
	}
#endif
	printf("遍历该数组为：arr[%d] = ", Num);
	for(count = 0; count < MAX; count++)
	{
		printf("%-5d", arr[count]);
	}
	putchar('\n');
//	printf("Max = %d, Max_index = %d\nMin = %d, Min_index = %d\n", Max, Max_index, Min, Min_index);
	printf("arr[Max] = %d, Max = %d, arr[Min] = %d, Min = %d\n", arr[Max], Max, arr[Min], Min);
	


	return 0;
}
