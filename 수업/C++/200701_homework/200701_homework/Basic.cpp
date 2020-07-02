#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<cstring>
#include<string>

using namespace std;
//1. main()의 실행 결과가 다음과 같도록 Tower클래스를 작성하세요
//
//높이는 1미터
//높이는 100미터
class Tower {
private:
	int height;
public:
	Tower() { height = 1; }
	Tower(int _h) { height = _h; }
	int getHeight() {
		return height;
	}
};
void problem1() {
	Tower myTower;
	Tower seoulTower(100);
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}
//2. 날짜를 다루는 Date 클래스를 작성하고자 합니다.
//Date를 이용하는 main()과 실행결과는 다음과 같습니다.
//클래스 Date를 작성하여 아래 프로그램에 추가하세요.
//
//1945년 8월 15일
//2014, 3, 20
class Date {
private:
	int year, month, day;
	string date;
public:
	Date() {}
	Date(int _y, int _m, int _d) {
		year = _y; month = _m; day = _d;
	}
	Date(string _d) {
		date = _d;
		int ndate[3] = { 0 };
		int idx=0, temp = 0;
		for (int i = 0; i < date.length(); i++) {
			if (date[i] != '/') {
				temp *= 10;
				temp += (date[i] - '0');
			}
			else {
				ndate[idx++] = temp;
				temp = 0;
			}
		}
		ndate[idx++] = temp;
		year = ndate[0]; month = ndate[1]; day = ndate[2];
	}
	void show() {
		string str[3] = { "년","월","일" };
		int idx = 0;
		for (int i = 0; i < date.length(); i++) {
			if (date[i] != '/') {
				cout << date[i]; 
			}
			else { 
				cout << str[idx++] << " "; 
			}
		}
		cout << endl;
	}
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
};
void problem2() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
	cout << independenceDay.getYear() << ',' << independenceDay.getMonth()
		<< ',' << independenceDay.getDay() << endl;
}

#include "Box.h"

void problem3() {
	Box b(10, 2);
	b.draw();
	cout << endl;
	b.setSize(7, 4);
	b.setFill('^');
	b.draw();
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
		else if (sel == 3) { problem3(); }
		cout << endl;
	}
	return 0;
}