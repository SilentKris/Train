#include<iostream>
#include<string>
using namespace std;

typedef void(*Fun)(void);

class Base {
	public:
		virtual void f() {
			cout << "Base::f()" << endl;
		}
		virtual void g() {
			cout << "Base::g()" << endl;
		}
		virtual void h() {
			cout << "Base::h()" << endl;
		}
};
int main() {
	Base b;
	Fun fp = NULL;
	cout << "虚函数表地址：" << (int*)(&b) << endl;
	cout << "虚函数表第一个虚函数指针地址：" <<(int*)*(int*)(&b) << endl;
	for (int i = 0; i != 3; ++i) {
		fp = (Fun)*((int*)*(int*)(&b) + i);
		fp();
	}
	return 0;
}
