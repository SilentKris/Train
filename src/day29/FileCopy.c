#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 200

sem_t sem1, sem2;
pthread_t tid_w, tid_r;
int status;
char *st;
FILE *fp_r, *fp_w;
char s[N];

void *pwrite(void *arg)
{
	while(1)
	{
		sem_wait(&sem1);
		if(NULL == st)
		{

			fclose(fp_w);
			pthread_exit(NULL);
			break;
		}
		status = fputs(s, fp_w);
		sem_post(&sem2);
	}
}

void *pread(void *arg)
{
	while(1)
	{
		sem_wait(&sem2);

		st = fgets(s, sizeof(s)-1, fp_r);
		sem_post(&sem1);
		if(NULL == st)
		{	
			fclose(fp_r);
			pthread_exit(NULL);
			break;
		}
	}
}


int main(int argc, char **argv)
{

	sem_init(&sem1, 0, 0);
	sem_init(&sem2, 0, 1);

	pthread_create(&tid_w, NULL, pwrite, NULL);
	pthread_create(&tid_r, NULL, pread, NULL);

	if(argc < 3)
	{
		fprintf(stderr,"Usage: %s <val1> <val2>\n", argv[0]);
		return -1;
	}

	fp_r = fopen(argv[1], "r+");
	if(NULL == fp_r)
	{
		perror(argv[1]);
		return -1;
	}
	fp_w = fopen(argv[2], "w+");
	if(NULL == fp_w)
	{
		perror(argv[2]);
		return -1;
	}



	puts("线程1,2未回收");
	pthread_join(tid_w, NULL);
	puts("线程2未回收");
	pthread_join(tid_r, NULL);
	puts("线程已回收");

	sem_close(&sem1);
	sem_close(&sem2);



	return 0;
}
