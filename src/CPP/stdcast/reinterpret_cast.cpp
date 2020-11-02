#include <iostream>

using namespace std;

int main()
{
	int *p = NULL;
	char *q = NULL;

	int a = 10;
	char b = a;

	p = &a;
	q = &b;

	q = reinterpret_cast<char *>(p); //有待考证

	cout << *p << endl;


	return 0;
}
