#include<iostream>
#include "06_struct01.h"
#include "06_struct02.h"

using namespace std;

int main()
{
	Score::Student st = { "홍길동",90, 88, 100 };
	cout << "이름 : " << st.name << endl;
	cout << "kor : " << st.kor << endl;
	cout << "math : " << st.math << endl;
	cout << "eng : " << st.eng << endl;

	cout << endl;

	Personal::Student st1 = { "홍길동","지리산",24,175.0f,72.5f };
	cout << "이름 : " << st1.name << endl;
	cout << "주소 : " << st1.address << endl;
	cout << "나이" << st1.age << endl;
	return 0;
}
