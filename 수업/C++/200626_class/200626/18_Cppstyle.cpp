#include<stdio.h>
#include<iostream>
using namespace std;
struct Student {
	char name[20];
	int age;
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