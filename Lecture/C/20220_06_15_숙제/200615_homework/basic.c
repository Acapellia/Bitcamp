#include<stdio.h>
//1. while문을 이용해서 1부터 100까지 출력하세요
//2. while문을 이용해서 10부터 20까지 출력하세요
//3. while문을 이용해서 1부터 10까지 합을 출력하세요
//4. while문을 이용해서 1부터 10까지 중에 짝수만 출력하세요
//while문내에 조건문을 넣어주면 됨
//짝수 조건 if (num % 2 == 0)
//5. 양의 정수를 입력받고 그 수만큼 "감사합니다"를 출력하세요
//6. 세개의 숫자를 입력받아서 가장 큰 수를 출력하는 프로그램을 구현하라
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
	printf("양의 정수를 입력하세요 : ");
	int cnt; scanf("%d", &cnt);
	for (int i = 1; i <= cnt; i++) {
		printf("감사합니다\n");
	}printf("\n");
}
void problem6() {
	int max = 0;
	for (int i = 1; i <= 3; i++) {
		printf("숫자를 입력하세요 : ");
		int x; scanf("%d", &x);
		if (x > max) max = x;
	}
	printf("max : %d\n",max);
}
/*void main()
{
	int select;
	while (1) {
		printf("선택 : ");
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