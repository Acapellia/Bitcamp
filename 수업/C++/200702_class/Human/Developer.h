#pragma once
#include "ComputerEngineer.h"
class Developer : public ComputerEngineer
{
protected:
	int nLanguage;
public:
	Developer(string n = "°³¹ßÀÚ", int a = 0, int nc = 0, int nl = 0);
	~Developer();
	void neverEndingStudy();
	void sleep();
	void overTime();
	void info();
};

