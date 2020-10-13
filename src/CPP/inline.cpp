#include <iostream>

using namespace std;

inline void add(int a, int b) //加inline和不加inline链接后生成的汇编文件相差0.1K
{
	cout << a+ b << endl;
}


int main(void)
{
	add(3,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);
	add(2,3);

	return 0;
}
