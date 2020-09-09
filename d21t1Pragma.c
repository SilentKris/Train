#include <stdio.h>


int main()
{

#pragma pack(push)
#pragma pack(2)

	struct _str1{
		char name[20];
		char num[10];
		int score;
		char sex;
	}stu1;

	printf("str1占用的内存的大小是：%d个字节\n", sizeof(stu1));
#pragma pack(pop)

	struct _stu2{
		char name[20];
		char num[10];
		int score;
		char sex;
		
	}stu2;
	
	printf("str2占用的内存的大小是：%d个字节\n", sizeof(stu2));

	return 0;
}
