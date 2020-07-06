#pragma once
#include "Police.h"
class ForcePolice:public Police
{
private:
	int handcuffs = 3;
	Gun gun;
public:
	void snap();
	void fireGun();
};

