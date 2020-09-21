#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>


time_t time(time_t *tloc);

sem_t sem1, sem2;
srand(time(NULL));
int num = 0;

void *pthread1(void *arg)
{
	while(1)
	{
		sem_wait(&sem1);

		printf("pthread1 output:%d\n", num);

		sleep(1);
	}
}



int main(int argc, char **argv)
{
	pthread_t tid1, tid2;

	sem_init(&sem1, 0, 20);



	pthread_create(&tid1, NULL, pthread1, NULL);

	while(1)
	{
		sem_post(&sem1);
		num++;
		printf("main output :%d\n", num);
		sem_destroy(&sem1);
		sleep(rand()%3);
	}

	pthread_join(tid1, NULL);
	return 0;
}
