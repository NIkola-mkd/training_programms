#include "Person.h"
#include<iostream>

Person::Person() {};

void Person::setPno(int _pno) {
	pno = _pno;
}

int Person::getPno() {
	return pno;
}

void Person::setName(std::string _nameSurname) {
	nameSurname = _nameSurname;
}

std::string Person::getName() {
	return nameSurname;
}

void Person::printInfo() {
	std::cout << "PNO: " << pno << std::endl;
	std::cout << "Name Surname: " << nameSurname << std::endl;
}