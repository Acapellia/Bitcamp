#include<stdio.h>
//1. ���� ���� �Է¹ް� �� ����ŭ 3�� ��� ����ϼ���
//���� ��� 5�� �Է¹����� 3 6 9 12 15�� ����ϸ� �˴ϴ�
void problem1() {
	printf("���� ������ �Է��ϼ��� : ");
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("%d ", i * 3);
	}printf("\n");
}
//2. ����ڷκ��� ������ �Է¹޽��ϴ�.
//�Է� ���� ���� ��� ���մϴ�
//����ڰ� 0�� �Է��ϸ� ���� ����մϴ�
//�׸��� ���α׷��� �����մϴ�.
void problem2() {
	int sum = 0;
	while (1) {
		printf("������ �Է��ϼ��� : ");
		int n; scanf("%d", &n);
		if (n == 0) { printf("sum : %d\n", sum);  break; }
		sum += n;
	}
	
}
//3. 5�� �Է��ϸ�
//*
//**
//***
//****
//*****
//�̷��� ����ϼ���.
void problem3() {
	printf("������ �Է��ϼ��� : ");
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}printf("\n");
	}

}
//4. 5�� �Է��ϸ�
//*****
//****
//***
//**
//*
//�̷��� �������� ����ϼ���.
void problem4() {
	printf("������ �Է��ϼ��� : ");
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			printf("*");
		}printf("\n");
	}
}
//5. 3���� ������� �Է¹ް� ���հ� ����� ����ϼ���
//�Լ��� ���� ����ϼ���
//�Լ� �̸� : inputKor, calcTotal, calcAvg
int inputKor() {
	int kor=0;
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d", &kor);
	return kor;
}
int calcTotal(int a, int b, int c) {
	return a+b+c;
}
double calcAvg(int total) {
	return total / 3;
}
void problem5() {
	int total = 0;
	double avg = 0;
	int kor[3];
	for (int i = 0; i < 3; i++) {
		kor[i] = inputKor();
	}
	total = calcTotal(kor[0],kor[1],kor[2]);
	avg = calcAvg(total);
	printf("total : %d avg : %.2lf\n", total, avg);
}
/*void main()
{
	int select;
	while (1) {
		printf("���� : ");
		scanf_s("%d", &select);
		if (select == 0) break;
		else if (select == 1) problem1();
		else if (select == 2) problem2();
		else if (select == 3) problem3();
		else if (select == 4) problem4();
		else if (select == 5) problem5();
	}
}*/