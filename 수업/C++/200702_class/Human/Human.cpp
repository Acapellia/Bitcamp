#include "Human.h"
Human::Human(string n = "사람", int a = 0) {
	name = n; age = a;
}
Human::~Human() {
	cout << "Human 소멸자" << endl;
}
void Human::eat() {
	cout << name << "은 밥을 먹는다." << endl;
}
void Human::sleep() {
	cout << name << "은 잠을 잔다." << endl;
}
void Human::work() {
	cout << name << "은 일을 한다." << endl;
}
void Human::info() {
	cout << "이름 : " << name << endl;
	cout << "나이 : " << age << endl;
}