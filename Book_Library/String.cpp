#include "String.h"
bool order;//даeт понять считываем фио или дисциплину
String INPUT_ERROR_BOOK_NUMBER = "Error! Incorrect number \0";
String INPUT_ERROR_LITTLE_DATA = "Error! Lack of informations \0";
String INPUT_ERROR_AUTHOR_FULL_NAME = "Error! Incorrect authors name \0";
String INPUT_ERROR_GENRE = "Error! Inccorect genre \0";
String GENRE_1 = "history\0";
String GENRE_2 = "biography\0";
String GENRE_3 = "pedagogy\0";
String GENRE_4 = "math\0";
String GENRE_5 = "physics\0";
String GENRE_6 = "sociology\0";
String::String()
{
	string_ = new char[size_];
}
int String::getsize() { return size_; }
String::String(const String& str) : size_(str.size_)
{
	delete[] string_;
	string_ = new char[size_];
	for (int i = 0; i < size_; i++)
	{
		string_[i] = str.string_[i];
	}
}
String::String(const char* str) :size_(strlen(str))
{
	delete[] string_;
	string_ = new char[size_];
	for (int i = 0; i < size_; i++)
		string_[i] = str[i];
}
String::~String() { delete[] string_; };
const char* String::getchar()
{
	char* ch = new char[size_];
	for (int i = 0; i < size_; i++)
		ch[i] = string_[i];
	ch[size_] = '\0';
	return ch;
}
String& String::operator=(const String& str)
{
	if (&str == this) return *this;
	delete[] string_;
	size_ = str.size_;
	string_ = new char[str.size_];
	for (int i = 0; i < str.size_; i++)
		string_[i] = str.string_[i];
	return *this;
}
bool String::operator==(const String& str)
{
	if (size_ != str.size_)return false;
	for (int i = 0; i < size_; i++)
		if (string_[i] != str.string_[i])return false;
	return true;
}
bool String::operator!=(String& str)
{
	if (size_ != str.size_)return true;
	for (int i = 0; i < size_; i++)
		if (string_[i] != str.string_[i])return true;
	return false;
}
ostream& operator <<(ostream& out, String& str)
{
	for (int i = 0; i < str.size_; i++)
	{
		out << str.string_[i];
	}
	return out;
}
istream& operator >>(istream& in, String& str)
{
	//считывание фио директора
	if (order)
	{
		char ch;
		in.get(ch);
		while (ch == ' ' or ch == '\t')
		{
			if (in.eof())throw INPUT_ERROR_LITTLE_DATA;
			in.get(ch);
		}
		while (true)
		{
			if (in.eof())throw INPUT_ERROR_LITTLE_DATA;
			if (ch == ' ' or ch == '\t')break;
			if (ch < 'А' or ch>'z')throw INPUT_ERROR_AUTHOR_FULL_NAME;
			if (str.size_ == 0)
			{
				if (ch >= 'a' and ch <= 'z')ch = ch - 26;
			}
			else
			{
				if (ch >= 'A' and ch <= 'Z')ch = ch + 26;
			}
			char* string_ = new char[str.size_ + 1];
			for (int i = 0; i < str.size_; i++)
			{
				string_[i] = str.string_[i];
			}
			string_[str.size_] = ch;
			delete[] str.string_;
			str.size_++;
			str.string_ = new char[str.size_ + 1];
			for (int i = 0; i < str.size_ + 1; i++)
			{
				str.string_[i] = string_[i];
			}
			delete[] string_;
			in.get(ch);

		}
		if (ch == '\t')ch = ' ';
		//добaвляем пробел после фамилии
		char* string_ = new char[str.size_ + 1];
		for (int i = 0; i < str.size_; i++)
		{
			string_[i] = str.string_[i];
		}
		string_[str.size_] = ch;
		delete[] str.string_;
		str.size_++;
		str.string_ = new char[str.size_ + 1];
		for (int i = 0; i < str.size_ + 1; i++)
		{
			str.string_[i] = string_[i];
		}
		delete[] string_;
		while (ch == ' ' or ch == '\t')
		{
			if (in.eof())throw INPUT_ERROR_LITTLE_DATA;
			in.get(ch);
		}
		// смотрим имя
		if (ch < 'A' or ch>'z')throw INPUT_ERROR_AUTHOR_FULL_NAME;
		else
		{
			if (ch >= 'a' and ch <= 'z')ch = ch - 26;
			char* string_ = new char[str.size_ + 1];
			for (int i = 0; i < str.size_; i++)
			{
				string_[i] = str.string_[i];
			}
			string_[str.size_] = ch;
			delete[] str.string_;
			str.size_++;
			str.string_ = new char[str.size_ + 1];
			for (int i = 0; i < str.size_ + 1; i++)
			{
				str.string_[i] = string_[i];
			}
			delete[] string_;
		}
		in.get(ch);
		while (ch == ' ' or ch == '\t')
		{
			if (in.eof())throw INPUT_ERROR_LITTLE_DATA;
			in.get(ch);
		}
		//добовляем точку
		if (ch != '.')throw INPUT_ERROR_AUTHOR_FULL_NAME;
		else
		{
			char* string_ = new char[str.size_ + 1];
			for (int i = 0; i < str.size_; i++)
			{
				string_[i] = str.string_[i];
			}
			string_[str.size_] = ch;
			delete[] str.string_;
			str.size_++;
			str.string_ = new char[str.size_ + 1];
			for (int i = 0; i < str.size_ + 1; i++)
			{
				str.string_[i] = string_[i];
			}
			delete[] string_;
		}
		in.get(ch);
		while (ch == ' ' or ch == '\t')
		{
			if (in.eof())throw INPUT_ERROR_LITTLE_DATA;
			in.get(ch);
		}
		//смотрим отчество
		if (ch < 'A' or ch>'z')throw INPUT_ERROR_AUTHOR_FULL_NAME;
		else
		{
			if (ch >= 'a' and ch <= 'z')ch = ch - 26;
			char* string_ = new char[str.size_ + 1];
			for (int i = 0; i < str.size_; i++)
			{
				string_[i] = str.string_[i];
			}
			string_[str.size_] = ch;
			delete[] str.string_;
			str.size_++;
			str.string_ = new char[str.size_ + 1];
			for (int i = 0; i < str.size_ + 1; i++)
			{
				str.string_[i] = string_[i];
			}
			delete[] string_;
		}
		in.get(ch);
		while (ch == ' ' or ch == '\t')
		{
			if (in.eof())throw INPUT_ERROR_LITTLE_DATA;
			in.get(ch);
		}
		//добовляем точку
		if (ch != '.')throw INPUT_ERROR_AUTHOR_FULL_NAME;
		else
		{
			char* string_ = new char[str.size_ + 1];
			for (int i = 0; i < str.size_; i++)
			{
				string_[i] = str.string_[i];
			}
			string_[str.size_] = ch;
			delete[] str.string_;
			str.size_++;
			str.string_ = new char[str.size_ + 1];
			for (int i = 0; i < str.size_ + 1; i++)
			{
				str.string_[i] = string_[i];
			}
			delete[] string_;
		}
		in.get(ch);
		while (ch == ' ' or ch == '\t')
		{
			if (in.eof())throw INPUT_ERROR_LITTLE_DATA;
			in.get(ch);
		}
		if (in.eof())throw INPUT_ERROR_LITTLE_DATA;
		if (ch != '\n')throw INPUT_ERROR_AUTHOR_FULL_NAME;
		return in;

	}
	//считывание специализации
	else
	{
		char ch;
		in.get(ch);
		while (ch == ' ' or ch == '\t')
		{
			if (in.eof())throw INPUT_ERROR_LITTLE_DATA;
			in.get(ch);
		}
		while (true)
		{
			if (in.eof())throw INPUT_ERROR_LITTLE_DATA;
			if (ch < 'A' or ch>'z')
				if (ch == ' ' or ch == '\n' or ch == '\t')break;
				else throw INPUT_ERROR_GENRE;
			else
			{
				if (ch >= 'A' and ch <= 'Z')ch = ch + 26;
				char* string_ = new char[str.size_ + 1];
				for (int i = 0; i < str.size_; i++)
				{
					string_[i] = str.string_[i];
				}
				string_[str.size_] = ch;
				delete[] str.string_;
				str.size_++;
				str.string_ = new char[str.size_ + 1];
				for (int i = 0; i < str.size_ + 1; i++)
				{
					str.string_[i] = string_[i];
				}
				delete[] string_;
			}
			in.get(ch);
		}
		while (ch == ' ' or ch == '\t')
		{
			if (in.eof())throw INPUT_ERROR_LITTLE_DATA;
			in.get(ch);
		}
		if (ch == '\n')
			if (str != GENRE_1 and str != GENRE_2 and str != GENRE_3 and str != GENRE_4 and str != GENRE_5 and str != GENRE_6) throw INPUT_ERROR_GENRE;
			else return in;
		else throw INPUT_ERROR_GENRE;

	}
}