#pragma once
#include "Human.h"
class ComputerEngineer : public Human
{
protected:
	int nComputer;
public:
	ComputerEngineer(string n="��ǻ�� �����Ͼ�", int a=0, int nc=0);
	~ComputerEngineer();
	void overTime();
	void info();
};

