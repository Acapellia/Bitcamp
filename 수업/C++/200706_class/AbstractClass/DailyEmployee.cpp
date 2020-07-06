#include "DailyEmployee.h"
void DailyEmployee::inputEmployee() {
	Employee::inputEmployee();
	cout << "시급을 입력:";
	cin >> this->perTimePay;
	cout << "일하는 시간을 입력:";
	cin >> this->workHour;
}
void DailyEmployee::showEmployee() {
	Employee::showEmployee();
	cout << "시급을 입력 : " << this->perTimePay << endl;
	cout << "일하는 시간을 입력 : " << this->workHour << endl;
	cout << "월급 : " << calcPay() << endl;
}
int DailyEmployee::calcPay() {
	return this->perTimePay * this->workHour * 30;
}