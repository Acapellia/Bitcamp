#include "DailyEmployee.h"
void DailyEmployee::inputEmployee() {
	Employee::inputEmployee();
	cout << "�ñ��� �Է�:";
	cin >> this->perTimePay;
	cout << "���ϴ� �ð��� �Է�:";
	cin >> this->workHour;
}
void DailyEmployee::showEmployee() {
	Employee::showEmployee();
	cout << "�ñ��� �Է� : " << this->perTimePay << endl;
	cout << "���ϴ� �ð��� �Է� : " << this->workHour << endl;
	cout << "���� : " << calcPay() << endl;
}
int DailyEmployee::calcPay() {
	return this->perTimePay * this->workHour * 30;
}