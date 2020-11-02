#include <iostream>
#include <stdexcept>
using namespace std;

int mydiv(int x, int y)
throw(invalid_argument) //指定抛出Invalid_argument异常
{
	if(y != 0)
		return x / y ;
	else
		throw invalid_argument("invalid argument");
}

int main()
{
	int a = 1;
	int b = 0;
	
	try //检查错误并抛出异常
	{
		mydiv(a, b);
	}
	catch(const invalid_argument &obj)
	{
		cout << obj.what() << endl;
	}

	return 0;
}
