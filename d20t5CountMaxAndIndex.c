#include <stdio.h>
struct number{
	int max;//最大值
	int node;//下标
};
void findmax ( int s[ ], int t, int *k,struct number *p )
{
	p -> max = 0;
	p -> node = 0;
	*k = 0;
	while(*k < 10)
	{
		if(p -> max < s[*k])
		{
			p -> max = s[*k];
			p -> node = *k;
		}
		(*k)++;
	}





}

int main (void)
{
	int a[10] = {12, 23, 34, 45, 56, 67, 78, 89, 11, 22}, k;
	struct number arr;
	findmax ( a, 10, &k,&arr );
	printf("arr->max = %d\tarr->node=%d\n", arr.max, arr.node );//打印出结构体中的元素
	return 0;
}

