#include <iostream>

using namespace std;
struct Demo{
	int y;
	int x;
public:
	void setx(int val)
	{
		x = val;
	}

	void sety(int val)
	{
		y = val;
	}

	int getx()
	{
		gety(); //是protect权限，只能在结构体内访问
		return x;
	}
	protected:
	int gety()
	{
		return y;
	}
	
};


int main()
{
	struct Demo obj;

	obj.setx(123);
	obj.sety(123);
	cout << obj.getx() << endl;
	cout << obj.x << endl; //因为x是私有变量不能在该区域访问

	return 0;
}
