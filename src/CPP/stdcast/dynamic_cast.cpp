#include <iostream>
using namespace std;

class Demo
{
	int myval;

	public:
	Demo(int val): myval(val)
	{

	}

	operator int ()
	{
		return this->myval;
	}
};

int main()
{
	Demo obj(123);

	int val = obj;

	cout << val << endl;


	return 0;
}
