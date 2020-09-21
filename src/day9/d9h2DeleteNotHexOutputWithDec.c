#include <stdio.h>
#include <string.h>

#define N 200

char *DeleteNotHex(char *);
int OutputWithDec(char *);

int main(int argc, char **argv)
{
	char ch[N];
	int Result;
	gets(ch);
	puts(ch);
	
	Result = OutputWithDec(ch);

	printf("The result in Dec is %d\n", Result);

	return 0;
}

//将非十六进制字符删除
char *DeleteNotHex(char ch[]){

	char *p, *q;
	int len;

	len = strlen(ch);
	p = q = ch;

	while(*q != '\0'){
		if(*q - 48 >=0 && *q - 48 <= 9){
			*p = *q;
			p++;
			q++;
		}
		else if((*q | 32) >= 'a' && (*q | 32) <= 'f'){
			*p = *q;
			p++;
			q++;
		}
		else
			q++;

	}
	*p = *q;

	puts(ch);

	return ch;

}

int OutputWithDec(char ch[])
{
	int len, i, sum = 0;
	char *q;

	ch = DeleteNotHex(ch);
	len = strlen(ch);
	q = ch;

	while(*q != '\0'){
		if(*q - 48 >=0 && *q - 48 <= 9){
			*q -= 48;
		}

		if((*q | 32) >= 'a' && (*q | 32) <= 'f'){
			*q -= 87;
		}
		q++;
	}

	for(i=0; i<len; i++){
		if( 0 == i){
			sum = ch[0];
		}
		else{
			sum *= 16;
			sum += ch[i];
		}

	}

	return sum;

}


