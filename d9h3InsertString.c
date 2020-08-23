#include <stdio.h>
#include <string.h>


char *Insert(char s1[], char s2[], int n);
int main(int argc, char **argv)
{
	char s1[64] = "Hello world";
	char s2[3] = "ni";
	char *p;
	puts(s1);
	puts(s2);

	p = Insert(s1, s2, 3);
	
	puts(p);

	return 0;
}

char *Insert(char s1[], char s2[], int n){
	int len1, len2, temp;
	char *p;

	len1 = strlen(s1);
	len2 = strlen(s2);
	p = s1 + len1 + len2; 

	while(p - len2 >= &s1[n]){

		*p = *(p - len2);
		p--;
	}
	temp = s1[n + len2];  // temp比较保存s1被s2中'\0'覆盖住的字符
	s1[n] = '\0';

	strcat(s1, s2);

	s1[n + len2] = temp;
	
	return s1;
}
