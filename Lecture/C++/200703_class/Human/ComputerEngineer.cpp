#include "ComputerEngineer.h"

ComputerEngineer::ComputerEngineer(string n, int a, int nc) : Human(n, a) {
	nComputer = nc;
	cout << "ComputerEngineer 생성자 호출" << endl;
}
ComputerEngineer::~ComputerEngineer() {
	cout << "ComputerEngineer 소멸자 호출" << endl;
}
void ComputerEngineer::overTime() {
	cout << name << "은 야근을 합니다." << endl;
}
void ComputerEngineer::info() {
	Human::info();
	cout << "컴퓨터 수 : " << nComputer << endl;
}