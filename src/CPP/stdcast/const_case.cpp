#include <iostream>

using namespace std;

int main()
{
	const	int *p = NULL;
	int *q = NULL;

	q = const_cast<int *>(p); //const_cast：const指针到非const指针之间的转化

	return 0;
}
