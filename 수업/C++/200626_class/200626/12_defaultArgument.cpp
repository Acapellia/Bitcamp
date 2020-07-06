#include<iostream>
using namespace std;
void showInfo(const char* name, const char* phone, const char* nation="대한민국", int exPhoneNum=82) {
	cout << "국적 : " << nation << endl;
	cout << "이름 : " << name << endl;
	cout << "국번 : " << exPhoneNum << endl;
	cout << "전화 : " << phone << endl;
	cout << "------------------------" << endl;
}
void main()
{
	showInfo( "홍길동", "010-1111-2222", "대한민국", 82);
	showInfo("이사람", "010-7777-9999");
	showInfo("그사람", "010-1234-5678","대한민국");
	showInfo("저사람", "010-8457-1629", "지구", 99);
}