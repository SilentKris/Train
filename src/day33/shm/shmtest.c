#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

char * PATHNAME=".";
int PROJ_ID = 0x66;
size_t SIZE = 2048;
int shmid;

int main(int argc, char **argv)
{
	key_t key = ftok(PATHNAME, PROJ_ID);

//	shmid = shmget(0, SIZE, IPC_PRIVATE);
	shmid = shmget(key, SIZE, IPC_CREAT);
	char *addr = shmat(shmid, NULL, );
	printf("key = %d\n", key);
	printf("shmid = %d\n", shmid);


	return 0;
}
