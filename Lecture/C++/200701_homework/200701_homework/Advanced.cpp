#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<cstring>
#include<string>

using namespace std;
//1. ���� ���� �߻���Ű�� Random Ŭ�����Դϴ�.
//// ������ ������ �����ϰ� �����ϴ� Ŭ����
class Random {
public:
	Random(); // ������. ���� seed�� �����Ѵ�.
	int next(); // ���� ������ �����Ѵ�.
	int nextInRange(int low, int high); // low�� high ������ ���� ������ �����Ѵ�.
};

Random::Random() {
	srand((unsigned)time(0)); // ������ seed�� �����Ͽ� �� ������ �ٸ� ���� ���� ������ �Ѵ�.
}

int Random::next() {
	return rand(); // 0���� RAND_MAX ������ ������ ���� ����
}

int Random::nextInRange(int low, int high) {
    int range=(high-low)+1;
    return low + (rand() % range); // low�� high ������ ���� ������ �����Ѵ�. 
}

void problem1() {
	Random r;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}
//2. 1���� �����ؼ� ¦�� ������ �����ϰ� �߻���Ű�� EvenRandom Ŭ������ �ۼ��ϰ�
//10���� ¦���� �����ϰ� ����ϴ� ���α׷��� �ϼ��ϼ���.
//0�� ¦���� ó���մϴ�.
class EvenRandom {
public:
	EvenRandom() {
		srand((unsigned)time(0));
	}
	int next() {
		int n = rand();
		if (n % 2 != 0) n++;
		return n;
	}
};
void problem2() {
	EvenRandom er;
	for (int i = 0; i < 10; i++) {
		cout << er.next()<<" ";
	}
	cout << endl;
}
//3. ¦��, Ȧ���� ������ �� �ִ� �����ڸ� ���� SelectableRandom Ŭ������ �ۼ��ϰ�
//���� ¦�� 10��, Ȧ�� 10���� �����ϰ� �߻���Ű�� ���α׷��� �ۼ��ϼ���.
class SelectableRandom {
private:
	int sel;
public:
	SelectableRandom() {
		srand((unsigned)time(0));
	}
	SelectableRandom(int _sel) {
		sel = _sel;
		srand((unsigned)time(0));
	}
	int next() {
		int n = rand();
		if (sel == 0) { // ¦
			if (n % 2 != 0) n++;
		}
		else if (sel == 1) { // Ȧ
			if (n % 2 != 1) n++;
		}
		return n;
	}
};
void problem3() {
	SelectableRandom sre(0), sro(1); // even 0 odd 1
	cout << "¦��" << endl;
	for (int i = 0; i < 10; i++) {
		cout << sre.next() << " ";
	}
	cout << endl;

	cout << "Ȧ��" << endl;
	for (int i = 0; i < 10; i++) {
		cout << sro.next() << " ";
	}
	cout << endl;
}

//4. intŸ���� ������ ��üȭ�� Integer Ŭ������ �ۼ��ϼ���.
//Integer Ŭ������ Ȱ���ϴ� �ڵ�� ������ �����ϴ�.
class Integer {
	int num;
public:
	Integer() {}
	Integer(int n) { num = n; }
	Integer(string sn) { 
		int temp=0;
		for (int i = 0; i < sn.length(); i++) {
			temp *= 10;
			temp += sn[i] - '0';
		}
		num = temp;
	}
	int get() { return num; }
	void set(int n) { num = n; }
	int isEven() {
		return num % 2 == 0 ? 1 : 0;
	}
};
void problem4() {
	Integer n(30);
	cout << n.get() << ' ';		// 30���
	n.set(50);
	cout << n.get() << ' ';		// 50���
	cout << endl;

	Integer m("300");
	cout << m.get() << ' ';		// 300���
	cout << m.isEven();			// true(������ 1) ���
	cout << endl;

	Integer m2("277");
	cout << m2.get() << ' ';
	cout << m2.isEven();
}
//5. Accumulator Ŭ������ �����ϼ���.

class Accumulator {
	int value;
public:
	Accumulator(int value);
	Accumulator& add(int n);
	int get();
};
Accumulator::Accumulator(int value) {
	this->value = value;
}
Accumulator& Accumulator::add(int n) {
	value += n;
	return *this;
}
int Accumulator::get() {
	return value;
}
void problem5() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc�� value ����� 28�� �ȴ�.
	cout << acc.get() << endl; // 28 ���
}
//6. Stack Ŭ������ ���弼��

class MyIntStack {
	int p[10];
	int tos; // ������ ����⸦ ����Ű�� �ε���
public:
	MyIntStack();
	int getTos() { return tos; }
	bool push(int n); // ���� n Ǫ��. �� �� ������ false, �ƴϸ� true ����
	bool pop(int& n); // ���Ͽ� n�� ����.������ ��� ������ false, �ƴϸ� true ����
};
MyIntStack::MyIntStack() { tos = 0; }
bool MyIntStack::push(int n) {
	if (tos > 9) { tos--;  return false; }
	p[tos] = n;
	if (tos <= 9) tos++;
	return true;
}
bool MyIntStack::pop(int& n) {
	if (tos < 0) return false;
	n = p[tos];
	if (tos >= 0) tos--;
	return true;
}
void problem6() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) { // 11���� Ǫ���Ѵ�.
		if (a.push(i)) cout << i << ' '; // Ǫ�õ� �� ����
		else cout << endl << i + 1 << " ��° stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) { // 11���� ���Ѵ�.
		if (a.pop(n)) cout << n << ' '; // �� �� �� ���
		else cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;
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
		else if (sel == 5) { problem5(); }
		else if (sel == 6) { problem6(); }
		cout << endl;
	}
	return 0;
}