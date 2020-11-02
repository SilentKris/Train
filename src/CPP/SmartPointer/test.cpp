#include <iostream>
using  namespace std;


template <class T>
class Base
{
	T *a;
public:
	Base(T *b):a(b)
	{

	}
	~Base()
	{

	}
	T operator *()
	{
		return *a;
	}

	T * operator ->()
	{
		return a;	
	}
	


};

class A
{
	public:
	void prnmsg()
	{
		cout << "hello world" << endl;
	}
};

int main()
{

	Base<A> obj(new A);

	obj->prnmsg();

//	cout << obj << endl;


	return 0;
}
