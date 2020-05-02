#include "BookinLibrary.h"
#include "Exception.h"
#include <iomanip>

bool isUpperLetter(char c)
{
	return c >= 'A' && c <= 'Z';
}

bool isLowerLetter(char c)
{
	return c >= 'a' && c <= 'z';
}

bool isLetter(char c)
{
	return isLowerLetter(c) || isUpperLetter(c);
}

bool isNumeral(char c)
{
	return c >= '0' && c <= '9';
}

bool BookinLibrary::isValidAuthorName(const String& authorName)
{
	if (authorName.getSize() == 0 || !isUpperLetter(authorName[0]))
	{
		return false;
	}
	for (int i = 1; i < authorName.getSize(); ++i)
	{
		if (isLetter(authorName[i - 1]) && !(isLowerLetter(authorName[i]) || authorName[i] == ' ')
			|| authorName[i - 1] == ' ' && !isUpperLetter(authorName[i])
			|| !(isLetter(authorName[i]) || authorName[i] == ' '))
		{
			return false;
		}
	}
	return true;
}

bool BookinLibrary::isValidTitle(const String& title)
{
	if (title.getSize() == 0)
	{
		return false;
	}
	for (int i = 0; i < title.getSize(); i++)
	{
		if (!(isLetter(title[i]) || isNumeral(title[i]) || title[i] == ' '))
		{
			return false;
		}
	}
	return true;
}

bool BookinLibrary::isValidPubYear(const int pubYear)
{
	return pubYear > 0 && pubYear <= 2020;
}

bool BookinLibrary::isValidGenre(const String& genre)
{
	if (genre.getSize() == 0 || !isUpperLetter(genre[0]))
	{
		return false;
	}
	for (int i = 1; i < genre.getSize(); ++i)
	{
		if (isLetter(genre[i - 1]) && !(isLowerLetter(genre[i]) || genre[i] == ' ')
			|| genre[i - 1] == ' ' && !isUpperLetter(genre[i])
			|| !(isLetter(genre[i]) || genre[i] == ' '))
		{
			return false;
		}
	}
	return true;
}

bool BookinLibrary::isValidAmount(const int amount)
{
	return amount >= 0;
}

BookinLibrary::BookinLibrary()
{
	authorName_ = "";
	title_ = "";
	pubYear_ = 0;
	genre_ = "";
	amount_ = 0;
}

BookinLibrary::BookinLibrary(const String& authorName, const String& title, int pubYear, const String& genre, int amount)
{
	if (!isValidAuthorName(authorName))
	{
		throw Exception("ERROR! Invalid author name!");
	}
	if (!isValidTitle(title))
	{
		throw Exception("ERROR! INvalid title!");
	}
	if (!isValidPubYear(pubYear))
	{
		throw Exception("Publication year mustn't be a negative number or a year greater than 2020!");
	}
	if (!isValidGenre(genre))
	{
		throw Exception("ERROR! Invalid genre name!");
	}
	if (!isValidAmount(amount))
	{
		throw Exception("ERROR! Amount of books can't be negative!");
	}
	authorName_ = authorName;
	title_ = title;
	pubYear_ = pubYear;
	genre_ = genre;
	amount_ = amount;
}

BookinLibrary::BookinLibrary(const BookinLibrary& bl)
{
	if (this == &bl)
	{
		return;
	}
	authorName_ = bl.authorName_;
	title_ = bl.title_;
	pubYear_ = bl.pubYear_;
	genre_ = bl.genre_;
	amount_ = bl.amount_;
}

String BookinLibrary::getAuthorName() const
{
	return authorName_;
}

String BookinLibrary::getTitle() const
{
	return title_;
}

unsigned short BookinLibrary::getPubYear() const
{
	return pubYear_;
}

String BookinLibrary::getGenre() const
{
	return genre_;
}

unsigned int BookinLibrary::getAmount() const
{
	return amount_;
}

void BookinLibrary::setAuthorName(const String& authorName)
{
	if (!isValidAuthorName(authorName))
	{
		throw Exception("ERROR! Invalid author name!");
	}
	authorName_ = authorName;
}

void BookinLibrary::setTitle(const String& title)
{
	if (!isValidTitle(title))
	{
		throw Exception("ERROR! Invalid title!");
	}
	title_ = title;
}

void BookinLibrary::setPubYear(const int pubYear)
{
	if (!isValidPubYear(pubYear))
	{
		throw Exception("ERROR! Publication year mustn't  be a negative number or a year  greater than 2020!");
	}
	pubYear_ = pubYear;
}

void BookinLibrary::setGenre(const String& genre)
{
	if (!isValidGenre(genre))
	{
		throw Exception("ERROR! Invalid genre name!");
	}
	genre_ = genre;
}

void BookinLibrary::setAmount(const int amount)
{
	if (!isValidAmount(amount))
	{
		throw Exception("ERROR! Amount cant be negative number!");
	}
	amount_ = amount;
}

BookinLibrary& BookinLibrary::operator=(const BookinLibrary& x)
{
	if (this == &x)
	{
		return *this;
	}
	authorName_ = x.authorName_;
	title_ = x.title_;
	pubYear_ = x.pubYear_;
	genre_ = x.genre_;
	amount_ = x.amount_;
	return *this;
}

bool BookinLibrary::operator==(const BookinLibrary& x) const
{
	return authorName_ == x.authorName_ && title_ == x.title_ && pubYear_ == x.pubYear_ && genre_ == x.genre_ && amount_ == x.amount_;
}

bool operator!=(const BookinLibrary& y, const BookinLibrary& x)
{
	return y.authorName_ != x.authorName_ || y.title_ != x.title_ || y.pubYear_ != x.pubYear_ || y.genre_ != x.genre_ || y.amount_ != x.amount_;
}


BookinLibrary BookinLibrary::operator+(const int amount) const
{
	return BookinLibrary(authorName_, title_, pubYear_, genre_, amount_ + amount);
}

BookinLibrary operator-(const BookinLibrary& book, const int amount)
{
	return BookinLibrary(book.authorName_, book.title_, book.pubYear_, book.genre_, book.amount_ - amount);
}

bool BookinLibrary::operator>(const BookinLibrary& x) const
{
	return amount_ > x.amount_;
}
bool operator<(const BookinLibrary& y, const BookinLibrary& x)
{
	return y.amount_ < x.amount_;
}

BookinLibrary operator++(BookinLibrary& b, int)
{
	BookinLibrary temp = b;
	b.amount_++;
	return temp;
}

BookinLibrary& BookinLibrary::operator++()
{
	amount_++;
	return *this;
}

BookinLibrary& BookinLibrary::operator--()
{
	amount_--;
	return *this;
}

BookinLibrary operator--(BookinLibrary& b, int)
{
	BookinLibrary temp = b;
	b.amount_--;
	return temp;
}

void ignoreLines(istream& in, const int lines)
{
	for (int i = 0; i < lines; i++)
	{
		in.ignore(INT_MAX, '\n');
	}
}

istream& operator>>(istream& in, BookinLibrary& b)
{
	String s;
	in >> s;
	if (in.fail() || !BookinLibrary::isValidAuthorName(s))
	{
		if (!in.eof())
		{
			in.clear();
			ignoreLines(in, 4);
		}
		throw Exception("ERROR! Invalid author name!");
	}
	b.authorName_ = s;

	in >> s;
	if (in.fail() || !BookinLibrary::isValidTitle(s))
	{
		if (!in.eof())
		{
			in.clear();
			ignoreLines(in, 3);
		}
		throw Exception("ERROR! Invalid title!");
	}
	b.title_ = s;

	int n;
	in >> n;
	if (in.fail() || !BookinLibrary::isValidPubYear(n))
	{
		if (!in.eof())
		{
			in.clear();
			ignoreLines(in, 3);
		}
		throw Exception("ERROR! Publication year mustn't be negative nember or a year  greater that 2020!");
	}
	ignoreLines(in, 1);
	b.pubYear_ = n;

	in >> s;
	if (in.fail() || !BookinLibrary::isValidGenre(s))
	{
		if (!in.eof())
		{
			in.clear();
			ignoreLines(in, 1);
		}
		throw Exception("ERROR! Invalid genre name!");
	}
	b.genre_ = s;

	in >> n;
	if (in.fail() || !BookinLibrary::isValidAmount(n))
	{
		if (!in.eof())
		{
			in.clear();
			ignoreLines(in, 1);
		}
		throw Exception("ERROR! Amount can't be negative number!");
	}
	ignoreLines(in, 1);
	b.amount_ = n;

	return in;
}

ostream& operator<<(ostream& out, const BookinLibrary& b)
{

	out << setw(30) << b.authorName_
		<< setw(50) << b.title_
		<< setw(7) << b.pubYear_
		<< setw(25) << b.genre_
		<< setw(7) << b.amount_;
	return out;
}

