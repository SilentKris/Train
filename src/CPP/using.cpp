#include <iostream>

namespace jk{
	double fetch;
}

char fetch;

int main()
{
	using jk::fetch;
	using std::cin;
	using std::cout;
	using std::endl;

	cin >> fetch;
	cin >> ::fetch;

	cout <<"jk::fetch = " << fetch << endl;
	cout << "global fetch is " << ::fetch << endl;
}
