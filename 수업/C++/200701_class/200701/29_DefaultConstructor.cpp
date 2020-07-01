#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

class Student {
private:
	char name[20];
public:
	void setName(const char* n) {
		strncpy(name, n, strlen(n));
	}
	char* getName() {
		return name;
	}
	void showName() {
		cout << "ÀÌ¸§ : " << name << endl;
	}
};

void main()
{
	Student st;
}