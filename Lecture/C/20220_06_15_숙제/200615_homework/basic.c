#include<stdio.h>
//1. while���� �̿��ؼ� 1���� 100���� ����ϼ���
//2. while���� �̿��ؼ� 10���� 20���� ����ϼ���
//3. while���� �̿��ؼ� 1���� 10���� ���� ����ϼ���
//4. while���� �̿��ؼ� 1���� 10���� �߿� ¦���� ����ϼ���
//while������ ���ǹ��� �־��ָ� ��
//¦�� ���� if (num % 2 == 0)
//5. ���� ������ �Է¹ް� �� ����ŭ "�����մϴ�"�� ����ϼ���
//6. ������ ���ڸ� �Է¹޾Ƽ� ���� ū ���� ����ϴ� ���α׷��� �����϶�
void problem1() {
	int cnt = 0;
	while (cnt++ < 100) {
		printf("%d ", cnt);
	}printf("\n");
}
void problem2() {
	for (int i = 10; i <= 20; i++) {
		printf("%d ", i);
	}printf("\n");
}
void problem3() {
	int sum = 0;
	for (int i = 1; i <= 10; i++) {
		sum += i;
	}
	printf("sum : %d\n",sum);
}
void problem4() {
	for (int i = 1; i <= 10; i++) {
		if (i % 2 == 0) printf("%d ", i);
	}printf("\n");
}
void problem5() {
	printf("���� ������ �Է��ϼ��� : ");
	int cnt; scanf("%d", &cnt);
	for (int i = 1; i <= cnt; i++) {
		printf("�����մϴ�\n");
	}printf("\n");
}
void problem6() {
	int max = 0;
	for (int i = 1; i <= 3; i++) {
		printf("���ڸ� �Է��ϼ��� : ");
		int x; scanf("%d", &x);
		if (x > max) max = x;
	}
	printf("max : %d\n",max);
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
		else if (select == 6) problem6();
	}
}*/