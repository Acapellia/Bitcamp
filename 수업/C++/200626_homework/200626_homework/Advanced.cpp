#include<iostream>
#include<cstring>
using namespace std;
//1. strcmp, strncmp, ���� ���� �ϳ��ϳ� ���ؼ� �˻��ϴ� �Լ�����
//���ڿ� 2�� �Է¹ް� ���ڿ��� ������ �ٸ��� �˻��ϴ� ���α׷� �ۼ��ϼ���.
int str_cmp(char str1[], char str2[]) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2) return 0;
	int len = len1 > len2 ? len1 : len2; // ���ٴ°��� ����ǹǷ� �ƹ��ų� �������
	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i]) return 0;
	}
	return 1;
}
void problem1() {
	char str1[20],str2[20];
	cout << "���ڿ� 2���� �Է��ϼ��� : ";
	cin >> str1 >> str2;
	if (str_cmp(str1, str2)) { cout << "2���� ���ڿ��� �����ϴ�." << endl; }
	else { cout << "2���� ���ڿ��� �ٸ��ϴ�." << endl; }
}
//cin, cout ����� ��

//2. ����ڷκ��� ��� ������ �Է¹޴´�.
//- 1�� �Ǹ� ����Ѵ�.
//default�� 5���� �����Ҵ��ϰ�
//5���� �Ѿ�� + 5�� �����Ҵ��� ������Ų��.
//5 -> 10 -> 15
//�ݵ�� new �����ڸ� ����� ��
#define SIZE 5
void problem2() {
	int* num = new int[SIZE]();
	int idx = 0;
	int size = SIZE;
	int tNum;
	while (true) {
		cout << "������ �Է��ϼ��� : ";
		cin >> tNum;
		if (tNum == -1) break;
		num[idx++] = tNum;
		if (idx >= size) {
			size += SIZE;
			int* temp = new int[size]();
			cout << "size�� " << size << "�� �þ���ϴ�." << endl;
			for (int i = 0; i < size - SIZE; i++) {
				temp[i] = num[i];
			}
			delete[] num;
			num = temp;
		}
	}
	for (int i = 0; i < idx; i++)
		cout << num[i] << " ";
	cout << endl;
	delete[] num;
}
//3. TelInfo�� new delete�� ����Ͽ� ������ ��
//void problem3() {}
//4. 3�������� ����ü���� Ŭ������ ��ȯ�� ��
//void problem4() {}
int main()
{
	while (1) {
		int sel;
		cout << "���ϴ� ������ �Է��ϼ��� : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		else if (sel == 2) { problem2(); }

		cout << endl;
	}
	return 0;
}