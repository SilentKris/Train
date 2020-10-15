#include <iostream>

using namespace std;

typedef void (*PFUN)();
class Base
{
	public:
		Base(int val):val(val)
		{
			cout << this << ":" << __func__ << ":" << __LINE__ << endl; 
		}
		~Base()
		{
			cout << this << ":" << __func__ << ":" << __LINE__ << endl; 
		}
	virtual  void prnmsg() 
		{
			cout << this << ":" << __func__ << ":" << __LINE__ << ":" << val << endl; 
	}

	private:
		int val;
};

class Inherit : public Base
{
	public:
	Inherit(int val) : val(val), Base(val)
	{
		cout << this << ":" << __func__ << ":" << __LINE__ << endl; 
	}
	~Inherit()
	{
		cout << this << ":" << __func__ << ":" << __LINE__ << endl; 
	}
	virtual void prnmsg()
	{
		cout << this << ":" << __func__ << ":" << __LINE__ << ":" << val << endl; 
	}
	
	private:
	int val;
};


int main()
{
	Base obja(123);
	Inherit objb(321);

	
	Base * a =  &obja;
	Base * b =  &objb;


	PFUN fp = (PFUN)*((int *)*(int *)&obja);
	fp();



//不用virtual关键字，则使用的引用的引用类型的对象方法，为静态联编
//用了virtual关键字，则使用的引用指向的对象类型方法，为动态联编

	a->prnmsg();
	b->prnmsg();
	return 0;
}
