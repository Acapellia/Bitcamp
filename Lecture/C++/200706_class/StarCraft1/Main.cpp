#include<iostream>
#include<windows.h>
#include<ctime>
#include<cstdlib>
#include "StarUnit.h"
#include "Scv.h"
#include "Hydra.h"
#include "Marine.h"
#include "FireSoldier.h"

using namespace std;

int randomSleep() {
	int delay = rand() % 2000 + 500;
	Sleep(delay);
	return delay;
}

void hitAndRun(StarUnit* pUnit) {
	cout << "°ø°Ý : ";
	pUnit->attack();
	if (randomSleep() < 1000) { cout << "»ç¸Á : "; pUnit->die(); }
	else { cout << "µµ¸Á : "; pUnit->move(); }
	cout << "=================" << endl;
}

void main()
{
	srand((unsigned)time(NULL));

	StarUnit* unit[] = { new Scv(), new Marine(), new Hydra(), new  FireSoldier()};

	hitAndRun(unit[0]);
	hitAndRun(unit[1]);
	hitAndRun(unit[2]);
	hitAndRun(unit[3]);

	delete[] unit;
}