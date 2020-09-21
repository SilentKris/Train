#include <stdio.h>
#include <string.h>
#define SIZE 200


int main(int argc, char **argv)
{

	char *front, *rear;
	int len;

	len = strlen(argv[1]) - 1;
	front = argv[1];
	rear = argv[1] + len;
	while((*front++ == *rear--) && (front <= rear));
	if(front > rear)
		printf("该字符串为回文字符串\n");
	else
		printf("该字符串不为回文字符串\n");

	return 0;
}
