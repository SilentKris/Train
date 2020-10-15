#include "mystring.h"


int main()
{
	mystring str1;  //无参数初始化
	mystring str2("hello world!"); //有参数初始化
	mystring str3(str2); //复制构造函数
	mystring str4 = "This is = overload";
	str1 = "nihao";   // =运算符重载

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	
	mystring str5 = str2 + str1;  // + 运算符重载
	cout << str5 << endl<<endl;

	// == 运算符重载
	if(str1 == "nihao")
		cout << "类和字符串比较" << endl;
	if(str2 == str3)
		cout << "类和类比较" << endl;
	if("nihao" == str1)
		cout << "字符串和类比较" << endl;

}
