#include <iostream>
#include <stdio.h>
#include <strings.h>
#include <string.h>

using namespace std;

class mystring{
	char *str;

	public:
	friend ostream & operator<<(ostream &, mystring &);
	mystring();
	mystring(const char *);
	mystring(const mystring &);
	~mystring();
	mystring & operator=(const mystring &);
	mystring & operator=(const char *p);
	char *operator+(const mystring &) const;
	bool operator==(const char *p) const;
	bool operator==(const mystring &) const;

};

mystring::mystring()
{
	str = NULL;
}

mystring::mystring(const mystring &obj)
{
	int len = strlen(obj.str);
	this->str = new char [len+1];
	if(!this->str)
	{
		perror("str");
		return;
	}
	bzero(str, len+1);
	for(int i=0; i<len; i++)
	{
		this->str[i] = obj.str[i];
	}

}
mystring::mystring(const char *p)
{
	int len = strlen(p);
	this->str = new char [len+1];
	if(!this->str)
	{
		perror("str");
		return;
	}
	bzero(str, len+1);
	for(int i=0; i<len; i++)
	{
		this->str[i] = p[i];
	}
}

mystring::~mystring()
{
	delete [] str;
}

mystring & mystring::operator=(const mystring &obj)
{
	int len = strlen(obj.str) + 1;
	if(this->str != NULL)
	{
		delete [] this->str;
	}
	this->str = new char [len];
	strcpy(this->str, obj.str);
	return *this;
}
mystring & mystring::operator=(const char *p)
{
	int len = strlen(p) + 1;
	if(this->str != NULL)
	{
		delete [] this->str;
	}
	this->str = new char [len];
	strcpy(this->str, p);
	return *this;
}

char * mystring::operator +(const mystring &obj) const
{
	int len = strlen(this->str) + strlen(obj.str) + 1;
	char *ptr = new char [len];
	bzero(ptr, len);
	strcat(ptr, this->str);
	strcat(ptr, obj.str);
	
	return ptr;
}

ostream & operator <<(ostream &os, mystring &obj)
{
	if(obj.str)
		os << obj.str;
	else
		cout << "value is NULL ";
	return os;
}
bool mystring::operator==(const char *p) const
{
	if(!strcmp(this->str, p))
		return true;
	else 
		return false;
}

bool mystring::operator==(const mystring &obj) const
{
	if(!strcmp(this->str, obj.str))
		return true;
	else 
		return false;
}
bool operator==(const char *p, mystring &obj)
{
	return (obj == p);
}

int main()
{
	mystring str1;  //无参数初始化
	mystring str2("hello world!"); //有参数初始化
	mystring str3(str2); //复制构造函数
	mystring str4 = "This is = overload";
	str1 = "nihao";   // =运算符重载

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	
	mystring str5 = str2 + str1;  // + 运算符重载
	cout << str5 << endl<<endl;

	// == 运算符重载
	if(str1 == "nihao")
		cout << "类和字符串比较" << endl;
	if(str2 == str3)
		cout << "类和类比较" << endl;
	if("nihao" == str1)
		cout << "字符串和类比较" << endl;

}
