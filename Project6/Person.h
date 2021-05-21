#pragma once
#include<string>
class Person
{
private:
	int pno; //person number
	std::string nameSurname;

public:
	Person();
	void setPno(int _pno);
	int getPno();
	void setName(std::string _nameSurname);
	std::string getName();

	void printInfo();
};

