// freind keywork
// keyword�� ���� ����, Ŭ����, �Լ����� ������ friend�̹Ƿ� private ������ �˷��൵ �ȴٴ� ǥ��
// ���к��ϰ� ������ (���� ����, ĸ��ȭ)�� ����� ���ǹ�����
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