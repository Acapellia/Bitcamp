#include<stdio.h>
#include<iostream>
using namespace std;
class Student {
	char name[20];
	int age;
public:
	void inputStudent() {
		cout << "�̸� �Է� : ";
		cin >> name;
		cout << "���� �Է� : ";
		cin >> age;
	}
	void showStudent() {
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
};
int main()
{
	Student st;
	st.inputStudent();
	st.showStudent();
	return 0;
}