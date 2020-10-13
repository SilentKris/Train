#include <iostream>
#include <assert.h>
using namespace std;

class Array{
	public:
		Array(int len, int val)
		{
			cout << this << ":" << endl;
			this->len = len;
			p = new int[len];
			assert(p);

			for(int i =0; i<len; i++)
				p[i] = val;
		}

		Array(const Array &obj)
		{
			cout << this << ":" << __func__ << ":" << __LINE__ << endl;
			this->p = new int [obj.len];
			this->len = obj.len;
			for(int i=0; i<len; i++)
				this->p[i] = obj.p[i];
		}

		~Array()
		{
			cout << this << ":" << __func__ << ":" << __LINE__ << endl;
			delete [] p;
		}
	private:
		int *p;//数组首地址
		int len;
};

int main()
{
	Array obj1(10,0);
	Array obj2 = obj1;

	return 0;
}

