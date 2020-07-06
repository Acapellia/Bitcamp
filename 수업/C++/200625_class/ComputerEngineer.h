#pragma once
#include"Human.h"
class ComputerEngineer : public Human {
protected:
	int m_nComputer;
public:
	ComputerEngineer(int age, char* Name, int nComputer);
	~ComputerEngineer();
public:
	void Overtime();
	void Info();
	void Play();
};