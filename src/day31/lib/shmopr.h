#ifndef __SHMOPR_H
#define __SHMOPR_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PATHNAME "."
#define PROJ_ID 0X12
#define SIZE 2048

key_t key;
int shmid;
char *buf;


key_t Createshm(void);
int Getshm(key_t key);
char *Bindshm(int shmid);
void Unbindshm(char *shmaddr) ;
void Relshm(int shmid);

#endif
