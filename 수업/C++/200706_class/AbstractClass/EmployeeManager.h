#pragma once
#include<iostream>
#include "Employee.h"
#include "RegularEmployee.h"
#include "DailyEmployee.h"
#include "TempEmployee.h"
#define EMP_NUM 100
class EmployeeManager
{
private:
	Employee* emp[EMP_NUM];
	int empNum=0;
public:
	void showMenu();
	int getSelNum();
	void insertEmployee();
	void showAllEmployee();
};

