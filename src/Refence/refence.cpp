#include <iostream>

using namespace std;

int main()
{
	double i = 0.1234;
	double a = 0.12;
	double &re = i;
	 re = a;

	cout << re  << endl;
	cout << i << endl;
	return 0;
}
