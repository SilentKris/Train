#include <stdio.h>
#include <string.h>

char *My_strstr(char str1[], char str2[]);

int main(int argc, char **argv)
{
	char str1[20] = "nihao, hello";
	char str2[20] = "he";
	char *pos = NULL;
	
	pos =My_strstr(str1, str2);

	printf("The postion is %p, the left string is %s, the position in str is %d\n", pos, pos, pos-str1-1);
	

	return 0;
}
char *My_strstr(char str1[], char str2[])
{
	int index1, index2, index;
	index1 = index2 = 0;
	
	while(str1[index1])
	{
		if(str1[index1] == str2[index2])
		{
			index = index1;
			while(str1[index1++] == str2[index2++])
			{
				if(str2[index2] == '\0')
					return &str1[index];
			}
			index2 = 0;
		}
		else
		index1++;

	}
	return NULL;
}

