#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>



typedef struct {
	long int mtype;
	char mtext[1024];
}MSG;


int main()
{
	int msgid, ret;
	MSG mbuf;
	key_t key = ftok("/tmp", 21);

	msgid = msgget(key, IPC_CREAT| 0666);
	if(-1 == msgid)
	{
		perror("msgget");
		return -1;
	}

	int s = msgrcv(msgid, &mbuf, 20, 100, IPC_NOWAIT);
	if(-1 == s)
	{
		perror("msgrcv");
		return -1;
	}

	printf("%s\n", mbuf.mtext);

	return 0;
}
