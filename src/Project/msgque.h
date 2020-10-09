#ifndef __MSGQUE_H
#define __MSGQUE_H

#define MSGSIZE 1024
#define N 256
#define PATHNAME "."
#define PROJ_ID 0x44
#define LEN(a, b) (sizeof(a) - sizeof(b))

struct msgbuf{
	long int mtype;
	char mtext[MSGSIZE];
};

void sendmesg(char *msg, long type);
char *revmesg(long type, char *buf);



#endif
