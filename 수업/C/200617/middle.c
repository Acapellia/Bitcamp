#include<stdio.h>
//1. 10�� ���� �Է� �� �ִ� �ּ� ���� ����� ���ϴ� �Լ��� ����ϴ�.
//�� �ִ�, �ּ�, ����, ��� �Ű������� ������ ������ �����ؼ�
//����� ���� ������ ������ ���� ���� �޵��� �մϴ�.
void calc(int* num,int len, int* max, int* min, int*sum, double* avg) {
	*max = 0;
	*min = 9999999;
	*sum = 0;
	for (int i = 0; i < len; i++) {
		if (num[i] > *max) *max = num[i];
		if (num[i] < *min) *min = num[i];
		*sum += num[i];
	}
	*avg = (double)*sum / len;
}
void problem1() {
	int num[10];
	int max, min, sum;
	double avg;
	printf("10���� ������ �Է��ϼ��� : "); 
	for(int i=0;i<10;i++)
		scanf("%d", &num[i]);
	calc(num,10,&max,&min,&sum,&avg);
	printf("max : %d min : %d sum : %d avg : %.2lf\n", max,min,sum,avg);
}
//2.�ҹ��ڸ� �빮�ڷ�, �빮�ڸ� �ҹ��ڷ�,
//�׿� ���ڴ� �״�� ����ϼ���.(��ȯ�ϴ� �Լ��� �����)
//����� ���� ������ ������ ���� ���� �޵��� �մϴ�.
void changeChar(char* c) {
	if ('A' <= *c && *c <= 'Z') { *c = *c + 32; }
	else if ('a' <= *c && *c <= 'z') { *c = *c - 32; }
}
void problem2() {
	while (1) {
		printf("���ڸ� �Է��ϼ��� : ");
		char c; scanf(" %c", &c);
		changeChar(&c);
		printf("��ȯ�� ���ڴ� %c �Դϴ�\n",c);
	}
}
//3. ����ڷκ��� �ʸ� �Է¹��� �� �̸�[��, ��, ��]��
//���·� ����ϴ� ���α׷��� �ۼ��ϼ���.
//1) �Է� �Լ�
//2) �ð� ���(����� ���� ������ ������ ���� ���� �޵��� �մϴ�)
//3) ��� �Լ�
int inputTime() {
	int sec;
	printf("�ʸ� �Է��ϼ��� : "); scanf("%d", &sec);
	return sec;
}
void calcTime(int *hour, int *min, int* sec) {
	*hour = *sec / 3600; *sec = *sec % 3600;
	*min = *sec / 60; *sec = *sec % 60;
}
void printTime(int hour, int min, int sec) {
	printf("%d�� %d�� %d��\n", hour, min, sec);
}
void problem3() {
	int hour, min, sec = inputTime();
	calcTime(&hour, &min, &sec);
	printTime(hour, min, sec);
}
//4. ����ڷκ��� ��, ��, �ʸ� �Է¹��� �� �ʷ� ��ȯ�ϴ� �Լ���
//�� ���� �ʸ� ����ϴ� �Լ��� ����� ����ϼ���
//1) ��, ��, �� �Է�
//2) ��� �Լ�(����� ���� ������ ������ ���� ���� �޵��� �մϴ�)
//3) �� ��� �Լ�
void inputTime2(int *hour, int* min, int* sec) {
	printf("�� �� �ʸ� �Է��ϼ��� : "); scanf("%d %d %d",hour, min, sec);
}
void calcTime2(int hour, int min, int* sec) {
	printf("%d�� %d�� %d��\n", hour, min, *sec);
	*sec = *sec + hour * 3600 + min * 60;
}
void printTime2(int sec) {
	printf("%d��\n", sec);
}
void problem4() {
	int hour, min, sec;
	inputTime2(&hour,&min,&sec);
	calcTime2(hour, min, &sec);
	printTime2(sec);
}
//5. Ű�� �����Ը� �Է��ϴ� �Լ��� ����� ����غ�����
//����� ���� ������ ������ ���� ���� �޵��� �մϴ�
void inputBody(double* h, double* w) {
	printf("Ű�� �����Ը� �Է��ϼ��� : ");
	scanf("%lf %lf", h, w);
}
void problem5() {
	double height, weight;
	inputBody(&height,&weight);
	printf("Ű : %.1lfcm  ������ : %.1lfkg\n",height,weight);
}
//6. �ݵ�� A�� �̿��ؼ� B�� ���� ä�쵵�� �ϼ���
// �迭 A, B�� ����
//int A[2][4] = { 1,2,3,4,5,6,7,8 };
//int B[4][2] = { 0 };
//
//A                B
//1 2 3 4          1 2
//5 6 7 8          3 4
//				   5 6
// 				   7 8
void moveArray(int* A, int B[4][2]) {
	int p=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			B[i][j] = *(A + p++);
		}
	}
}

void problem6() {
	int A[2][4] = { 1,2,3,4,5,6,7,8 };
	int B[4][2] = { 0 };
	moveArray(A,B);
	
	// basic6
	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			B[i][j] = A[j][i];
		}
	}*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", B[i][j]);
		}printf("\n");
	}
}
void main()
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
		else if (select == 6) problem6();
		printf("\n");
	}
}