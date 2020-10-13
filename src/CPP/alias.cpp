#include <iostream>

int main(int argc, char **argv)
{
	using namespace std;

	int a = 10;
	int &b = a;
	int c = 20;
//	int &b = c; //重复引用出错

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;


	return 0;
}
