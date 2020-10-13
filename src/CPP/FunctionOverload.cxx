#include <iostream>
using namespace std;

int add(int a)
{
	return a+a;
}
double add(double a, double b, double c=0.01) //可以在参数列表中初始化参数，则该参数在调用的时候可以不写（忽略）
{
	return a+b+c;
}

int add(int a, int b)
{
	return a + b;
}


int main()
{
	cout << add(10) << endl;
	cout << add(10, 20) << endl;
	cout << add(1.1, 1.2) << endl;

	return 0;
}
