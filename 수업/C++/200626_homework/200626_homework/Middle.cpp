#include<iostream>
#include<cstring>
using namespace std;
//1.swap(&a, &b) 시 a와 b의 값이 교환되도록 하는 swap함수를 포인터를 사용해서 작성하세요
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
//2.swap(a, b) 시 a와 b의 값이 교환되도록 하는 swap함수를 레퍼런스를 사용해서 작성하세요
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
//3.swap(&a, &b, &c) 시 a => b, b => c, c => a에 전달되도록 포인터를 사용해서 작성하세요
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
//4.swap(a, b, c) 시 a = > b, b = > c, c = > a에 전달되도록 레퍼런스를 사용해서 작성하세요
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