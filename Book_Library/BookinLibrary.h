#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include "String.h"
#include "List.h"

using namespace std;

class BookinLibrary
{
public:
	BookinLibrary();
	BookinLibrary(String, String,int,String, int);
	BookinLibrary(const BookinLibrary&);
	BookinLibrary& operator =(const BookinLibrary&);
	~BookinLibrary();
	BookinLibrary operator + (const BookinLibrary&);
	BookinLibrary operator - (const BookinLibrary&);
	bool operator >(const BookinLibrary&);
	bool operator <(const BookinLibrary&);
	bool operator ==(const BookinLibrary&);
	bool operator >=(const BookinLibrary&);
	bool operator <=(const BookinLibrary&);
	int getYear();
	int getNumberofbooks();
	String getGenre();
	BookinLibrary operator ++();
	BookinLibrary operator ++ (int);
	BookinLibrary operator --();
	BookinLibrary operator -- (int);
private:
	String authorsfullname_;
	String title_;
	String genre_;
	int year_ ;
	int numberofbooks_;
	

	friend ostream& operator <<(ostream&, BookinLibrary& );
	friend istream& operator >>(istream&, BookinLibrary&);
};


bool input(List<int, String>&);
void output(List<int, String>&);