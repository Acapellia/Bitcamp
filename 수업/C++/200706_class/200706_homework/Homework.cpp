#include<iostream>
using namespace std;

class Calc {
protected:
	int a, b;
public:
	void setValue(int x, int y);	// x를 a에, y를 b에 저장
	virtual int calculate() = 0;	// 연산을 실행하고 결과 리턴
};
int selNum() {
	int sel;
	cout << "계산을 선택하세요(0 : Add, 1 : Sub, 2 : Mul, 3 : Div 4 : Exit) : ";
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
			cout << "Add 계산입니다" << endl;
			cout << "숫자 2개를 입력하세요 : ";
			cin >> x >> y;
			calc[0]->setValue(x, y);
			num = calc[0]->calculate();
		}
		else if (sel == 1) {
			cout << "Sub 계산입니다" << endl;
			cout << "숫자 2개를 입력하세요 : ";
			cin >> x >> y;
			calc[1]->setValue(x, y);
			num = calc[1]->calculate();
		}
		else if (sel == 2) {
			cout << "Mul 계산입니다" << endl;
			cout << "숫자 2개를 입력하세요 : ";
			cin >> x >> y;
			calc[2]->setValue(x, y);
			num = calc[2]->calculate();
		}
		else if (sel == 3) {
			cout << "Div 계산입니다" << endl;
			cout << "숫자 2개를 입력하세요 : ";
			cin >> x >> y;
			calc[3]->setValue(x, y);
			num = calc[3]->calculate();
		}
		else if (sel == 4) {
			cout << "프로그램을 종료합니다" << endl;
			return;
		}
		else {
			state = 1;
			cout << "다시 선택하세요" << endl;
		}
		if (state != 0) { 
			state = 0;
			cout << "결과는 " << num << "입니다" << endl;
		}
		cout << endl;
	}
}