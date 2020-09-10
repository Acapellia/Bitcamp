#include<iostream>
#include "Employee.h"
#include "RegularEmployee.h"
#include "DailyEmployee.h"
#include "TempEmployee.h"
#include "EmployeeManager.h"
using namespace std;

void main()
{
	EmployeeManager em;
	while(true) {
		em.showMenu();
		int sel = em.getSelNum();
		if (sel == 1) { em.insertEmployee(); }
		else if (sel == 2) { em.showAllEmployee(); }
		else if (sel == 3) { cout << "프로그램을 종료합니다." << endl; return; }
		cout << endl;
	}
}