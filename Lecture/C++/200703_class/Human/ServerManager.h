#pragma once
#include "ComputerEngineer.h"
class ServerManager : public ComputerEngineer
{
protected:
	int nManagedServer;
public:
	ServerManager(string n = "����������", int a = 0, int nc = 0, int ns = 0);
	~ServerManager();
	void work();
	void info();
};

