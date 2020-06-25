#include<iostream>
#include "Position.h"
using namespace std;
int main()
{
	Position pos(10, 10), pos2(20, 20), pos3;
	pos3 = 2 * pos;
	pos3.ShowPosition();
	return 0;
}