#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<cstring>
#include<string>

using namespace std;
//1. 랜덤 수를 발생시키는 Random 클래스입니다.
//// 임의의 정수를 랜덤하게 제공하는 클래스
class Random {
public:
	Random(); // 생성자. 랜덤 seed를 설정한다.
	int next(); // 랜던 정수를 리턴한다.
	int nextInRange(int low, int high); // low와 high 사이의 랜덤 정수를 리턴한다.
};

Random::Random() {
	srand((unsigned)time(0)); // 임의의 seed를 설정하여 할 때마다 다른 랜덤 수가 나오게 한다.
}

int Random::next() {
	return rand(); // 0에서 RAND_MAX 사이의 랜덤한 정수 리턴
}

int Random::nextInRange(int low, int high) {
    int range=(high-low)+1;
    return low + (rand() % range); // low와 high 사이의 랜덤 정수를 리턴한다. 
}

void problem1() {
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}
//2. 1번을 참고해서 짝수 정수만 랜덤하게 발생시키는 EvenRandom 클래스를 작성하고
//10개의 짝수를 랜덤하게 출력하는 프로그램을 완성하세요.
//0도 짝수로 처리합니다.
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
//3. 짝수, 홀수를 선택할 수 있는 생성자를 가진 SelectableRandom 클래스를 작성하고
//각각 짝수 10개, 홀수 10개를 랜덤하게 발생시키는 프로그램을 작성하세요.
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
		if (sel == 0) { // 짝
			if (n % 2 != 0) n++;
		}
		else if (sel == 1) { // 홀
			if (n % 2 != 1) n++;
		}
		return n;
	}
};
void problem3() {
	SelectableRandom sre(0), sro(1); // even 0 odd 1
	cout << "짝수" << endl;
	for (int i = 0; i < 10; i++) {
		cout << sre.next() << " ";
	}
	cout << endl;

	cout << "홀수" << endl;
	for (int i = 0; i < 10; i++) {
		cout << sro.next() << " ";
	}
	cout << endl;
}

//4. int타입의 정수를 객체화한 Integer 클래스를 작성하세요.
//Integer 클래스를 활용하는 코드는 다음과 같습니다.
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
	cout << n.get() << ' ';		// 30출력
	n.set(50);
	cout << n.get() << ' ';		// 50출력
	cout << endl;

	Integer m("300");
	cout << m.get() << ' ';		// 300출력
	cout << m.isEven();			// true(정수로 1) 출력
	cout << endl;

	Integer m2("277");
	cout << m2.get() << ' ';
	cout << m2.isEven();
}
//5. Accumulator 클래스를 구현하세요.

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
	acc.add(5).add(6).add(7); // acc의 value 멤버가 28이 된다.
	cout << acc.get() << endl; // 28 출력
}
//6. Stack 클래스를 만드세요

class MyIntStack {
	int p[10];
	int tos; // 스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack();
	int getTos() { return tos; }
	bool push(int n); // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int& n); // 팝하여 n에 저장.스택이 비어 있으면 false, 아니면 true 리턴
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
	for (int i = 0; i < 11; i++) { // 11개를 푸시한다.
		if (a.push(i)) cout << i << ' '; // 푸시된 값 에코
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) { // 11개를 팝한다.
		if (a.pop(n)) cout << n << ' '; // 팝 한 값 출력
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
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
		else if (sel == 5) { problem5(); }
		else if (sel == 6) { problem6(); }
		cout << endl;
	}
	return 0;
}