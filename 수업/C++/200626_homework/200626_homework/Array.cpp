#include<iostream>
#include<cstring>
#include<string>
using namespace std;
//1. ���̰� 5�� int�� �迭�� �����ؼ� 5���� ������ �Է¹޽��ϴ�.
//���� �ִ밪, �ּҰ�, ����, ����� ���ϼ���.
void problem1(){
	int arr[5] = { 0 };
	int max = 0, min = 9999999, sum = 0;
	double avg = 0.0;
	for (int i = 0; i < 5; i++) {
		cout << "������ �Է��ϼ��� : ";
		cin >> arr[i];
		sum += arr[i];
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}
	avg = double(sum) / 5;
	cout << "�ִ밪 : " << max << endl;
	cout << "�ּҰ� : " << min << endl;
	cout << "���� : " << sum << endl;
	cout << "��� : " << avg << endl;
}
//2. char�� 1�����迭�� ���� �� "Good Morning"�� �ʱ�ȭ �ϼ���.
//�׸��� ������ ����ϼ���.
void problem2() {
	char str[] = "Good Morning";
	cout << "string : " << str << endl;
}
//3. ���ܾ �Է¹ް� ���ܾ �������� ����������.
//��, �ΰ��� �״�ο��� �մϴ�.
//�������� ��ȯ�� ���� ����ϼ���.
void problem3() {
	char str[20] = { 0 }, rvs[20] = {0};
	cout << "���ܾ �Է����ּ��� : ";
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		rvs[len-i-1] = str[i];
	}
	cout << "�������� ���ܾ�� : "<< rvs << endl;
}
//4. ���̰� 5�� int�� �迭 arr�� �����ϰ�
//1, 2, 3, 4, 5�� �ʱ�ȭ�Ѵ�.
//������ ��Ҹ� ����Ű�� ptr�� �����ϰ�
//ptr�� �����ϴ� �������� �迭�� ��Ҹ� ��� ���Ͽ� �����
//����Ѵ�.
void problem4() {
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = &arr[4];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += (*ptr--);
	}
	cout << "sum : " << sum << endl;
}
//5. ���̰� 6�� �迭 arr 1, 2, 3, 4, 5, 6 ���� �ʱ�ȭ�� ����
//�迭�� ����� ���� ������ 6, 5, 4, 3, 2, 1�� �����Ѵ�.
//�迭�� �հ� �ڸ� ����Ű�� ������ ���� 2���� �����ؼ�
//�̸� Ȱ���Ͽ� ����� ���� ������ �ٲ�� �Ѵ�.
void problem5() {
	int arr[6] = { 1,2,3,4,5,6 };
	int* ptr1 = arr;
	int* ptr2 = &arr[5];
	for (int i = 0; i < 3; i++) {
		int temp = (*ptr1);
		*ptr1 = *ptr2;
		*ptr2 = temp;
		*ptr1++; *ptr2--;
	}
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
//6. ���ڸ� ������ ���ڿ��� �Է¹޾Ƽ� �� �ȿ� �����ϴ� ������ ������
//���ϼ���.
//���� ��� q1df3kf9lj3�� ����
//1 + 3 + 9 + 3�� ����ؾ� �մϴ�.
void problem6() {
	char str[20] = { 0 };
	int num[20] = { 0 };
	int idx = 0,sum=0;
	cout << "���ڸ� ������ ���ڿ��� �Է��ϼ��� : ";
	cin >> str;
	for (int i = 0; i < strlen(str); i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			num[idx++] = str[i] - '0';
			sum += (str[i] - '0');
		}
	}
	for (int i = 0; i < idx; i++) {
		cout << num[i];
		if (i < idx-1) cout << " + ";
	}
	cout << " = " << sum << endl;
}
//7. 20byte char �迭 3���� ����ϴ�.
//�迭�� ���ڿ��� �ΰ��� �Է¹޽��ϴ�.
//�������迭�� �ΰ��� ���ڿ��� �����Ͽ� �ٿ��ֽ��ϴ�.
//�� korea, student�� �Է¹޾Ҵٸ�
//����° �迭���� koreastudent�� ����Ǿ� ����Ͽ��� �մϴ�.
void problem7() {
	char str1[20] = {0}, str2[20] = { 0 }, str3[20] = { 0 };
	int idx = 0;
	cout << "���ڿ�1�� �Է��ϼ��� : ";
	cin >> str1;
	cout << "���ڿ�2�� �Է��ϼ��� : ";
	cin >> str2;
	for (int i = 0; i < strlen(str1); i++) {
		str3[idx++] = str1[i];
	}
	for (int i = 0; i < strlen(str2); i++) {
		str3[idx++] = str2[i];
	}
	cout << str3 << endl;
}
//8. ����ڷκ��� �̸��� ���̸� ������ ���Ŀ� ���缭 �ϳ��� ���ڿ���
//�Է¹޽��ϴ�.
//ȫ�浿 32
//�Ӳ��� 17
//�׷��� �̸��� ���� ���̿��� ������ ���ԵǾ�� �մϴ�.
//�̸��� ���̰� ������ �ٸ��� �Ǵ��Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
void problem8() {
	char str1[30] = { 0 }, str2[30] = { 0 };
	getchar();
	cout << "1��° ��� : ";	cin.getline(str1, 30);
	cout << "2��° ��� : ";	cin.getline(str2, 30);
	cout << "------------------------------" << endl;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int same[2] = { 0 }, idx = 0;

	cout << "----------<��>----------" << endl;
	for (int i = 0,j=0; i < len1 && j <len2;) {
		cout << "str1 : " << str1[i] << " " << "str2 : " << str2[j] << endl;
		if (str1[i] != ' ') { i++; }
		if (str2[j] != ' ') { j++; }
		if (str1[i] == ' ' && str2[j] == ' ') { idx++; i++; j++; }
		if (str1[i] != str2[j]) { same[idx] = 1; }
	}
	cout << "--------------------------" << endl;
	cout << "----------<���>----------" << endl;
	if(same[0] == 0 && same[1] == 0) cout << "�̸��� ���̰� �����ϴ�" << endl;
	else if (same[0] == 0) cout << "�̸��� �����ϴ�" << endl;
	else if (same[1] == 0) cout << "���̰� �����ϴ�" << endl;
	else { cout << "�̸��� ���̰� ��� �ٸ��ϴ�" << endl; }
	cout << "--------------------------" << endl;
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