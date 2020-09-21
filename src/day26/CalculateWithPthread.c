#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int num = 50;
int sumA = 0;
int sumB = 0;

void *pthread_funA()
{
	int numA = num;
	while(numA--)
	{
		sumA += numA;
	}
}

void *pthread_funB()
{
	int numB = num;
	while(numB <= 100)
	{
		sumB += numB++;
	}

}

int main()
{
	pthread_t tidA, tidB;

	if(pthread_create(&tidA, NULL, pthread_funA, NULL) != 0)
	{
		perror("pthread_create failed");
		return -1;
	}

	if(pthread_create(&tidB, NULL, pthread_funB, NULL) != 0)
	{
		perror("pthread_create failed");
		return -1;
	}

	pthread_join(tidA, NULL);
	pthread_join(tidB, NULL);

	printf("1-100的和为%d\n", sumA + sumB);
	return 0;
}
