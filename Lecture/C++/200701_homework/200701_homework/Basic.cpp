#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<cstring>
#include<string>

using namespace std;
//1. main()�� ���� ����� ������ ������ TowerŬ������ �ۼ��ϼ���
//
//���̴� 1����
//���̴� 100����
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
	cout << "���̴� " << myTower.getHeight() << "����" << endl;
	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
}
//2. ��¥�� �ٷ�� Date Ŭ������ �ۼ��ϰ��� �մϴ�.
//Date�� �̿��ϴ� main()�� �������� ������ �����ϴ�.
//Ŭ���� Date�� �ۼ��Ͽ� �Ʒ� ���α׷��� �߰��ϼ���.
//
//1945�� 8�� 15��
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
		string str[3] = { "��","��","��" };
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
		cout << "���ϴ� ������ �Է��ϼ��� : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		else if (sel == 2) { problem2(); }
		else if (sel == 3) { problem3(); }
		cout << endl;
	}
	return 0;
}