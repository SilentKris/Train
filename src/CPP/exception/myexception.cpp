#include <iostream>
#include <stdexcept>
using namespace std;

class myexception : public exception
{
	public:
	myexception(const char *str) noexcept:ptr(str){}
	~myexception()noexcept {}
	
	const char *what() const noexcept  //重写基类exception 的虚函数
	{
		return this -> ptr; //返回异常信息首地址
	}
	private:
	const char *ptr; // 保存异常信息的首地址 
};


int mydiv(int x, int y)
throw(myexception, invalid_argument) //指定抛出自定义myexception异常和非法数据异常
{
	if(y != 0)
		return x / y ;
	else
		throw myexception("invalid argument");
}

int main()
{
	int a = 1;
	int b = 0;
	
	try //检查错误并抛出异常
	{
		mydiv(a, b);
	}catch(const myexception &obj)
	{
		cout << obj.what() << endl;
	}

	return 0;
}
