#pragma once
#include "Human.h"
class ComputerEngineer : public Human
{
protected:
	int nComputer;
public:
	ComputerEngineer(string n="컴퓨터 엔지니어", int a=0, int nc=0);
	~ComputerEngineer();
	void overTime();
	void info();
};

