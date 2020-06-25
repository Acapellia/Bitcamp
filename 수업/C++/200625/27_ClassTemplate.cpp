// "public: void __thiscall template명 ~~~~~ 외부 기호(참조 위치: _main 함수)에서 확인하지 못했습니다. main.obj
// template는 헤더와 소스파일의 분리를 허락하지 않는다.
// 1) #include<~~.h> 대신 #include<~~.cpp> (cpp에는 해당 h를 include 해야함) 를 사용한다
// 2) 헤더와 소스파일을 합친다.
#include<iostream>
#include "PosList.h"
#define DEFAULT_POSLEN 24

using namespace std;

int main()
{
	double pos = 0;
	PosList<double> p1(DEFAULT_POSLEN);
	for (int i = 0; i < DEFAULT_POSLEN; i++) {
		if (!p1.SetPos(i, (pos=pos+i) *2.25)) {
			cout << "SetPos Error : [" << i << "," << pos*2.25 << "]" << endl;
		}
	}
	for (int i = 0; i < DEFAULT_POSLEN; i++) {
		if (p1.GetPos(i, pos)) {
			cout << "Pos : [" << i << "," << pos << "]" << endl;
		}
		else {
			cout << "GetPos Error : [" << i  << "]" << endl;
		}
	}
	return 0;
}