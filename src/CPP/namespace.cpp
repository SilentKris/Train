#include <iostream>

using namespace std;

namespace A{
	int a = 10;
	void fun()
	{
		cout << a << endl;
	}
}

namespace B{
	
	int a = 10;
	void fun()
	{
		cout << a << endl;
	}
}

int main()
{
	using namespace A;
	using namespace B;
#if 0
	//这样会编译器报错，引起歧义，不知道该变量是属于哪个名字空间的
	a = 23;
	fun();
#endif
	A::a = 23;
	B::fun();

	return 0;
}
