#include <iostream>
using namespace std;

struct job
{
	char name[40];
	double salary;
	int floor;
};


template <class T>
void Swap(T &, T &);
void Show(job &a);

template <> void Swap<job>(job &, job &);

int main()
{
	int a = 10;
	int b = 11;

	 Swap(a, b);
	

	job d = {"name1", 3.14, 23};
	job e = {"name2", 3.15, 24};


	Show(d);
	Show(e);

	Swap(d, e);
	Show(d);
	Show(e);

	return 0;
}

template <class T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> void Swap(job &a ,job &b)
{
	double temp;
	temp = a.salary;
	a.salary = b.salary;
	b.salary = temp;
}

void Show(job &a)
{
	cout << a.name << "salary = " << a.salary << " floor = " << a.floor << endl;
}
