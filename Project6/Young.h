#pragma once
#include "Person.h"
class Young:public Person
{
private:
	int work;
	int health;
	int skills;
	int sports;
	int temperament;
	int sociality;

public:
	Young();
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

	void PrintMarks();

};

