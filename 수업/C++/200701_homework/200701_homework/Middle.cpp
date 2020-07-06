#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<cstring>
#include<string>

using namespace std;
//1. Fruit 프로젝트를
//seller.saleApple(buyer, 2000);
//처럼 호출할 수 있도록 수정하세요
void problem1() {

}

void problem2() {
}

void problem3() {

}
//4. Add, Sub, Mul, Div 클래스를 만듭니다.
//이 클래스들은 공통적으로 4개의 멤버를 가지고 있습니다
//int a, b;
//void setValue(int x, int y);	// x를 a에, y를 b에 저장
//int calculate()					// 연산을 실행하고 결과 리턴
//프로그램은 무한루프를 돕니다
//
//3 4 *
//= > 12
//5 2 /
//= > 2
class Add {
	double a, b;
public:
	void setValue(int x, int y) {
		a = x; b = y;
	}
	int calculate() {
		return a + b;
	}
};
class Sub {
	double a, b;
public:
	void setValue(int x, int y) {
		a = x; b = y;
	}
	int calculate() {
		return a - b;
	}
};
class Mul {
	double a, b;
public:
	void setValue(int x, int y) {
		a = x; b = y;
	}
	int calculate() {
		return a * b;
	}
};
class Div {
	double a, b;
public:
	void setValue(int x, int y) {
		a = x; b = y;
	}
	int calculate() {
		if (b == 0) { cout << "divide by zero" << endl; return 0; }
		return a / b;
	}
};
void problem4() {
	while (true) {
		int num1, num2;
		char op;
		cout << "두 수와 연산자를 입력하세요 : ";
		cin >> num1 >> num2 >> op;
		switch (op) {
		case '+': Add add; add.setValue(num1, num2); 
			cout << "= > " << add.calculate() << endl; break;
		case '-': Sub sub; sub.setValue(num1, num2); 
			cout << "= > " << sub.calculate() << endl; break;
		case '*': Mul mul; mul.setValue(num1, num2); 
			cout << "= > " << mul.calculate() << endl; break;
		case '/': Div div; div.setValue(num1, num2); 
			cout << "= > " << div.calculate() << endl; break;
		case 'x': cout << "프로그램 종료" << endl; return;
		default: cout << "다시 입력하세요" << endl; break;
		}
	}
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
		else if (sel == 4) { problem4(); }
		cout << endl;
	}
	return 0;
}