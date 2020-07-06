#pragma once
#include "ComputerEngineer.h"
class Programmer : public ComputerEngineer {
protected:
	int m_nLanguage;
public:
	Programmer(int age, char* Name, int nComputer, int nLanguage);
	~Programmer();
public:
	void NeverEndingStudy();
	void Sleep();
	void Overtime();
	void Info();
	void Play();
};