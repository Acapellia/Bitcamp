#include<stdio.h>
//1. 3���� �л��� �̸��� ���������� �Է¹ް�
//������ ���
//�� �л� �̸��� ������ ����ϼ���
//�̸��� �������� ��� �迭�� ����ϼ���
#define SIZE 3
int main()
{
	char name[SIZE][20] = { 0 };
	int kor[SIZE] = { 0 };
	int sum = 0;
	double avg = 0.0;
	for (int i = 0; i < SIZE; i++) {
		printf("�л� %d�� �̸��� ������� �Է��ϼ��� : ",i+1);
		scanf("%s %d", name[i], &kor[i]);
		sum += kor[i];
	}
	avg = (double)sum / SIZE;
	for (int i = 0; i < SIZE; i++) {
		printf("�л��̸� : %s ����� : %d\n", name[i], kor[i]);
	}
	printf("�л� ���� : %d\n", sum);
	printf("�л� ��� : %.2lf\n", avg);
}