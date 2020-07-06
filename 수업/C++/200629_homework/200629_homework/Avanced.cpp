#include<iostream>
#include <cstdlib>
#include <string> 
#include<cstring>
using namespace std;
//1. string을 이용하여 영문 한줄 입력받고 거꾸로 출력할 것
//Reversestring
void problem1() {
	string str;
	cout << "문자열을 입력하세요 : ";
	cin >> str;
	for (int i = str.length()-1; i >= 0; i--)
		cout << str[i];
}
//2. Histogram 클래스 만들것

//#include <iostream>
//#include <string>
//using namespace std;

//int main() {
//	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, \n");
//	elvisHisto.put("falling in love with you");
//	elvisHisto.putc('-');
//	elvisHisto.put("Elvis Presley");
//	elvisHisto.print();
//}
class Histogram {
private:
	string str;
	int cnt = 0;
public:
	Histogram() {}
	Histogram(string _str) {
		str = _str;
	}
	void put(string _str) {
		str += _str;
	}
	void putc(char c) {
		str += c;
	}
	void print() {
		cout << str << endl;
	}
	void showHistogram() {
		int alpha[27] = {0};
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'A' && str[i]<='Z') str[i] = str[i] + ('a' - 'A');
			if (str[i] >= 'a' && str[i] <= 'z') {
				int idx = (str[i] - 'a')+1 ;
				alpha[idx]++;
				cnt++;
			}
		}
		cout << "\n알파벳 수 : " << cnt << endl<<endl;
		for (int i = 1; i <= 26; i++) {
			cout << (char)('a' + (i - 1)) <<" ("<< alpha[i] << ")     :  ";
			for (int j = 0; j < alpha[i]; j++) {
				cout << "*";
			}
			cout << endl;
		}
	}
};
void problem2() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, \n");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
	elvisHisto.showHistogram();
}
//3.TelInfo의 클래스내의 이름과 전화번호를 동적할당하시오.
//동적할당할 때 생성자와 소멸자를 이용할 것.
//
//void problem3() {}
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