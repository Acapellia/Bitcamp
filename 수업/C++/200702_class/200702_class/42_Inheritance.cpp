#include<iostream>
using namespace std;
class Animal {
private:
	string name;
public:
	string getName() { return name; }
	void setName(string n) { name = n; }
	void breathe(){
		cout << "���� ����." << endl;
	}
	void move() {
		cout << "�����δ�." << endl;
	}
	void sleep() {
		cout << "���� �ܴ�." << endl;
	}
};
class Mammal: public Animal {
private:
public:
	void drinkMilk() {
		cout << "������ ���Ŵ�." << endl;
	}
};
class Tiger : public Mammal {
public:
	/*void breathe() {

		cout << "ȣ���̰� ���� ����." << endl;
	}
	void move() {
		cout << "ȣ���̰� �����δ�." << endl;
	}
	void sleep() {
		cout << "ȣ���̰� ���� �ܴ�." << endl;
	}*/
};
class Lion : public Mammal {
public:
	/*void breathe() {
		cout << "���ڰ� ���� ����." << endl;
	}
	void move() {
		cout << "���ڰ� �����δ�." << endl;
	}
	void sleep() {
		cout << "���ڰ� ���� �ܴ�." << endl;
	}*/
};

void main()
{
	Tiger tiger;
	Lion lion;
	tiger.drinkMilk();
	lion.drinkMilk();
}