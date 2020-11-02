#include <iostream>
using namespace std;


template <class Type>
class myshared_ptr
{
	Type *ptr;
	static int count;
	public:
	myshared_ptr(Type *ptr);
	myshared_ptr(const myshared_ptr<Type> &obj);
	~myshared_ptr();
	Type operator *() ;
	Type * operator ->();
	static void Add() {count++;}
	static void Minus() {count--;}
	

};

class Demo
{
	public:
		void prnmsg()
		{
			cout << this << ":" << __func__ << ":" << __LINE__ << endl;
		}
};

/*******************************************************/

template <class Type>
int myshared_ptr<Type>::count = 0;

template <class Type>
myshared_ptr<Type>::myshared_ptr(Type *p)
{
	Add();
	this->ptr  = p;
}

template <class Type>
myshared_ptr<Type>::myshared_ptr(const myshared_ptr<Type> &obj)
{
	Add();
	ptr = obj.ptr;
}

template <class Type>
myshared_ptr<Type>::~myshared_ptr()
{
	Minus();
	if(count == 0)
	{
		delete this->ptr;
		cout <<"Memory is released！" << endl;
		
	}
}

template <class Type>
Type myshared_ptr<Type>::operator *()
{
	return *ptr;
}

template <class Type>
Type *myshared_ptr<Type>::operator ->()
{
	 return ptr;
}

/**************************************************/
int main()
{
	myshared_ptr<Demo> p(new Demo);
	myshared_ptr<Demo> pp(p);

	p->prnmsg();
	pp->prnmsg();

	(*p).prnmsg();
	(*pp).prnmsg();

	return 0;
}

