#include<iostream>
#include<cstring>
using namespace std;
//1. 1 ~100���� ���� ����� ����ϼ���.
//cout�� ����ϼ���.
void problem1() {
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		sum += i;
	}
	cout << "sum : " << sum << endl;
}
//2. 1 ~100���� ���ٿ� 10���� ����ϼ���.
//������ ������ ������ �� ��
void problem2() {
	for (int i = 1; i <= 100; i++) {
		cout << i << "	";
		if (i % 10 == 0) cout << endl;
	}
}
//3. C�� C++�� cout, cin�� ����Ͽ� �ٲټ���
//
//#include <stdio.h>
//int main() { // ������ �־��� �ڵ�
//	int k, n = 0;
//	int sum = 0;
//	printf("�� ���� �Է��ϼ���>>");
//	scanf("%d", &n);
//	for (k = 1; k <= n; k++) {
//		sum += k;
//	}
//	printf("1���� %d������ ���� %d �Դϴ�.\n", n, sum);
//	return 0;
//}
int problem3() {
	int k, n = 0;
	int sum = 0;
	cout << "�� ���� �Է��ϼ���>>";
	cin>>n;
	for (k = 1; k <= n; k++) {
		sum += k;
	}
	cout<<"1���� " << n << "������ ���� " << sum << " �Դϴ�."<< endl;
	return 0;
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
		cout << endl;
	}
	return 0;
}