#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

#define PATHNAME "/tmp"

typedef struct {
	long int mtype;
	char mtext[1024];	
}MSG;


int main()
{


	key_t key = ftok(PATHNAME, 21);
	MSG mbuf;
	if(-1 == key)
	{
		perror("ftok");
		return -1;
	}

	int msgid = msgget(key, 0666 | IPC_CREAT);
	if(msgid == -1) {
		perror("MSGGET");
		return -1;
	}

	mbuf.mtype = 100;
	strcpy(mbuf.mtext, "This is a test!\n");

	int s = msgsnd(msgid, &mbuf, 20,  0);
	if(s == -1) {
		perror("msgsnd");
		return -1;
	}

	return 0;
}

