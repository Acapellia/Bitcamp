#include<iostream>
#include "06_struct01.h"
#include "06_struct02.h"

using namespace std;

int main()
{
	Score::Student st = { "ȫ�浿",90, 88, 100 };
	cout << "�̸� : " << st.name << endl;
	cout << "kor : " << st.kor << endl;
	cout << "math : " << st.math << endl;
	cout << "eng : " << st.eng << endl;

	cout << endl;

	Personal::Student st1 = { "ȫ�浿","������",24,175.0f,72.5f };
	cout << "�̸� : " << st1.name << endl;
	cout << "�ּ� : " << st1.address << endl;
	cout << "����" << st1.age << endl;
	return 0;
}
