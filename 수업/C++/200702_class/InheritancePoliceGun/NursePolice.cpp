#include "NursePolice.h"
void NursePolice::checkTemperature() {
	cnt++;
	if (cnt > 3) {
		cout << "I don't have any Gun..."<<endl;
	}
	else {
		if (this->thermomoeter == 0) {
			cout << "No!!" << endl;
		}
		this->thermomoeter--;
		cout << "36.5กษ" << endl;
	}
	
}