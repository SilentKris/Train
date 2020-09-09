#include <stdio.h>


int main()
{
	unsigned char ascii;
	int diff = 0;
	putchar('\n');
	putchar('\n');
	putchar('\n');
	putchar('\n');
	diff = 'A' - 'a';
	printf("请输入一个字符：");
	ascii = getchar();
	
	printf("您输入的字符的十六进制ASCII码为：%#X\n", ascii);

	if(ascii >= 'a' && ascii <= 'z')
			ascii += diff;
	else if(ascii >= 'A' && ascii <= 'Z')
			ascii -= diff;
	else
	{
			printf("输入错误，请重启程序后输入！！\n");
			putchar('\n');
			putchar('\n');
			putchar('\n');
			putchar('\n');
			return 0;
	}
	printf("转换后的字符为%c\n",ascii);
	putchar('\2');
	return 0;


}
