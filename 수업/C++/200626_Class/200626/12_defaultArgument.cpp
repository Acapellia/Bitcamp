#include<iostream>
using namespace std;
void showInfo(const char* name, const char* phone, const char* nation="���ѹα�", int exPhoneNum=82) {
	cout << "���� : " << nation << endl;
	cout << "�̸� : " << name << endl;
	cout << "���� : " << exPhoneNum << endl;
	cout << "��ȭ : " << phone << endl;
	cout << "------------------------" << endl;
}
void main()
{
	showInfo( "ȫ�浿", "010-1111-2222", "���ѹα�", 82);
	showInfo("�̻��", "010-7777-9999");
	showInfo("�׻��", "010-1234-5678","���ѹα�");
	showInfo("�����", "010-8457-1629", "����", 99);
}