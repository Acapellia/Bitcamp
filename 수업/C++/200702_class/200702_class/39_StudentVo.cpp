#include<iostream>
#include<string>
using namespace std;
/*
VO(Value Object) : 값을 저장하는 공간 (c++에서 클래스로 구현 가능..?)
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
		strcpy(copy, "복사");
	}
	~Student() { delete[] copy; }
	string getName() { return name; }
	void setName(string n) { name = n; }
	string getAddress() { return address; }
	void setAddress(string addr) { address = addr; }
	int getAge() { return age; }
	void setAge(int a) { age = a;}
	void showStudent() {
		cout << "이름 : " << name << endl;
		cout << "주소 : " << address << endl;
		cout << "나이 : " << age << endl;
		cout << "특성 : " << copy << endl;
	}
};

void main()
{
	Student* st1 = new Student("홍길동", "지리산", 24);
	Student st2 = *st1;
	delete st1;
	st2.showStudent();
}