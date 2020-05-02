#pragma once
#include <iostream>

using namespace std;

class String
{
private:

	char* str_;
	size_t size_;

public:

	String();
	String(const char* str);
	String(const String& string);
	~String();

	int getSize() const;
	const char* get() const;
	void set(const char* str);

	String& operator=(const char* str);
	String& operator=(const String& string);

	friend bool operator==(const String& y, const String& x);
	friend bool operator!=(const String& y, const String& x);

	char& operator[](const int index);
	char operator[](const int index) const;

	friend istream& operator>>(istream& in, String& string);
	friend ostream& operator<<(ostream& out, const String& string);

	friend bool operator<(const String& y, const String& x);
	friend bool operator>(const String& y, const String& x);

};
