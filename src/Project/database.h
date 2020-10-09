#ifndef __DATABASE_H
#define __DATABASE_H
#include <sqlite3.h>
#include "datastruct.h"


int db_init(sqlite3 **ppdb);
int Createdb(sqlite3 **ppdb);
int Createusr(sqlite3 *ppdb);
int Createmsg(sqlite3 *ppdb);
int Insertdb(sqlite3 *ppdb, int connfd, int, char *, char *);
int Insertmsg(sqlite3 *ppdb, int connfd, int type, char *msg);

int Delmsg(sqlite3 *ppdb, int type );
LNode *Checkdb(sqlite3 *ppdb, int connfd, char *, char *);
LNode *Searchusr(sqlite3 *ppdb, int connfd, int type, char *name);
int Searchmsg(sqlite3 *ppdb, int type);

#endif
