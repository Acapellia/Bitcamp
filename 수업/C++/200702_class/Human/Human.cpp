#include "Human.h"
Human::Human(string n = "���", int a = 0) {
	name = n; age = a;
}
Human::~Human() {
	cout << "Human �Ҹ���" << endl;
}
void Human::eat() {
	cout << name << "�� ���� �Դ´�." << endl;
}
void Human::sleep() {
	cout << name << "�� ���� �ܴ�." << endl;
}
void Human::work() {
	cout << name << "�� ���� �Ѵ�." << endl;
}
void Human::info() {
	cout << "�̸� : " << name << endl;
	cout << "���� : " << age << endl;
}