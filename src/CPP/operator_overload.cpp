#include <iostream>
using namespace std;
class opr{
	int num;
	bool boo;
	public:

	friend ostream & operator <<(ostream &os, opr &obj);

	opr(bool boo, int num = 23)
	{
		this->boo = boo;
		this->num = num;
	}
	int  operator ++(int)
	{
		num += 1;
		return num;
	}
	opr &  operator <<(int i)
	{
		num <<= i;
		return *this;
	}

	void getval()
	{
		cout << num << endl;
	}
	bool operator !();

};

ostream & operator <<(ostream &os, opr &obj)
{
	os << "hello world, im opr" << endl;
	return os;
}

#if 0
bool opr::operator !()
{
	return  (!this->boo);
}
int operator++(opr &obj)
{
	return obj++;
}
bool operator !(opr &obj) //创建友元函数来实现单目运算符
{
	if(obj.boo)
		return false;
	else
		return true;
}
#endif
int main()
{
	opr obj(true);

	cout << obj;
	


	return 0;
}
