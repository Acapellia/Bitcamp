#include<stdio.h>
//1. �� ���� �Է¹ް� �ּҰ������ ���ϴ� �Լ��� ����� ����ϼ���
/*int getGcd(int num0, int num1) {
	int temp, tnum;
	// ��Ŭ����
	if (num0 < num1) { temp = num0; num0 = num1; num1 = temp; }
	while (1) {
		tnum = num0 % num1;
		num0 = num1;
		num1 = tnum;
		if (tnum == 0) break;
	}
	tnum = num0;
}
int getLcm(int num0, int num1) {
	int gcd = getGcd(num0,num1);
	printf("lcm : %d\n", (num0 * num1) / gcd);
}*/
int getLcm(int num0, int num1) {
	int lcm;
	for (int i = 1;; i++) {
		lcm = num0 * i;
		if (lcm % num1 == 0) break;
	}
	printf("lcm : %d\n", lcm);
}
void problem1() {
	printf("�� ���� �Է��ϼ��� : ");
	int num0, num1;
	scanf("%d %d", &num0, &num1);
	int lcm = getLcm(num0,num1);
}
//2. 2���� ������ �Է¹޽��ϴ�.
//ù��° ������ �ش� ���� ���
//�ι�° ������ �ݺ� ȸ���Դϴ�
//���� ��� ù��° ���ڴ� 5
//�ι�° ���ڴ� 7
//��� : 5 10 15 20 25 30 35
void viewMultiple(int num0, int num1) {
	for (int i = 1; i <= num1; i++)
		printf("%d ", i * num0);
}
void problem2() {
	printf("�� ���� �Է��ϼ��� : ");
	int num0, num1;
	scanf("%d %d", &num0, &num1);
	viewMultiple(num0, num1);
}
//3. �Է¹��� ������ �������� ����ϴµ� �������� ����ϴ� �Լ��� ����� ����ϼ���
//��) 3 * 9 = 27
//3 * 8 = 24...
//void viewMultiplication(int num);
void viewMultiplication(int num) {
	for (int i = 9; i >= 1; i--)
		printf("%d * %d = %d\n", num, i, num * i);
}
void problem3()
{
	printf("������ ����� ���ϴ� ���ڸ� �Է��ϼ��� : ");
	int num;  scanf("%d", &num);
	viewMultiplication(num);
}
//4. ���� n�� �Է¹ް� n!�� ���ϼ���.(factorial)
//5�� �Է��Ѱ�� 1 * 2 * 3 * 4 * 5�� ���ϼ���.
//int factorial(int num);
//
//factory(5) = > 120

int factorial(int num) {
	int f = 1;
	for (int i = 1; i <= num; i++) {
		printf("%d ",i);
		f *= i;
		printf("%d\n", f);
	}
	return f;
}
void problem4()
{
	printf("factorial ����� ���ϴ� ���ڸ� �Է��ϼ��� : ");
	int num;  scanf("%d", &num);
	int fact = factorial(num);
	printf("%d factorial : %d\n", num, fact);
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
		printf("\n");
		
	}
}