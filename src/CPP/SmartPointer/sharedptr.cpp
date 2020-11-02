#include <iostream>
#include <memory>
using namespace std;

class Demo
{
	public:
	Demo() 
	{
		cout << this << ":" << __func__ << ":" << __LINE__ << endl;
	}
	~Demo()
	{
		cout << "deconstruct" << endl;
		cout << this << ":" << __func__ << ":" << __LINE__ << endl;
	}

	void prnmsg()
	{
	cout << this << ":" << __func__ << ":" << __LINE__ << endl;
	}

};

int main()
{
	shared_ptr<Demo> p(new Demo);
	shared_ptr<Demo> pp(p);

	p->prnmsg();
	pp->prnmsg();

	return 0;
}
