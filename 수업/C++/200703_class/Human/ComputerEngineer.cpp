#include "ComputerEngineer.h"

ComputerEngineer::ComputerEngineer(string n, int a, int nc) : Human(n, a) {
	nComputer = nc;
	cout << "ComputerEngineer ������ ȣ��" << endl;
}
ComputerEngineer::~ComputerEngineer() {
	cout << "ComputerEngineer �Ҹ��� ȣ��" << endl;
}
void ComputerEngineer::overTime() {
	cout << name << "�� �߱��� �մϴ�." << endl;
}
void ComputerEngineer::info() {
	Human::info();
	cout << "��ǻ�� �� : " << nComputer << endl;
}