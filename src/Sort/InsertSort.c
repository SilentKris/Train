#include <stdio.h>

int main(int argc, char **argv)
{



	return 0;
}

int insertSort(int *p, int len)
{
	if(NULL == p || len <=0)
		return -1;
	int temp;
	int i = 0; 
	int j; 
	
	for(i=1; i<len; i++)
	{
		temp = p[i];
		j = i-1;
		while(j >=0 && p[j] > temp)
		{
			p[j+1] = p[j];
			j--;
		}

		p[j+1] = temp;
	}

	return 0;
}
