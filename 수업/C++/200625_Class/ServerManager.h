#pragma once
#include "ComputerEngineer.h"
class ServerManager :public ComputerEngineer {
protected:
	int m_nManagedComputer;
public:
	ServerManager(int age, char* Name, int nComputer, int nManagedComputer);
	~ServerManager();
public:
	void Work();
	void Info();
	void Play();
};