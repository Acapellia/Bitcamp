#include<iostream>
using namespace std;
// char* str = "��Ʈ��" ������ ���� " "�� �ʱ�ȭ �Ҷ�
// "const char *" ������ ���� ����Ͽ� "char *" ������ ����Ƽ�� �ʱ�ȭ�� �� �����ϴ�.
// 1) ������Ʈ �Ӽ� -> c/c++ -> ��� -> �ؼ���� -> �ƴϿ�
// 2) const char* str = "��Ʈ��" �� ���� ����

int main()
{
	const char* temp = "����";
	// const�� ������ ���� ���� ���ȭ �Ѵ�.
	// const char* dest -> char �� ���� �Ұ�.
	// char* const dest - > dest �ּ� ���� �Ұ�.
	const char* dest;
	dest = temp;
	printf("%s", dest);
	return 0;
}