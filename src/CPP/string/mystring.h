#ifndef MYSTRING_H_
#define MYSTRING_H_

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

bool operator==(const char *, mystring &);

#endif
