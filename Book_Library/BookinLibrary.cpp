#include "BookinLibrary.h"
#include "String.h"
#include "List.h"

extern bool order;
extern String GENRE_1;
extern String GENRE_2;
extern String GENRE_4;
extern String GENRE_5;
extern String GENRE_6;
extern BookinLibrary maxobj;
extern BookinLibrary minobj;
extern String INPUT_FILE;
extern String OUTPUT_FILE;
extern String INPUT_ERROR_LITTLE_DATA;
char begin1 = '|';
String INPUT_ERROR_EMPTY_FILE = "FILE IS EMPTY!!!\0";
String INPUT_ERROR_GENRE = "Error!Incorrect genre. \0";
String INPUT_ERROR_NUMBER_OF_BOOKS = "Error! Incorrect number of books! ¹\0";
String INPUT_ERROR_IS_FILE_OPEN = "FILE CAN NOT BE OPEN! \0";
BookinLibrary::BookinLibrary() {}
BookinLibrary::BookinLibrary( String authorsfullname, String title, int year, String genre, int numberofbooks )
{
	authorsfullname_ = authorsfullname;
	title_ = title;
	year_ = year;
	genre_ = genre;
	numberofbooks_ = numberofbooks;
}
BookinLibrary::BookinLibrary(const BookinLibrary& bl)
{
	authorsfullname_ = bl.authorsfullname_;
	title_ = bl.title_;
	year_ = bl.year_;
	genre_ = bl.genre_;
	numberofbooks_ = bl.numberofbooks_;
}
BookinLibrary& BookinLibrary::operator=(const BookinLibrary& bl)
{
	if (&bl == this)return *this;
	authorsfullname_ = bl.authorsfullname_;
	title_ = bl.title_;
	year_ = bl.year_;
	genre_ = bl.genre_;
	numberofbooks_ = bl.numberofbooks_;
	return *this;
}
BookinLibrary::~BookinLibrary() {};
BookinLibrary BookinLibrary::operator+(const BookinLibrary& bl)
{
	int k = numberofbooks_ + bl.numberofbooks_;
	return BookinLibrary(authorsfullname_, title_, year_, genre_, k);
}
BookinLibrary BookinLibrary::operator-(const BookinLibrary& bl)
{
	int k = numberofbooks_ - bl.numberofbooks_;
	return BookinLibrary(authorsfullname_, title_, year_, genre_, k);
}
bool BookinLibrary::operator>(const BookinLibrary& bl)
{
	return numberofbooks_ > bl.numberofbooks_;
}
bool BookinLibrary::operator<(const BookinLibrary& bl)
{
	return numberofbooks_ < bl.numberofbooks_;
}
bool BookinLibrary::operator==(const BookinLibrary& bl)
{
	return (numberofbooks_ == bl.numberofbooks_) and (genre_ == bl.genre_) and (authorsfullname_ == bl.authorsfullname_) and (title_ == bl.title_) and (year_ == bl.year_);
}
bool BookinLibrary::operator<=(const BookinLibrary& bl)
{
	return numberofbooks_ <= bl.numberofbooks_;
}
bool BookinLibrary::operator>=(const BookinLibrary& bl)
{
	return numberofbooks_ >= bl.numberofbooks_;
}
int BookinLibrary::getYear()
{
	return year_;
}
int BookinLibrary::getNumberofbooks()
{
	return numberofbooks_;
}
String BookinLibrary::getGenre()
{
	return genre_;
}
BookinLibrary BookinLibrary::operator++()
{
	numberofbooks_ += 1;
	return *this;
}
BookinLibrary BookinLibrary::operator++(int notused)
{
	BookinLibrary bl(authorsfullname_, title_, year_, genre_, numberofbooks_);
	numberofbooks_ += 1;
	return bl;
}
BookinLibrary BookinLibrary::operator--()
{
	numberofbooks_ -= 1;
	return *this;
}
BookinLibrary BookinLibrary::operator--(int notused)
{
	BookinLibrary bl(authorsfullname_, title_, year_, genre_, numberofbooks_);
	numberofbooks_ -= 1;
	return bl;
}
ostream& operator <<(ostream& out, BookinLibrary& bl)
{

}
