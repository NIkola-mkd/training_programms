#pragma once
#include "Person.h"

class Adult :public Person {

private:
	int work;
	int health;
	int skills;
	int sports;
	int temperament;
	int sociality;
	int years;

public:
	Adult();
	void setWork(int _w);
	int getWork();
	void setHealth(int _h);
	int getHealth();
	void setSkills(int _s);
	int getSkills();
	void setSports(int _sp);
	int getSports();
	void setTemperament(int _t);
	int getTemperament();
	void setSociality(int _soc);
	int getSociality();
	void setYears(int _years);
	int getYears();

	void PrintMarks();
	int calc();

};

