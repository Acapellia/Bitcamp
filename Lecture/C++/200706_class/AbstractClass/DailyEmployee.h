#pragma once
#include "Employee.h"
class DailyEmployee : public Employee
{
private:
	int perTimePay;
	int workHour;
public:
	void inputEmployee();
	void showEmployee();
	int calcPay();
};

