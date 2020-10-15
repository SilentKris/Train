#include <iostream>
using namespace std;

class Base
{
	public:
		Base(int myval):myval(myval)
		{
			cout << this << __func__ << ":" << __LINE__ <<endl;
		}
		~Base()
		{
		}
	protected:
		void setmyval(int myval)
		{
			this->myval = myval;
		}
	public:
		void getmyval() const
		{
			cout << "myval = " << myval << endl;
		}
	private:
		int myval;
	public:
		static int staticval;
};

int Base::staticval = 45;

class Subclass:public Base
{
	public:
	Subclass(int val=0):val(val),Base(val)
	{
		setmyval(666);
	}
	~Subclass()
	{
	}

	private:
	int val;
};
class Inherit:private Subclass
{
	public:
	Inherit()
	{
		cout << "struct" << ":" << __func__ << " " << __LINE__ << endl;
		setmyval(777);
		staticval = 23;
	}
	~Inherit()
	{
		cout << "destruct" <<":" << __func__ << " " << __LINE__ << endl;
	}


	
};

int main()
{
	cout << Base::staticval << endl;
	Subclass obj;
	Inherit obj1;
	cout << Subclass::staticval << endl;


	return 0;
}
