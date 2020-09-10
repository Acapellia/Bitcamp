#include "EmployeeManager.h"

void EmployeeManager::showMenu() {
	cout << "-------Menu-------" << endl;
	cout << "1. InsertMenu" << endl;
	cout << "2. ShowAllEmployee" << endl;
	cout << "3. Exit" << endl;
	cout << endl;
}
int EmployeeManager::getSelNum() {
	int sel;
	cout << "메뉴를 선택하세요 : ";
	cin >> sel;
	cout << endl;
	return sel;
}
void EmployeeManager::insertEmployee() {
	cout << "---사원 종류를 선택하세요---" << endl;
	cout << "1. Regular Employee" << endl;
	cout << "2. Temp Employee" << endl;
	cout << "3. Daily employee" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
	int sel;
	cout << "종류 : ";
	cin >> sel;
	cout << endl;
	if (sel == 1) { 
		emp[empNum] = new RegularEmployee();
	}
	else if (sel == 2) { 
		emp[empNum] = new TempEmployee();
	}
	else if(sel==3){ 
		emp[empNum] = new DailyEmployee();
	}
	else { cout << "잘 못 입력하셨습니다" << endl; return; }
	emp[empNum++]->inputEmployee();
}
void EmployeeManager::showAllEmployee() {
	if (empNum == 0) {
		cout << "아무도 없습니다..." << endl;
		return;
	}
	for (int i = 0; i < empNum; i++) {
		emp[i]->showEmployee();
		cout << endl;
	}cout << endl;
}