#include "mystring.h"

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


