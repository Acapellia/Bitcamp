#include<iostream>
#include<windows.h>
#include "StarUnit.h"
#include "Scv.h"
#include "Hydra.h"
#include "Marine.h"
#include<ctime>
#include<cstdlib>

using namespace std;

int randomSleep() {
	int delay = rand() % 2000 + 500;
	Sleep(delay);
	return delay;
}
void hitAndRun(StarUnit* pUnit) {
	cout << "���� : ";
	pUnit->attack();
	if (randomSleep() < 1000) { cout << "��� : "; pUnit->die(); }
	else { cout << "���� : "; pUnit->move(); }
	cout << "=================" << endl;
}
void main()
{
	srand((unsigned)time(NULL));
	StarUnit* unit[] = { new Scv, new Marine(), new Hydra() };
	hitAndRun(unit[0]);
	hitAndRun(unit[1]);
	hitAndRun(unit[2]);

}