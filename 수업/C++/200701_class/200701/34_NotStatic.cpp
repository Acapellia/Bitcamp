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
		cout << "������ : " << name << " �л��� : " << stuCnt << endl;
	}
	int getCnt() { return stuCnt; }
	void showAllCnt() {
		cout << "Bitcamp �� �л��� : " << bitCnt << endl;
	}
};
int Bitcamp::bitCnt = 0;
void main()
{
	Bitcamp bitSeocho("��Ʈķ�� ����",300);
	Bitcamp bitGangnam("��Ʈķ�� ����", 120);
	Bitcamp bitJongro("��Ʈķ�� ����", 200);
	Bitcamp bitSinchon("��Ʈķ�� ����", 150);
	Bitcamp bitSeomyun("��Ʈķ�� ����", 22);
	bitSeocho.showInfo();
	bitGangnam.showInfo();
	bitJongro.showInfo();
	bitSinchon.showInfo();
	bitSeomyun.showInfo();
	cout << "�� �л��� : " << bitSeocho.getCnt() + bitGangnam.getCnt() + bitJongro.getCnt() + 
		bitSinchon.getCnt() + bitSeomyun.getCnt() << endl;
}