#include<iostream>
using namespace std;

class Calc {
protected:
	int a, b;
public:
	void setValue(int x, int y);	// x�� a��, y�� b�� ����
	virtual int calculate() = 0;	// ������ �����ϰ� ��� ����
};
int selNum() {
	int sel;
	cout << "����� �����ϼ���(0 : Add, 1 : Sub, 2 : Mul, 3 : Div 4 : Exit) : ";
	cin >> sel;
	return sel;
}
void Calc::setValue(int x, int y) {
	a = x; b = y;
}
class Add :public Calc {
public:
	int calculate() { 
		return a + b; }
};
class Sub :public Calc {
public:
	int calculate() { return a - b; }
};
class Mul :public Calc {
public:
	int calculate() { return a * b; }
};
class Div :public Calc {
public:
	int calculate() {
		if (b == 0) { cout << "divide by zero" << endl; return 0; }
		return a / b;
	}
};

void main()
{
	Calc* calc[4] = { new Add() , new Sub(), new Mul(), new Div() };
	while (true) {
		int sel = selNum();
		int num, state = 0;;
		int x=0, y=0;
		
		if (sel == 0) {
			cout << "Add ����Դϴ�" << endl;
			cout << "���� 2���� �Է��ϼ��� : ";
			cin >> x >> y;
			calc[0]->setValue(x, y);
			num = calc[0]->calculate();
		}
		else if (sel == 1) {
			cout << "Sub ����Դϴ�" << endl;
			cout << "���� 2���� �Է��ϼ��� : ";
			cin >> x >> y;
			calc[1]->setValue(x, y);
			num = calc[1]->calculate();
		}
		else if (sel == 2) {
			cout << "Mul ����Դϴ�" << endl;
			cout << "���� 2���� �Է��ϼ��� : ";
			cin >> x >> y;
			calc[2]->setValue(x, y);
			num = calc[2]->calculate();
		}
		else if (sel == 3) {
			cout << "Div ����Դϴ�" << endl;
			cout << "���� 2���� �Է��ϼ��� : ";
			cin >> x >> y;
			calc[3]->setValue(x, y);
			num = calc[3]->calculate();
		}
		else if (sel == 4) {
			cout << "���α׷��� �����մϴ�" << endl;
			return;
		}
		else {
			state = 1;
			cout << "�ٽ� �����ϼ���" << endl;
		}
		if (state != 0) { 
			state = 0;
			cout << "����� " << num << "�Դϴ�" << endl;
		}
		cout << endl;
	}
}