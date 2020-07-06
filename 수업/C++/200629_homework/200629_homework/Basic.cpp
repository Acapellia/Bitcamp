#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<cstring>

using namespace std;
//1.
//int main() {
//	Random r;
//	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
//	for (int i = 0; i < 10; i++) {
//		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
//		cout << n << ' ';
//	}
//	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;
//	for (int i = 0; i < 10; i++) {
//		int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ����
//		cout << n << ' ';
//	}
//	cout << endl;
//}
#define rand_max 32767

class Random {
public:
	Random() {
		srand((unsigned)time(NULL));
	}
	int next() {
		return rand();
	}
	int nextinrange(int n1, int n2) {
		return n1 + (rand() % (n2 - n1+1));
	}
};
void problem1() {
	Random r;
	cout << "-- 0���� " << rand_max << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0���� rand_max(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextinrange(2, 4); // 2���� 4 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}
//2. Oval Ŭ���� �����
//#include <iostream>
//using namespace std;
//
//// main() �Լ�
//int main() {
//	Oval a, b(3, 4);
//	a.set(10, 20);
//	a.show();
//	cout << b.getWidth() << ", " << b.getHeight() << endl;
//}
class Oval {
private:
	int w, h;
public:
	Oval(){}
	Oval(int _w, int _h){
		w = _w; h = _h;
	}
	~Oval() {
		cout << "Oval �Ҹ� :" << " width : " << w << " height : " << h << endl;
	}
	void set(int _w, int _h) {
		w = _w; h = _h;
	}
	void show() {
		cout << "Width : " << w << " Height : " << h<<endl;
	}
	int getWidth() {
		return w;
	}
	int getHeight() {
		return h;
	}
};
void problem2() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
}

int main()
{
	while (1) {
		int sel;
		cout << "���ϴ� ������ �Է��ϼ��� : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		else if (sel == 2) { problem2(); }
		cout << endl;
	}
	return 0;
}