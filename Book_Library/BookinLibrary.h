#pragma once
#include "String.h"

class BookinLibrary
{
private:

	String authorName_;
	String title_;
	unsigned short pubYear_;
	String genre_;
	unsigned int amount_;



	static bool isValidAuthorName(const String& authorName);
	static bool isValidTitle(const String& title);
	static bool isValidPubYear(const int pubYear);
	static bool isValidGenre(const String& genre);
	static bool isValidAmount(const int amount);

public:

	BookinLibrary(); 
	BookinLibrary(const String& authorName, const String& title, int pubYear, const String& genre, int amount);
	BookinLibrary(const BookinLibrary& book);



	String getAuthorName() const; 
	String getTitle() const;
	unsigned short getPubYear() const;
	String getGenre() const;
	unsigned int getAmount() const;



	void setAuthorName(const String& authorName);
	void setTitle(const String& title);
	void setPubYear(const int pubYear);
	void setGenre(const String& genre);
	void setAmount(const int amount);


	BookinLibrary& operator=(const BookinLibrary& x);

	bool operator==(const BookinLibrary& x) const;
	friend bool operator!=(const BookinLibrary& y, const BookinLibrary& x);

	BookinLibrary operator+(const int amount) const;
	friend BookinLibrary operator-(const BookinLibrary& book, const int amount);

	bool operator>(const BookinLibrary& x) const;
	friend bool operator<(const BookinLibrary& y, const BookinLibrary& x);

	BookinLibrary& operator++(); 
	friend BookinLibrary operator++(BookinLibrary& b, int);

	BookinLibrary& operator--(); 
	friend BookinLibrary operator--(BookinLibrary& b, int);

	friend std::istream& operator>>(std::istream& in, BookinLibrary& b);
	friend std::ostream& operator<<(std::ostream& out, const BookinLibrary& b);

};