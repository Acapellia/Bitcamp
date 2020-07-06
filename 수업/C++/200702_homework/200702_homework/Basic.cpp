#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<cstring>
#include<string>

using namespace std;
//1. Point Ŭ������ ��ӹ��� ColorPointŬ������ �ۼ��ϰ�, �ϼ��ϼ���
class Point {
protected:
	int x, y;
public:
	Point() {}
	Point(int x, int y) {
		this->x = x; this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};
class ColorPoint :Point {
private:
	string color;
public:
	ColorPoint(int x, int y, string c) {
		this->x = x; this->y = y; this->color = c;
	}
	void setPoint(int x, int y) {
		this->x = x; this->y = y;
	}
	void setColor(string c) {
		this->color = c;
	}
	void show() {
		cout << "point : " << "(" << x << "," << y << ")" << endl;
		cout << "color : " << color << endl;
	}
};
void problem1() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}

int main()
{
	while (1) {
		int sel;
		cout << "���ϴ� ������ �Է��ϼ��� : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		cout << endl;
	}
	return 0;
}