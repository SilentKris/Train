#ifndef _COMMON_H__
#define _COMMON_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define PATHNAME "."
#define PROJ_ID 0x6666

int CreateShm(int size);
int DestroyShm(int shmid);
int GetShm(int size);
#endif

