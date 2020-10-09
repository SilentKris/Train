#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "msgque.h"



#define N 256
#define PATHNAME "."
#define PROJ_ID 0x44
#define LEN(a, b) (sizeof(a) - sizeof(b))

extern int msgid;
void sendmesg(char *msg, long type)
{
	struct msgbuf mbuf;
	strcpy(mbuf.mtext, msg);
	mbuf.mtype = type;
	msgsnd(msgid, &mbuf, LEN(mbuf, long), IPC_NOWAIT);
	if(EAGAIN == errno)
	{
		fprintf(stderr, "%s", strerror(errno));
	}
}

char * revmesg(long type, char *buf)
{
	struct msgbuf mbuf;
	bzero(&mbuf, sizeof(mbuf));
	ssize_t ret = msgrcv(msgid, &mbuf, LEN(mbuf, long), type,0);
	if(-1 == ret)
	{
		perror("msgrcv");
		return NULL;
	}
	strcpy(buf, mbuf.mtext);

}
