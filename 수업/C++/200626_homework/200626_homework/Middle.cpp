#include<iostream>
#include<cstring>
using namespace std;
//1.swap(&a, &b) �� a�� b�� ���� ��ȯ�ǵ��� �ϴ� swap�Լ��� �����͸� ����ؼ� �ۼ��ϼ���
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void problem1() {
	int a = 10, b = 20;
	swap(&a, &b);
	cout << "a : " << a << " b : " << b << endl;
}
//2.swap(a, b) �� a�� b�� ���� ��ȯ�ǵ��� �ϴ� swap�Լ��� ���۷����� ����ؼ� �ۼ��ϼ���
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void problem2() {
	int a = 10, b = 20;
	swap(a, b);
	cout << "a : " << a << " b : " << b << endl;
}
//3.swap(&a, &b, &c) �� a => b, b => c, c => a�� ���޵ǵ��� �����͸� ����ؼ� �ۼ��ϼ���
void swap(int* a, int* b, int* c) {
	int temp = *c;
	*c = *b;
	*b = *a;
	*a = temp;
}
void problem3() {
	int a = 10, b = 20, c = 30;
	swap(&a, &b, &c);
	cout << "a : " << a << " b : " << b << " c : "<< c << endl;
}
//4.swap(a, b, c) �� a = > b, b = > c, c = > a�� ���޵ǵ��� ���۷����� ����ؼ� �ۼ��ϼ���
void swap(int& a, int& b, int& c) {
	int temp = c;
	c = b;
	b = a;
	a = temp;
}
void problem4() {
	int a = 10, b = 20, c = 30;
	swap(a, b, c);
	cout << "a : " << a << " b : " << b << " c : " << c << endl;
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