/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：test.c
*   创 建 者:  dwl
*   创建日期：2020/08/19
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <iostream>
#include <cstring>
#include <cstdio>

 using namespace std;
int main()
{
	char *p = NULL;
	char *s = "ing";
	

	p = "string1";
	strtok(p, s);
	puts(p);
	
//	printf("%d\n", sizeof(p));
//	printf("%d\n", strlen(p));
//	printf("%p\n", (void *)p);

//	printf("%#X\n", (int )p);

	cout << (void *)p <<  endl;
	return 0;
}
