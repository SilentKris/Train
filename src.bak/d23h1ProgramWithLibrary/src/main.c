#include "lib.h"

void print(void);

int main(int argc, char **argv)
{
	int num = 5;
	printf("Welcome!\n");
	while(1)
	{
		switch(num)
		{
			case 1:Dec2Bin();print();break;
			case 2:TheOperationOnArray();print();break;
			case 3:dice();print();break;
			case 4:Deal();print();break;
			case 5:print();break;
			default:printf("输入错误请重新输入");break;
		}
		scanf("%d", &num);
	}
	return 0;
}

void print()
{
	 printf("\n\n请选择你要使用的功能:\n1、十进制转换二进制\n2、数组操作\n3、掷色子\n4、发牌\n5、主菜单\n");

}
