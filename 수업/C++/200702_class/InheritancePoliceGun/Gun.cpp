#include "Gun.h"
#include<iostream>
using namespace std;
void Gun::fire() {
	if (this->bullet == 0) {
		cout << "Oops!" << endl;
		return;
	}
	this->bullet--;
	cout << "fire" << endl;
}