#include<iostream>
#include<string>
using namespace std;
/*
VO(Value Object) : ���� �����ϴ� ���� (c++���� Ŭ������ ���� ����..?)
*/
class Student{
private:
	string name;
	string address;
	char* copy;
	int age;
public:
	Student(){}
	Student(const Student& st) {
		name = st.name;
		address = st.address;
		age = st.age;
		copy = new char[10];
		strcpy(copy, st.copy);
	}
	Student(string n, string addr, int a) {
		name = n; address = addr; age = a;
		copy = new char[10];
		strcpy(copy, "����");
	}
	~Student() { delete[] copy; }
	string getName() { return name; }
	void setName(string n) { name = n; }
	string getAddress() { return address; }
	void setAddress(string addr) { address = addr; }
	int getAge() { return age; }
	void setAge(int a) { age = a;}
	void showStudent() {
		cout << "�̸� : " << name << endl;
		cout << "�ּ� : " << address << endl;
		cout << "���� : " << age << endl;
		cout << "Ư�� : " << copy << endl;
	}
};

void main()
{
	Student* st1 = new Student("ȫ�浿", "������", 24);
	Student st2 = *st1;
	delete st1;
	st2.showStudent();
}