#include <stdio.h>
/*
   extern int a ;//若加上extern关键字表明 a 为声明
   int a;
   */

/*
   int a;  //两个都没有初始化，则其中有一个是声明
   int a;
   */
/*
   int a = 10; //两个都进行初始化，则都为定义，编译时出错，错误为重复定义
   int a = 10;
   */
/*
   extern int a = 10;  //gcc编译器C99标准 在函数体外用extern初始化会报警告，但是依然默认允许
   int a;
   */
int main(int argc, char **argv)
{

	//	extern int a;//未定义，只是声明，语法没错，但是链接会出问题:找不到所要链接的外部的定义
	extern int a ; //错误，显示

	printf("a = %d\n", a);


	return 0;
}
