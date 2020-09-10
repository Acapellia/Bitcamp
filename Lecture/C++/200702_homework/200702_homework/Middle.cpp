#include <iostream>
#include <ctime>
using namespace std;

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

//1. Random 클래스를 상속해서 짝수 정수만 랜덤하게 발생시키는 EvenRandom 클래스를 작성하고
//next()를 재정의하여
//10개의 짝수를 랜덤하게 출력하는 프로그램을 완성하세요.
//0도 짝수로 처리합니다.
class EvenRandom :Random {
protected:
	int n;
public:
	int next() {
		while (true) {
			n = rand();
			if (n % 2 == 0) return n;
		}
	}
};
void problem1() {
	EvenRandom er;
	for (int i = 0; i < 10; i++) {
		cout<<er.next()<<" ";
	}
	cout << endl;
}
//2. EvenRandom 클래스를 상속해 짝수, 홀수를 선택할 수 있는 생성자를 가진
//생성자를 가진 SelectableRandom 클래스를 작성하고
//next()를 재정의하여
//각각 짝수 10개, 홀수 10개를 랜덤하게 발생시키는 프로그램을 작성하세요.
class SelectableRandom :EvenRandom {
private:
	int sel;
public:
	SelectableRandom(int s) { sel = s; }
	int next() {
		while (true) {
			n = rand();
			if (sel == 1) {
				if (n % 2 == 0) return n;
			}
			else {
				if (n % 2 == 1) return n;
			}
		}
	}
};
void problem2() {
	SelectableRandom esr(1), osr(0);
	for (int i = 0; i < 10; i++) {
		cout << esr.next() << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << osr.next() << " ";
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
		cout << endl;
	}
	return 0;
}