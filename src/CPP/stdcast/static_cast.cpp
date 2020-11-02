#include <iostream>

using namespace std;

class Base{

	
};

class Inherit: public Base
{

};

int main()
{
	Base *p;
	Inherit *q;

 	q = new Inherit;

	p = q;
	static_cast<Inherit *>(p);
	
	cout << endl;
	return 0;
}
