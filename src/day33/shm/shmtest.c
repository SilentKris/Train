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
	char buf[N];
	key_t key = ftok(PATHNAME, PROJ_ID);

	shmid = shmget(key, SIZE, IPC_CREAT | 0666 );
	char *addr = shmat(shmid, NULL, 0);
	
	system("ipcs -m");
	while(1)
	{
		fgets(buf, sizeof(buf), stdin);
		if(strcmp("quit", buf) == 0)
			break;
		else
			strcpy(addr, buf);
	}
	shmdt(addr);
	system("ipcs -m");
	
	shmctl(shmid, IPC_RMID, NULL);
	system("ipcs -m");
	


	return 0;
}