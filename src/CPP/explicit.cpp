#include <iostream>
using namespace std;


class Demo
{
	int myval;
	public:

	//加上explicit可以关闭类的隐式类型转换，但是可以避免显式类型转换
	explicit Demo(int val):myval(val){}
	virtual ~Demo(){}
	int getval(){return this->myval;}
};


int main()
{
	Demo obj(23);
	obj = (Demo)234;

	cout << obj.getval() << endl;
	return 0;
}
