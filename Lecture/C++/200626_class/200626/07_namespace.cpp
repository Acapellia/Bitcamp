#include<iostream>
#include "07_struct01.h"
#include "07_struct02.h"
#include "07_namespace.h"
using namespace std;
int main()
{
	A::Score::Student st = { "ȫ�浿",90, 88, 100 };
	cout << "�̸� : " << st.name << endl;
	cout << "kor : " << st.kor << endl;
	cout << "math : " << st.math << endl;
	cout << "eng : " << st.eng << endl;

	cout << endl<<endl;

	B::Personal::Student st1 = { "ȫ�浿","������",24,175.0f,72.5f };
	cout << "�̸� : " << st1.name << endl;
	cout << "�ּ� : " << st1.address << endl;
	cout << "����" << st1.age << endl;

	cout << endl << endl;

	cout << A::name << endl;
	cout << A::job << endl;
	cout << B::name << endl;
	cout << B::job << endl;
	return 0;
}
