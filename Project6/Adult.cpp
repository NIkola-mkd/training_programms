#include "Adult.h"
#include "Person.h"
#include<iostream>

Adult::Adult() {
}
void Adult::setWork(int _w) {
	work = _w;
}
int Adult::getWork() {
	return work;
}
void Adult::setHealth(int _h) {
	health = _h;
}
int Adult::getHealth() {
	return health;
}
void Adult::setSkills(int _s) {
	skills = _s;
}
int Adult::getSkills() {
	return skills;
}
void Adult::setSports(int _sp) {
	sports = _sp;
}
int Adult::getSports() {
	return sports;
}
void Adult::setTemperament(int _t) {
	temperament = _t;
}
int Adult::getTemperament() {
	return temperament;
}
void Adult::setSociality(int _soc) {
	sociality = _soc;
}
int Adult::getSociality() {
	return sociality;
}
void Adult::setYears(int _years) {
	years = _years;
}
int Adult::getYears() {
	return years;
}

//void Person::printInfo() {
//	std::cout << "Pno: " << pno << std::endl;
//	std::cout << "Name: " << nameSurname << std::endl;
//}

void Adult::PrintMarks() {
	std::cout << "Work: " << work << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Skills: " << skills << std::endl;
	std::cout << "Sports: " << sports << std::endl;
	std::cout << "Temperament: " << temperament << std::endl;
	std::cout << "Sociality: " << sociality << std::endl;
	std::cout << "Years: " << years << std::endl;
}

int Adult::calc() {
	int gpa=1;
	int sum = 0;

	sum = work + health + skills + sports + temperament + sociality;

	gpa = sum / 6;
	
	return gpa;
}