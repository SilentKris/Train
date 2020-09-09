#include <stdio.h>
void Convert(char *s1);
int main(int argc, char **argv)
{
	char a;
	printf("请输入要转换的字符\n");
	scanf("%c", &a);
	printf("a = %c\n", a);
	Convert(&a);
	printf("a = %c\n", a);


	return 0;
}


void Convert(char *s1)
{
	char s2;
	s2 = *s1 & (1<<5);
	if(s2 == 32)
		*s1 &= ~(1<<5);
	else
		*s1 |= (1<<5);
}
