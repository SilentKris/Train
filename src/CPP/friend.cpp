#include <iostream>

using namespace std;

class Demo{
	public:
		Demo(int val = 0): myval(val)
		{
			cout << this << ":" << __func__ << ":" << __LINE__ << endl;
		}
		Demo(const Demo &obj)
		{
			this->myval = obj.myval;
			cout << this << ":" << __func__ << ":" << __LINE__ << endl;	
		}
		~Demo()
		{
			cout << this << ":" << __func__ << ":" << __LINE__ << endl;
		}
	public:
		int getmyval() const;
		friend void setval(Demo &obj);//将setval声明成Demo类的友元函数
	private:
		int myval;

};


int Demo::getmyval()const
{
	return this->myval;
}

void setval(Demo &obj) //设置Demo类对象的成员变量myval
{
	obj.myval = 12; //调用友元函数来修改类的私有成员变量
}
int main()
{
	Demo obj;
	setval(obj);
	cout << obj.getmyval()<< endl;
	return 0;
}

