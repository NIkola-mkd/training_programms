#include "Person.h"
#include "Adult.h"
#include "Young.h"
#include<iostream>
#include<string>

using namespace std;

int main() {

	Adult a[3];
	Young y[2];
	
	a[0].setPno(0);
	a[0].setName ("Nikola");
	a[0].setWork(12);
	a[0].setHealth(10);
	a[0].setSkills(3);
	a[0].setSociality(10);
	a[0].setSports(11);
	a[0].setTemperament(20);
	a[0].setYears(27);

	a[1].setPno(0);
	a[1].setName("N");
	a[1].setWork(22);
	a[1].setHealth(13);
	a[1].setSkills(3);
	a[1].setSociality(10);
	a[1].setSports(15);
	a[1].setTemperament(20);
	a[1].setYears(32);

	a[2].setPno(0);
	a[2].setName("Niko");
	a[2].setWork(22);
	a[2].setHealth(2);
	a[2].setSkills(34);
	a[2].setSociality(2);
	a[2].setSports(11);
	a[2].setTemperament(30);
	a[2].setYears(22);

	y[0].setPno(1);
	y[0].setName("abc");
	y[0].setWork(22);
	y[0].setHealth(2);
	y[0].setSkills(34);
	y[0].setSociality(2);
	y[0].setSports(11);
	y[0].setTemperament(30);
	
	y[1].setPno(1);
	y[1].setName("abcd");
	y[1].setWork(22);
	y[1].setHealth(2);
	y[1].setSkills(34);
	y[1].setSociality(2);
	y[1].setSports(11);
	y[1].setTemperament(30);



	
	cout << "Info Adults:" << endl;
	for (int i = 0;i < 3;i++) {
		a[i].printInfo();
		a[i].PrintMarks();
		cout << endl;
	}
	cout << "-----------------------------------------------------" << endl;
	cout << "Info Young:" << endl;
	for (int i = 0;i < 2;i++) {
		y[i].printInfo();
		y[i].PrintMarks();
		cout << endl;
	}

	cout << "GPA for adults:" << endl;
	for (int i = 0;i < 3;i++) {
		a[i].printInfo();
		a[i].calc();
		cout << endl;
	}

	//find min gpa
	int min;
	min = a[0].calc();
	int cnt = 0;

	for (int i = 0;i < 3;i++) {
		
		if (min > a[i].calc()) {
			min = a[i].calc();
			cnt = i;
		}
	}
	a[cnt].printInfo();

	return 0;
}
