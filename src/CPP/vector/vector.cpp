#include <iostream>
#include <vector>
using namespace std;

template <class T>
void Traverse(vector<T> &);


int main()
{
	vector<int> a(10, 0);
	Traverse<int>(a);

	return 0;
}
template <class T>
void Traverse(vector<T> &a)
{
	for(int i=0; i<a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
