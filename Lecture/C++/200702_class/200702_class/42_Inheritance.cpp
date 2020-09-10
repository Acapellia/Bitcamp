#include<iostream>
using namespace std;
class Animal {
private:
	string name;
public:
	string getName() { return name; }
	void setName(string n) { name = n; }
	void breathe(){
		cout << "¼ûÀ» ½®´Ù." << endl;
	}
	void move() {
		cout << "¿òÁ÷ÀÎ´Ù." << endl;
	}
	void sleep() {
		cout << "ÀáÀ» ÀÜ´Ù." << endl;
	}
};
class Mammal: public Animal {
private:
public:
	void drinkMilk() {
		cout << "¿ìÀ¯¸¦ ¸¶½Å´Ù." << endl;
	}
};
class Tiger : public Mammal {
public:
	/*void breathe() {

		cout << "È£¶ûÀÌ°¡ ¼ûÀ» ½®´Ù." << endl;
	}
	void move() {
		cout << "È£¶ûÀÌ°¡ ¿òÁ÷ÀÎ´Ù." << endl;
	}
	void sleep() {
		cout << "È£¶ûÀÌ°¡ ÀáÀ» ÀÜ´Ù." << endl;
	}*/
};
class Lion : public Mammal {
public:
	/*void breathe() {
		cout << "»çÀÚ°¡ ¼ûÀ» ½®´Ù." << endl;
	}
	void move() {
		cout << "»çÀÚ°¡ ¿òÁ÷ÀÎ´Ù." << endl;
	}
	void sleep() {
		cout << "»çÀÚ°¡ ÀáÀ» ÀÜ´Ù." << endl;
	}*/
};

void main()
{
	Tiger tiger;
	Lion lion;
	tiger.drinkMilk();
	lion.drinkMilk();
}