#include <iostream>
#include <ctime>
using namespace std;

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

//1. Random Ŭ������ ����ؼ� ¦�� ������ �����ϰ� �߻���Ű�� EvenRandom Ŭ������ �ۼ��ϰ�
//next()�� �������Ͽ�
//10���� ¦���� �����ϰ� ����ϴ� ���α׷��� �ϼ��ϼ���.
//0�� ¦���� ó���մϴ�.
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
//2. EvenRandom Ŭ������ ����� ¦��, Ȧ���� ������ �� �ִ� �����ڸ� ����
//�����ڸ� ���� SelectableRandom Ŭ������ �ۼ��ϰ�
//next()�� �������Ͽ�
//���� ¦�� 10��, Ȧ�� 10���� �����ϰ� �߻���Ű�� ���α׷��� �ۼ��ϼ���.
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
		cout << "���ϴ� ������ �Է��ϼ��� : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		else if (sel == 2) { problem2(); }
		cout << endl;
	}
	return 0;
}