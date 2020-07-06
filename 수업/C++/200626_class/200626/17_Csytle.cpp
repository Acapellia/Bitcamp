#include<stdio.h>
#include<iostream>
using namespace std;
struct Student {
	char name[20];
	int age;
};
void inputStudent(Student& st) {
	cout << "이름 입력 : ";
	cin >> st.name;
	cout << "나이 입력 : ";
	cin >> st.age;
}
void showStudent(Student& st) {
	cout << "이름 : " << st.name << endl;
	cout << "나이 : " << st.age << endl;
}
int main()
{
	Student st;
	inputStudent(st);
	showStudent(st);
	return 0;
}