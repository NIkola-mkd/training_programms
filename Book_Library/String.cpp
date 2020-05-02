#include "String.h"
#include "Exception.h"
#include <iostream>

#define MAX_LINE_SIZE 256

using namespace std;

int strLen(const char* str)
{
	int c = 0;
	while (*str++)
	{
		c++;
	}
	return c;
}

void strCpy(char* copy, const char* str)
{
	int i;
	while (*str)
	{
		*copy++ = *str++;
	}
	*copy = '\0';
}

String::String()
{
	size_ = 0;
	str_ = new char[size_ + 1];
	str_[size_] = '\0';
}

String::String(const char* str)
{
	if (str == str_)
	{
		return;
	}
	size_ = str == nullptr ? 0 : strLen(str);
	str_ = new char[size_ + 1];
	strCpy(str_, str);
}

String::String(const String& string)
{
	if (this == &string)
	{
		return;
	}
	size_ = string.size_;
	str_ = new char[size_ + 1];
	strCpy(str_, string.str_);
}

String::~String()
{
	if (str_ != nullptr)
	{
		delete[] str_;
	}
}

int String::getSize() const
{
	return size_;
}

const char* String::get() const
{
	return str_;
}

void String::set(const char* str)
{
	if (str_ == str)
	{
		return;
	}
	size_ = str == nullptr ? 0 : strLen(str);
	if (str_ != nullptr)
	{
		delete[] str_;
	}
	str_ = new char[size_ + 1];
	strCpy(str_, str);
}

String& String::operator=(const char* str)
{
	set(str);
	return *this;
}

String& String::operator=(const String& string)
{
	set(string.str_);
	return *this;
}

bool operator==(const String& y, const String& x)
{
	if (y.size_ != x.size_)
	{
		return false;
	}
	for (int i = 0; i < y.size_; ++i)
	{
		if (y.str_[i] != x.str_[i])
		{
			return false;
		}
	}
	return true;
}

bool operator!=(const String& y, const String& x)
{
	return !(y == x);
}

char& String::operator[](const int index)
{
	if (index < 0 || index > size_)
	{
		throw Exception("ERROR! Index out of range!");
	}
	return str_[index];
}

char String::operator[](const int index) const
{
	if (index < 0 || index > size_)
	{
		throw Exception("ERROR! Index out of range!");
	}
	return str_[index];
}

istream& operator>>(istream& in, String& string)
{
	char* buf = new char[MAX_LINE_SIZE];
	in.getline(buf, MAX_LINE_SIZE, '\n');
	if (in.fail())
	{
		throw Exception("ERROR! Incorrect input stream !");
	}
	string.set(buf);
	delete[] buf;
	return in;
}

ostream& operator<<(ostream& out, const String& string)
{
	out << string.str_;
	return out;
}

bool operator<(const String& y, const String& x)
{
	if (y.size_ == 0)
	{
		return true;
	}
	int c = y.size_ < x.size_ ? y.size_ : x.size_;
	for (int i = 0; i < c; ++i)
	{
		if (tolower(y.str_[i]) < tolower(x.str_[i]))
		{
			return true;
		}
		else if (tolower(y.str_[i]) > tolower(x.str_[i]))
		{
			return false;
		}
	}
	return y.size_ < x.size_;
}

bool operator>(const String& y, const String& x)
{
	if (x.size_ == 0)
	{
		return true;
	}
	int c = y.size_ < x.size_ ? y.size_ : x.size_;
	for (int i = 0; i < c; ++i)
	{
		if (tolower(y.str_[i]) > tolower(x.str_[i]))
		{
			return true;
		}
		else if (tolower(y.str_[i]) < tolower(x.str_[i]))
		{
			return false;
		}
	}
	return y.size_ > x.size_;
}
