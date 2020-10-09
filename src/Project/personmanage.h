#ifndef __PERSONMANAGE_H
#define __PERSONMANAGE_H
#include "datastruct.h"

#define N 256

int  Login(sqlite3 *ppdb, int connfd, LNode *);
void Emptywithzero(int n_values, ...);
int  Regist(sqlite3 *ppdb, int connfd);

#endif
