// "public: void __thiscall template�� ~~~~~ �ܺ� ��ȣ(���� ��ġ: _main �Լ�)���� Ȯ������ ���߽��ϴ�. main.obj
// template�� ����� �ҽ������� �и��� ������� �ʴ´�.
// #include<~~.h> ��� #include<~~.cpp> (cpp���� �ش� h�� include �ؾ���) �� ����Ѵ�
#include<iostream>
#include "27_PosList.cpp"
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