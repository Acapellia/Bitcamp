// freind keywork
// keyword가 붙은 변수, 클래스, 함수등은 본인의 friend이므로 private 정보를 알려줘도 된다는 표시
// 무분별하게 사용금지 (정보 은닉, 캡슐화)의 기능이 무의미해짐
#include<iostream>
#include "Position.h"
using namespace std;
int main()
{
	Position pos(10, 10), pos2(20, 20), pos3;
	pos3 = 2 * pos;
	pos3.ShowPosition();
	return 0;
}