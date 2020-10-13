#include <iostream>

class test {
	int i;
	int k;

	public:
	test();
	int add(int i, int k) const;
	void modify();

};

test::test()
{
	i = 10;
	k = 12;
}
int test::add(int i, int k) const
{
	return i+k;
}

void test::modify()
{
	this->i = 1;
}

int main()
{
	test mytest;

	mytest.modify();

	return 0;
}
