#include <iostream>
#include <stdio.h>
using namespace std;

class Demo{

	int myval;

	public:
	Demo(int myval) // 构造函数：无返回值,函数名和类型名相同，参数可有可无，当定义对象时构造函数被自动调用，主要用来做初始化工作，可以主动调用
	{
		
		this->myval = myval;
		cout << this << ":" <<__func__ << ":" << __LINE__ << endl;
		cout << "我是构造函数" << endl;
	
	}

	~Demo() //析构函数，无参数，函数结束后，系统自动调用，也可手动调用,但是程序结束后仍调用，主要功能：做程序的清理工作
	{
		cout << __func__ << ":" << __LINE__ << endl;
		cout << "我是析构函数" << endl;
	}

	Demo(Demo &obj)
	{
		this->myval = obj.myval;
	}
	void setval(int val);
	int getval()
	{
		cout << myval << endl;
	}

};

void Demo::setval(int val) //设置X的值
{
	myval = val;
}

int main()
{
	Demo obj(1222); //在堆区给对象申请空间时，若构造函数有参数，则需要在new时添加参数或者指定默认参数，否则报错
//	cout << obj << ":" << __func__ << " " << __LINE__ << endl;
	cout << sizeof(Demo) << endl;
	Demo(1111).getval();
	obj.setval(1234);
	obj.getval();

	return 0;
}
