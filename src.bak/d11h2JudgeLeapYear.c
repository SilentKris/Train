#include <stdio.h>

int LeapYear(int year);

int main(int argc, char **argv)
{
	int year, i;
	printf("请输入年：");
	scanf("%d", &year);
	i = LeapYear(year);
	if(i)
		printf("%d is Leap year\n", year);
	else 
		printf("%d is not Leap year\n", year);


	return 0;
}

int LeapYear(int year)
{
	if(year % 400)
	{
		if(!(year % 4) || !(year % 100))
			return 1;
		else 
			return 0;
	}
	else 
		return 0;
}
