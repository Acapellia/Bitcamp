#include<stdio.h>
//1. do~while���� �̿��ؼ� 1���� 100���� ����ϼ���
//for���� �̿��ؼ� 1���� 100���� ����ϼ���
void problem1() {
	int num = 1;
	do {
		printf("%d ", num);
	} while (++num<=100);
	printf("\n");
	for (int i = 1; i <= 100; i++) printf("%d ", i);
}
//2. do~while���� �̿��ؼ� 10���� 20���� ����ϼ���
//for���� �̿��ؼ� 10���� 20���� ����ϼ���
void problem2() {
	int num = 10;
	do {
		printf("%d ", num);
	} while (++num <= 20);
	printf("\n");
	for (int i = 10; i <= 20; i++) printf("%d ", i);
}
//3. do~while���� �̿��ؼ� 1���� 10���� ���� ����ϼ���
//for���� �̿��ؼ� 1���� 10���� ���� ����ϼ���
void problem3() {
	int num = 1;
	int sum = 0;
	do {
		sum += num;
	} while (++num <= 10);
	printf("sum : %d\n",sum);
	sum = 0;
	for (int i = 1; i <= 10; i++) sum += i;
	printf("sum : %d ", sum);
}
//4. do~while���� �̿��ؼ� 1���� 10���� �߿� ¦���� ����ϼ���
//do~while������ ���ǹ��� �־��ָ� ��
//¦�� ���� if (num % 2 == 0)
void problem4() {
	int num = 1;
	do {
		if(num%2==0)	printf("%d ", num);
	} while (++num <= 10);
	printf("\n");

	for (int i = 1; i <= 10; i++) {
		if (i % 2 == 0) printf("%d ", i);
	}
}
//5. do~while���� �̿��ؼ� ���� ������ �Է¹ް� �� ����ŭ "�����մϴ�"�� ����ϼ���
//for���� �̿��ؼ� ���� ������ �Է¹ް� �� ����ŭ "�����մϴ�"�� ����ϼ���
void problem5() {
	int num; 
	int n=0;
	printf("���ڸ� �Է��ϼ��� : ");  scanf("%d", &num);
	do {
		printf("�����մϴ�\n");
	} while (++n<num);
	printf("\n");

	for (int i = 1; i <=num ; i++) {
		printf("�����մϴ�\n");
	}
}
//6. do~while���� �̿��ؼ� ���� ���� �Է¹ް� �� ����ŭ 3�� ��� ����ϼ���
//���� ��� 5�� �Է¹����� 3 6 9 12 15�� ����ϸ� �˴ϴ�
//for���� �̿��ؼ� ~
void problem6() {
	int num;
	int n = 1;
	printf("���ڸ� �Է��ϼ��� : ");  scanf("%d", &num);
	do {
		printf("%d ",3*n);
	} while (++n <= num);
	printf("\n");

	for (int i = 1; i <= num; i++) {
		printf("%d ",3*i);
	}
}
//7. do~while���� �̿��ؼ�, for���� �̿��ؼ� ���� 2������ Ǯ�����
//�Է¹��� ������ �������� ����ϼ���
//���� ��� 3�� �Է��ϸ�
//3 x 1 = 3
//3 x 2 = 6
//...
//3 x 9 = 27
void problem7() {
	int num; 
	int m = 1;
	printf("������ ���� �Է� : ");  scanf("%d", &num);
	do {
		printf("%d * %d = %d\n",num,m,num*m);
	} while (++m < 10);
	printf("\n");

	for (int i = 1; i < 10; i++) {
		printf("%d * %d = %d\n", num, i, num * i);
	}
}
//8. do~while���� �̿��ؼ�, for���� �̿��ؼ� 2������ Ǯ�����
//����ڷκ��� ������ �Է¹޽��ϴ�.
//�Է� ���� ���� ��� ���մϴ�
//����ڰ� 0�� �Է��ϸ� ���� ����մϴ�
//�׸��� ���α׷��� �����մϴ�.
void problem8() {
	int num=0;
	int sum = 0;
	do {
		printf("���ڸ� �Է��ϼ��� : ");
		scanf("%d", &num);
		sum += num;
	} while (num!=0);
	printf("%d\n",sum);
	
	sum = 0;
	for (int i = 1; ; i++) {
		printf("���ڸ� �Է��ϼ��� : ");
		scanf("%d", &num);
		if (num == 0) break;
		sum += num;
	}
	printf("%d\n", sum);
}
//9. 0���� 1�� ������ ���� �����Ͽ� ���մϴ�.
//��� ���Ѱ��� 1000�� ���� �� �� ���հ�
//���� ���� ���ϼ���.
void problem9() {
	int sum = 0;
	int n = 0;
	while (1) {
		sum += n;
		if (sum > 1000) break;
		n++;
	}
	printf("���� : %d ���� �� : %d\n", sum, n);
}
//10. int multiplication[8][9] �迭�� �����ϼ���
//�׸��� �������� 2 ~9�ܱ����� �������
//�迭�� �����ϼ���
//�׸��� ����ϼ���
void problem10() {
	int multiplication[8][9];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9;j++) {
			multiplication[i][j] = (i + 2) * (j + 1);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d * %d = %d\n",i+2,j+1,multiplication[i][j]);
		}printf("\n");
	}
	printf("\n");
}
int main() 
{
	while (1) {
		printf("������ ������ �Է��ϼ��� : ");
		int select; scanf("%d", &select);
		if (select == 0) break;
		else if (select == 1) problem1();
		else if (select == 2) problem2();
		else if (select == 3) problem3();
		else if (select == 4) problem4();
		else if (select == 5) problem5();
		else if (select == 6) problem6();
		else if (select == 7) problem7();
		else if (select == 8) problem8();
		else if (select == 9) problem9();
		else if (select == 10) problem10();
		printf("\n\n");

	}
}