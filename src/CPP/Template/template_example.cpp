#include <iostream>
using namespace std;

template <typename T>

class Demo{  //模板类

	T num;
	public:
	Demo(T num)
	{
		this->num = num;
	}
	
	T getval();

};
template <class T>

T Demo<T>::getval()
{
	cout << this->num << endl;
}
	
template <class T>
T add(T a, T b)
{
	T c = a + b;
	return c;
}

int main()
{
	cout << add(10, 20) << endl;
	cout << add(1.2, 1.3) << endl; //template 识别参数类型，将class T隐式转换
//	cout << add(1, 1.2) << endl; //系统识别到 1 为 int , 1.2为double,声明add参数是相同的类型 T, 即add(T, T) ，此时会报错 add(int, double) 没有声明。
	cout << add<double> (12, 2.3) << endl; //显式指定形参的类型，可以防止系统识别错误

	Demo<int> obj(123);
	obj.getval();
	return 0;
}
