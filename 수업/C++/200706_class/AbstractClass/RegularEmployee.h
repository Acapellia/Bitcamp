#pragma once
#include "Employee.h"
class RegularEmployee : public Employee
{
private:
	int annualPay;
	int bonus;
public:
	void inputEmployee();
	void showEmployee();
	int calcPay();
};

