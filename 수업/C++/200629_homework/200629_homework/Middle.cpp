#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<cstring>
using namespace std;
//1. cout << �����ڸ� �̿��ؼ� �������� ����ϼ���
//2 x 1 = 2  3 x 1 = 3 ..... 9 x 1 = 9
//......
//2 x 9 = 18
void problem1() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 2; j <= 9; j++) {
			cout << j << " * " << i << " = " << j * i << " ";
		}cout << endl;
	}
}
//2. Ű����κ��� 2���� ������ �о ū ���� ����ϼ���
void problem2() {
	int num1, num2;
	cout << "2���� ������ �Է��ϼ��� : ";
	cin >> num1 >> num2;
	cout << (num1 > num2 ? num1 : num2);
}
//3. �Ҽ����� ������ 5���� �Ǽ��� �Է¹޾� ���� ū ���� ����ϼ���
void problem3() {
	double max = 0.0;
	cout << "5���� �Ǽ��� �Է��ϼ���"<<endl;
	for (int i = 1; i <= 5; i++) {
		cout << i << "��° �Ǽ��� �Է��ϼ��� : ";
		double num; cin >> num;
		if (i == 1) max = num;
		max < num ? (max = num) : (max = max);
	}
	cout << "max : " << max<<endl;

}
//4. < Enter > Ű�� �Էµ� ������ ���ڵ��� �а�, �Էµ� ���� 'x'��
//������ ȭ�鿡 ����ϼ���.
void problem4() {
	getchar();
	int cnt = 0;
	cout << "���ڿ��� �Է��ϼ���:";
	while (true) {
		char x;
		cin.get(x);
		if (x == '\n') { cout << "cnt : " << cnt; break; }
		cnt++;
	}
}
//5. "yes"�� �Էµ� ������ �������� �ʴ� ���α׷��� �ۼ��ؼ���.�Է��� cin.getline() �Լ��� ����ϼ���
// �̻���
void problem5() {
	getchar();
	for(int i=0;i<3;i++) {
		char x[10];
		cout << "���ڿ��� �Է��ϼ��� : ";
		//getchar();
		cin.getline(x, 10,'\n');
		if (!strcmp(x, "yes")) { cout << "����" << endl; break; }
		//cout << "string : " << x<<endl;
	}
}
//6. ';'���� 5���� �̸��� �����ؼ� �Է¹޾�, �� �̸��� ����� ȭ�鿡 ����ϼ���.
//�׸��� ���� �� �̸��� �Ǻ��ؼ� ��Ÿ������.
//cin.getline(str, 100, ';');
//ȫ�浿; �Ӳ���; ����; ������; ��¥��Ʈ;
//1:ȫ�浿
//2 : �Ӳ���
//3 : ����
//4 : ������
//5 : ��¥��Ʈ
void problem6() {
	getchar();
	int len=0;
	char maxStr[100];
	cout << ";�� ������ �ϴ� ���ڿ����� �Է��ϼ��� : ";
	for (int i = 0; i < 5; i++) {
		char str[100] = { 0 };
		cin.getline(str, 100, ';');
		if (len < strlen(str)) { len = strlen(str); strcpy(maxStr, str); }
		cout << i+1 << " : "  << str << endl;
	}
	cout << endl;
	cout << "string : " << maxStr << endl;
	cout << "len : " << len << endl;
}
//7. �̸�, �ּ�, ���̸� �Է¹޾� ����ϼ���.
void problem7() {
	char name[20], addr[20];
	int age;
	cout << "�̸� : ";  cin >> name; 
	cout << "�ּ� : ";  cin >> addr; 
	cout << "���� : ";  cin >> age; 
	cout << name << endl;
	cout << addr << endl;
	cout << age << endl;

}
//8. ���ڿ��� �ϳ� �Է¹ް� ���ڿ��� �κ� ���ڿ��� ����ϼ���
//hello
//h
//he
//hel
//hell
//hello
void problem8() {
	char str[20];
	cout << "���ڿ��� �Է��ϼ��� : ";
	cin >> str;
	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j <= i; j++) {
			cout << str[j];
		}cout << endl;
	}
}
int main()
{
	while (1) {
		int sel;
		cout << "���ϴ� ������ �Է��ϼ��� : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		else if (sel == 2) { problem2(); }
		else if (sel == 3) { problem3(); }
		else if (sel == 4) { problem4(); }
		else if (sel == 5) { problem5(); }
		else if (sel == 6) { problem6(); }
		else if (sel == 7) { problem7(); }
		else if (sel == 8) { problem8(); }
		cout << endl;
	}
	return 0;
}