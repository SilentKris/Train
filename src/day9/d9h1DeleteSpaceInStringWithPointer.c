#include <stdio.h>
#include <string.h>
#define N 200

int main(int argc, char **argv){
	char arr[N];
	char *i, *j;
	
	i = j = arr;
	gets(arr);
	puts(arr);

	while(*i != '\0'){
		if(*j != ' '){
			*i++ = *j++;
		}
		else{
			j++;
		}
	}
	puts(arr);


	return 0;
}
