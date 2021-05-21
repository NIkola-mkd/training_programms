#include "Young.h"
#include "Person.h"
#include<iostream>

Young::Young() {
}
void Young::setWork(int _w) {
	work = _w;
}
int Young::getWork() {
	return work;
}
void Young::setHealth(int _h) {
	health = _h;
}
int Young::getHealth() {
	return health;
}
void Young::setSkills(int _s) {
	skills = _s;
}
int Young::getSkills() {
	return skills;
}
void Young::setSports(int _sp) {
	sports = _sp;
}
int Young::getSports() {
	return sports;
}
void Young::setTemperament(int _t) {
	temperament = _t;
}
int Young::getTemperament() {
	return temperament;
}
void Young::setSociality(int _soc) {
	sociality = _soc;
}
int Young::getSociality() {
	return sociality;
}

//void Person::printInfo() {
//	std::cout << "Pno: " << pno << std::endl;
//	std::cout << "Name: " << nameSurname << std::endl;
//}


void Young::PrintMarks() {
	std::cout << "Work: " << work << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Skills: " << skills << std::endl;
	std::cout << "Sports: " << sports << std::endl;
	std::cout << "Temperament: " << temperament << std::endl;
	std::cout << "Sociality: " << sociality << std::endl;
}
