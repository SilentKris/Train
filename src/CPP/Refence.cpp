#include <iostream>
using namespace std;

int add(int &a, int &b)
{

	cout << a << " " << b << endl;

	return a + b;
}


int main()
{
	int m = 10;
	int n = 20;

	cout << m << " " << n << endl;
	cout << add(m, n) << endl;

	return 0;
}
