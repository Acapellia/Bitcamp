#include<stdio.h>
//1. 2���� ������ �Է¹ް� ū ���� ��ȯ�ϴ� �Լ���
//���� ���� ��ȯ�ϴ� �Լ��� �ۼ��ϰ� ����ϼ���
int findMax(int x, int y) { return x > y ? x : y; }
int findMin(int x, int y) { return x < y ? x : y; }
void problem1() {
	printf("2���� ������ �Է��ϼ��� : ");
	int x, y; scanf("%d %d", &x, &y);
	int max = findMax(x, y);
	int min = findMin(x, y);
	printf("max : %d   min : %d\n", max, min);
}
//2. 3���� ������ �Է¹ް� ū ���� ��ȯ�ϴ� �Լ���
//���� ���� ��ȯ�ϴ� �Լ��� �ۼ��ϰ� ����ϼ���
int find3Max(int x, int y, int z) { 
	int ret;
	ret = x > y ? x : y;
	return ret > z ? ret : z;
}
int find3Min(int x, int y, int z) { 
	int ret;
	ret = x < y ? x : y;
	return ret < z ? ret : z;
}
void problem2() {
	printf("3���� ������ �Է��ϼ��� : ");
	int x, y, z; scanf("%d %d %d", &x, &y, &z);
	int max = find3Max(x, y, z);
	int min = find3Min(x, y, z);
	printf("max : %d   min : %d\n", max, min);
}
//3. ���� ������ �Է¹ް� �� ����ŭ "�����մϴ�"�� ����ϴ� �Լ��� ���弼��
void problem3() {
	printf("���� ������ �Է��ϼ��� : ");
	int cnt; scanf("%d", &cnt);
	for (int i = 1; i <= cnt; i++) {
		printf("�����մϴ�\n");
	}printf("\n");
}
//4. 5�� �Է��ϸ�
//o
//* o
//* *o
//* **o
//* ***o
//�̷��� ����ϴ� �Լ��� ���弼��
//void triangle(int num, char mainChar, char endChar);
//
//����� triangle(5, '*', 'o');
//�̷��� �ϸ� �˴ϴ�.
int problem4(int num, char mainChar, char endChar) {
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == i) printf("%c", endChar);
			else printf("%c", mainChar);
		}printf("\n");
	}printf("\n");
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
		else if (select == 4) problem4(5,'*','o');
	}
}