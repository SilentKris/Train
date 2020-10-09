#include <stdio.h>
#include <sqlite3.h>

int main(void)
{

    sqlite3 *db;
    int ret;
    //打开数据
    ret = sqlite3_open("my.db",&db);
    if(ret!=SQLITE_OK){
        printf("open my.db failed\n");
        return -1;
    }


    //创建表
    //char sql[256]="create table if not exists user (name text primary key, passwd text);";
    char sql[256]="insert into user values ('jack','123abc') ;";
    char *errmsg;
    ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
    if(ret!=SQLITE_OK){
        printf("sqlite3_exec failed :%s\n",errmsg);
        return -1;
    }

    //关闭数据库
    sqlite3_close(db);

    return 0;
}
