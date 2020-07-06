#include<iostream>
#include<cstdio>
using namespace std;
#define NAME_LEN 30
class Bitcamp {
private:
	char name[NAME_LEN];
	int stuCnt = 0;
public:
	static int bitCnt;
	Bitcamp() {}
	Bitcamp(const char* _name, int _cnt) {
		strcpy(name, _name);
		stuCnt = _cnt;
		bitCnt += _cnt;
	}
	void showInfo() {
		cout << "지점명 : " << name << " 학생수 : " << stuCnt << endl;
	}
	int getCnt() { return stuCnt; }
	static void showAllCnt();
};

// static 멤버변수의 초기화 방법
int Bitcamp::bitCnt = 0;
void Bitcamp:: showAllCnt() {
	cout << "Bitcamp 총 학생수 : " << bitCnt << endl;
}
void main()
{
	Bitcamp bitSeocho("비트캠프 본원", 300);
	Bitcamp bitGangnam("비트캠프 강남", 120);
	Bitcamp bitJongro("비트캠프 종로", 200);
	Bitcamp bitSinchon("비트캠프 신촌", 150);
	Bitcamp bitSeomyun("비트캠프 서면", 22);

	bitSeocho.showInfo();
	bitGangnam.showInfo();
	bitJongro.showInfo();
	bitSinchon.showInfo();
	bitSeomyun.showInfo();
	
	Bitcamp::showAllCnt();
}