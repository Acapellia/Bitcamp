#pragma once
#include "Employee.h"
class TempEmployee : public Employee
{
private:
	int pay;
public:
	void inputEmployee();
	void showEmployee();
	int calcPay();
};

