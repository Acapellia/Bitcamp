#include<iostream>
#include<set>
using namespace std;

void main() {
	set<string> s;

	s.insert("�ٳ���");
	s.insert("���");
	s.insert("����");
	s.insert("��ǻ��");
	s.insert("ġŲ");
	while (true) {
		string temp;
		cout << "ã�� ���� ��ǰ�� �Է� : ";
		cin >> temp;

		set<string>::iterator it = s.find(temp);
		if (it != s.end()) {
			cout << temp << "�� �ִ�." << endl;;
		}
		else {
			cout << temp << "�� ����." << endl;
		}
	}
}