#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define N 256

char * PATHNAME=".";
int PROJ_ID = 0x66;
size_t SIZE = 2048;
int shmid;


int main(int argc, char **argv)
{
	int count = 1000;
	key_t key = ftok(PATHNAME, PROJ_ID);

	shmid = shmget(key, SIZE, IPC_CREAT );
	char *addr = shmat(shmid, NULL, 0);

	while(count--)
	{
		usleep(100000);
		printf("%s\n", addr);
		
	}
	shmdt(addr);
	return 0;
}
