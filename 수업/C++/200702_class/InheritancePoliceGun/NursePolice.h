#pragma once
#include "Police.h"
class NursePolice : public Police
{
private:
	int cnt = 0;
	int thermomoeter = 5;
public:
	void checkTemperature();
};

