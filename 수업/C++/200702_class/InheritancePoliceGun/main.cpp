#include<iostream>
#include "ForcePolice.h"
#include "NursePolice.h"
using namespace std;
void main()
{
	ForcePolice fpolice;
	fpolice.wearSuit();
	fpolice.fireGun();
	fpolice.snap();

	cout << "=======================\n";

	NursePolice npoilice;
	npoilice.wearSuit();
	for(int i=0;i<4;i++)
		npoilice.checkTemperature();
}