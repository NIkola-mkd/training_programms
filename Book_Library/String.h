#pragma once
#include <iostream>
using namespace std;
class String
{
public:
	String();
	String(const String&);
	String(const char*);
	~String();
	String& operator =(const String&);
	bool operator ==(const String&);
	bool operator !=(String&);
	const char* getchar();
	int getsize();
private:
	int size_ = 0;
	char* string_ = nullptr;

	friend ostream& operator <<(ostream&, String&);
	friend istream& operator >>(istream&, String&);
};