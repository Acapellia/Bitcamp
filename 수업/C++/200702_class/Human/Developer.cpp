#include "Developer.h"
Developer::Developer(string n = "개발자", int a = 0, int nc = 0, int nl = 0):ComputerEngineer(name, age, nComputer) {
	nLanguage = nl;
	cout << "Developer 생성자 호출" << endl;
}
Developer::~Developer() {
	cout << "Developer 소멸자 호출" << endl;
}
void Developer::neverEndingStudy() {
	cout << name << "은 늘 공부를 한다." << endl;
}
void Developer::sleep() {
	cout << name << "은 늦게 잘 때가 있다." << endl;
}
void Developer::overTime() {
	ComputerEngineer::overTime();
	cout << "다음에 휴식을 취하자" << endl;
}
void Developer::info() {
	ComputerEngineer::info();
	cout << "사용하는 언어의 수 : " << nLanguage << endl;
}