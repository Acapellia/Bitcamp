#include "ForcePolice.h"
void ForcePolice::snap() {
	if (this->handcuffs == 0) {
		cout << "Oh" << endl;
	}
	this->handcuffs--;
	cout << "Snap!!" << endl;
}
void ForcePolice::fireGun() {
	gun.fire();
}