#include "Developer.h"
Developer::Developer(string n = "������", int a = 0, int nc = 0, int nl = 0):ComputerEngineer(name, age, nComputer) {
	nLanguage = nl;
	cout << "Developer ������ ȣ��" << endl;
}
Developer::~Developer() {
	cout << "Developer �Ҹ��� ȣ��" << endl;
}
void Developer::neverEndingStudy() {
	cout << name << "�� �� ���θ� �Ѵ�." << endl;
}
void Developer::sleep() {
	cout << name << "�� �ʰ� �� ���� �ִ�." << endl;
}
void Developer::overTime() {
	ComputerEngineer::overTime();
	cout << "������ �޽��� ������" << endl;
}
void Developer::info() {
	ComputerEngineer::info();
	cout << "����ϴ� ����� �� : " << nLanguage << endl;
}