#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun()
{
	printf("im a pthread new create\n");
}


int main()
{
	pthread_t tidA, tidB;

	pthread_create(&tidA, );


}
