#include <stdio.h>
#include <string.h>

#define N 50

int main(int argc, char **argv)
{

	char s1[5][N];
	char s2[5];
	char temp[N];
	int i, j;
	for(i = 0; i < 5; i++){
		gets(s1[i]);
	}

	printf("排序后\n");

	for(i = 0; i < 5; i++){
		for(j = 0; j < 4 - i; j++){
			if(strlen(s1[j + 1]) < strlen(s1[j])){

				strcpy(temp, s1[j + 1]);
				strcpy(s1[j + 1], s1[j]);
				strcpy(s1[j], temp);

			}
		}
		puts(s1[j]);
		if(strlen(s1[j]) >= 4)
			s2[j] = s1[j][3];
		else
			s2[j] = ' ';

	}
	puts(s2);

	return 0;

}
