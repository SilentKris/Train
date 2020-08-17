#include <stdio.h>

int conv(char );

int main()
{
	int ascii;
	char section = 0;
	printf("*********ASCII转换器**************\n");
	printf("请选择输入ASCII的方式(输入数字即可)：\n");
	printf("\t1.十六进制\n\r\t2.十进制\n\r\t3.八进制\n");
	
	section = getchar();
	section -= 48;
	switch(section)
	{
		case 1:scanf("%x", &ascii);break;
		case 2:scanf("%u", &ascii);break;
		case 3:scanf("%o", &ascii);break;
		default:printf("输入错误，请重新执行程序！！！\n");
	}

	printf("您所输入的字符为%c\n", ascii);

	return 0;


}
