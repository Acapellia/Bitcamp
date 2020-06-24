#include<stdio.h>
//1. 두 수를 입력받고 최소공배수를 구하는 함수를 만들고 사용하세요
/*int getGcd(int num0, int num1) {
	int temp, tnum;
	// 유클리드
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
	printf("두 수를 입력하세요 : ");
	int num0, num1;
	scanf("%d %d", &num0, &num1);
	int lcm = getLcm(num0,num1);
}
//2. 2개의 정수를 입력받습니다.
//첫번째 정수는 해당 수의 배수
//두번째 정수는 반복 회수입니다
//예를 들어 첫번째 숫자는 5
//두번째 숫자는 7
//결과 : 5 10 15 20 25 30 35
void viewMultiple(int num0, int num1) {
	for (int i = 1; i <= num1; i++)
		printf("%d ", i * num0);
}
void problem2() {
	printf("두 수를 입력하세요 : ");
	int num0, num1;
	scanf("%d %d", &num0, &num1);
	viewMultiple(num0, num1);
}
//3. 입력받은 숫자의 구구단을 출력하는데 역순으로 출력하는 함수를 만들고 출력하세요
//예) 3 * 9 = 27
//3 * 8 = 24...
//void viewMultiplication(int num);
void viewMultiplication(int num) {
	for (int i = 9; i >= 1; i--)
		printf("%d * %d = %d\n", num, i, num * i);
}
void problem3()
{
	printf("구구단 출력을 원하는 숫자를 입력하세요 : ");
	int num;  scanf("%d", &num);
	viewMultiplication(num);
}
//4. 정수 n을 입력받고 n!을 구하세요.(factorial)
//5를 입력한경우 1 * 2 * 3 * 4 * 5를 구하세요.
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
	printf("factorial 출력을 원하는 숫자를 입력하세요 : ");
	int num;  scanf("%d", &num);
	int fact = factorial(num);
	printf("%d factorial : %d\n", num, fact);
}
int main()
{
	while (1) {
		printf("실행할 과제를 입력하세요 : ");
		int select; scanf("%d", &select);
		if (select == 0) break;
		else if (select == 1) problem1();
		else if (select == 2) problem2();
		else if (select == 3) problem3();
		else if (select == 4) problem4();
		printf("\n");
		
	}
}