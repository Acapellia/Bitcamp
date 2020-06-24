#include<stdio.h>
//1. 양의 정수 입력받고 그 수만큼 3의 배수 출력하세요
//예를 들어 5를 입력받으면 3 6 9 12 15를 출력하면 됩니다
void problem1() {
	printf("양의 정수를 입력하세요 : ");
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("%d ", i * 3);
	}printf("\n");
}
//2. 사용자로부터 정수를 입력받습니다.
//입력 받은 값을 계속 더합니다
//사용자가 0을 입력하면 합을 출력합니다
//그리고 프로그램을 종료합니다.
void problem2() {
	int sum = 0;
	while (1) {
		printf("정수를 입력하세요 : ");
		int n; scanf("%d", &n);
		if (n == 0) { printf("sum : %d\n", sum);  break; }
		sum += n;
	}
	
}
//3. 5를 입력하면
//*
//**
//***
//****
//*****
//이렇게 출력하세요.
void problem3() {
	printf("정수를 입력하세요 : ");
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}printf("\n");
	}

}
//4. 5를 입력하면
//*****
//****
//***
//**
//*
//이렇게 역순으로 출력하세요.
void problem4() {
	printf("정수를 입력하세요 : ");
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			printf("*");
		}printf("\n");
	}
}
//5. 3명의 국어성적을 입력받고 총합과 평균을 출력하세요
//함수를 만들어서 사용하세요
//함수 이름 : inputKor, calcTotal, calcAvg
int inputKor() {
	int kor=0;
	printf("국어 성적을 입력하세요 : ");
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
		printf("선택 : ");
		scanf_s("%d", &select);
		if (select == 0) break;
		else if (select == 1) problem1();
		else if (select == 2) problem2();
		else if (select == 3) problem3();
		else if (select == 4) problem4();
		else if (select == 5) problem5();
	}
}*/