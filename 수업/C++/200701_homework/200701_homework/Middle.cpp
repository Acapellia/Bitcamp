#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<cstring>
#include<string>

using namespace std;
//1. Fruit ������Ʈ��
//seller.saleApple(buyer, 2000);
//ó�� ȣ���� �� �ֵ��� �����ϼ���
void problem1() {

}

void problem2() {
}

void problem3() {

}
//4. Add, Sub, Mul, Div Ŭ������ ����ϴ�.
//�� Ŭ�������� ���������� 4���� ����� ������ �ֽ��ϴ�
//int a, b;
//void setValue(int x, int y);	// x�� a��, y�� b�� ����
//int calculate()					// ������ �����ϰ� ��� ����
//���α׷��� ���ѷ����� ���ϴ�
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
		cout << "�� ���� �����ڸ� �Է��ϼ��� : ";
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
		case 'x': cout << "���α׷� ����" << endl; return;
		default: cout << "�ٽ� �Է��ϼ���" << endl; break;
		}
	}
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
		else if (sel == 4) { problem4(); }
		cout << endl;
	}
	return 0;
}