#include "Developer.h"
Developer::Developer(string n, int a, int nc, int nl):ComputerEngineer(n, a, nc) {
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