#include <stdio.h>

char *change_str(char str[], char old, char new);
char *del_char(char str[], char a);
int my_strlen(char str[]);
int find_pos(char str1[], char str2[]);
char *my_strcat(char str1[], char str2[]);
char *sort_str(char str[]);

int main()
{
	char  str1[64]  =  {"hello world, good morning!"};
	char  str2[64]  =  {"china, sichuan, chengdu"};
	char  str3[64]  =  {"ld"};

	puts(  change_str(str1,  'o',  'a')   );			
	puts(  del_char(str2,  'h')  );
	printf("len = %d\n",  my_strlen(str1)  );
	printf("pos = %d\n",  find_pos(str1, str3) );
	puts(  my_strcat(str1,  str2) );
	puts( sort_str(str1) );
	return 0;
}

char *change_str(char str[], char old, char new)
{
	char *p = str;
	while(*p)
	{
		if(*p == old)
			*p = new;
		p++;
	}
	return str;
}

char *del_char(char str[], char a)
{
	char *p, *q;

	p = q = str;
	while(*p)
	{
		if(*q != a)
			*p++ = *q;
		q++;
	}

	return str;

}
int my_strlen(char str[])
{
	int count = 0;
	char *p = str;

	while(p[count++]);

	return count-1;
}
int find_pos(char str1[], char str2[])
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
					return index;
			}
			index2 = 0;
		}
		else
		index1++;

	}
	

	printf("不包含\n");
	return -1;

}
char *my_strcat(char str1[], char str2[])
{
	char *q = str1;
	char *p = str2;

	while(*++q);
	while(*q++ = *p++);

	return str1;
} 
char *sort_str(char str[])
{
	char *q = str;
	char temp;
	int i, j, count=0;
	while(q[count++] != '\0');

	for(i=0; i< count-1; i++)
		for(j=0; j<count-2-i; j++)
		{
			if(str[j+1] < str[j])
			{
				temp = str[j+1];
				str[j+1] = str[j];
				str[j] = temp;
			}
		}
	return str;
}

