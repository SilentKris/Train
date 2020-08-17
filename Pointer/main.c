#include <stdio.h>

int main(int argc, char **argv)
{
    int count = 0;
    char ch;
    unsigned int overtime = 1000;

    while((ch = getchar()) != '\n')
    {   
        if(ch == '{')
            count++;
        if(ch == '}')
            count--;
        printf("count = %d\n", count);
    }
    if(!count)
        printf("该程序'{'和'}'皆成对出现\n");
    if(count)
        printf("不成对！\n");


    return 0;
}