#include<stdio.h>
// 1��
// ���ڸ� �Է¹ް� ���� ��ŭ ������ ��� �� ������ "������ ĳ����" 
// 2��
// 1���� �Լ��� ����� �Լ��� ���ڸ� �����ϸ� "������ ��´�"�� �ݺ�
// 3��
// �Լ��� ���� func(�ݺ�Ƚ��,�ش� ��°���� ���� ���)
// chopTree(10,3)
// 4��
// chopTree(10,3,2) 3���� �ѹ� �� 2���� �ѹ� ½
void chopTree(int n, int c,int c2) {
	for (int i = 1; i <= n; i++) {
		printf("������ %2d�� �����!!\n",i);
		if (i%c == 0) printf("��~~\n");
		if (i%c2 == 0) printf("½~~\n");
	}
	printf("������ ������!!!\n\n");
}
void main()
{
	int n,c,c2; 
	while (1) {
		printf("�ݺ�Ƚ�� n�� �� ��� c ½ ��� c2: ");
		scanf_s("%d %d %d", &n, &c, &c2);
		printf("\n");
		if (n == 0) break;
		chopTree(n, c, c2);
	}
}

