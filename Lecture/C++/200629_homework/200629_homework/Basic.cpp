#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<cstring>

using namespace std;
//1.
//int main() {
//	Random r;
//	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
//	for (int i = 0; i < 10; i++) {
//		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
//		cout << n << ' ';
//	}
//	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
//	for (int i = 0; i < 10; i++) {
//		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
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
	cout << "-- 0에서 " << rand_max << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0에서 rand_max(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextinrange(2, 4); // 2에서 4 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}
//2. Oval 클래스 만들기
//#include <iostream>
//using namespace std;
//
//// main() 함수
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
		cout << "Oval 소멸 :" << " width : " << w << " height : " << h << endl;
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
		cout << "원하는 과제를 입력하세요 : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		else if (sel == 2) { problem2(); }
		cout << endl;
	}
	return 0;
}