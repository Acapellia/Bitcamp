#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
#define NAME_LEN 5
class Student {
private:
	char* name;
public:
	Student() { 
		name = new char[NAME_LEN]; 
	}
	Student(const Student &t) {
		name = new char[NAME_LEN];
		strcpy(name, t.name);
	}
	~Student() { 
		cout << "delete : " << name << endl; 
		delete[] name; 
	}
	void setName(const char* n) {
		strncpy_s(name, sizeof(name), n, strlen(n));
	}
	string getName() {
		return name;
	}
	void showName() {
		cout << "ÀÌ¸§ : " << name << endl;
	}
	Student operator =(const Student& tst) {
		strcpy(name, tst.name);
		return (*this);
	}
};

void main()
{
	char* name = "Name";
	Student st;
	st.setName(name);
	Student st1 = st;
	st1.setName("ddd");
	st.showName();
	st1.showName();
}