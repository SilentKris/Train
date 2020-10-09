#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>


#define N 256
#define PATHNAME "."
#define PROJ_ID 0x44
#define LEN(a, b) (sizeof(a) - sizeof(b))

struct msgbuf{
	long mtype;
	char mtext[N];
};

void sendmsg(char *msg, long type);
void revcmesg( long type);

int msgid;



int main()
{
	int select;
	long type;
	char buf[256];
	key_t key = ftok(PATHNAME, PROJ_ID);

	msgid = msgget(key, 0666 | IPC_CREAT);


	while(1)
	{
		puts("Please select function");
		select = fgetc(stdin) - '0';
		switch(select)
		{
			case 1: {
						puts("Please input type");
						scanf("%ld",&type);
						getchar();
						puts("Please input message");
						sendmsg(fgets(buf, sizeof(buf), stdin),type);
					}	
					;break;
			case 2: {
						puts("Please input type");
						scanf("%ld",&type);
						getchar();
						revcmesg(type);
					}
					;break;
		}
	}

	return 0;
}

void sendmsg(char *msg, long type)
{
	struct msgbuf mbuf;
	strcpy(mbuf.mtext, msg);
	mbuf.mtype = type;
	msgsnd(msgid, &mbuf, strlen(mbuf.mtext), IPC_NOWAIT);
	if(EAGAIN == errno)
	{
		fprintf(stderr, "%s", strerror(errno));
	}
}

void revcmesg(long type)
{
	struct msgbuf mbuf;
	bzero(&mbuf, sizeof(mbuf));
	ssize_t ret = msgrcv(msgid, &mbuf, LEN(mbuf, long), type,IPC_NOWAIT );
	if(-1 == ret)
	{
		perror("msgrcv");
		
	}
	
	puts(mbuf.mtext);

}
