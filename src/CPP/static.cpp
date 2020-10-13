#include <iostream>

using std::endl;
using std::cout;
class stc{
	int myval;
	static int val;
	const int cval;
	public:

	stc(): cval(2233)
	{

	}
	
	void getcval()
	{
		cout << "cval = " << cval << endl;
	}
	void minus()
	{
		val--;
	}
	void getmyval()
	{
		std::cout << myval << std::endl;
		cout << "val = "<< this->val << endl; 
	
	}
	static void getval()
	{
		cout << "val = "<<  val << endl;
	}

	void setmyval(int val)
	{
		myval = val;
	}
	static void setval()
	{
		val = 432; 
	}
};
	int stc::val = 3423;
	
int main()
{
	stc obj;
	stc obj1;
	obj.getval();
	obj.minus();
	obj.getval();
	obj1.getval();
	obj.getcval();

	return 0;
}
