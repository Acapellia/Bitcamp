#include<stdio.h>
//1. 10개 정수 입력 후 최대 최소 총합 평균을 구하는 함수를 만듭니다.
//단 최대, 최소, 총합, 평균 매개변수를 포인터 변수로 전달해서
//결과를 직접 포인터 변수를 통해 전달 받도록 합니다.
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
	printf("10개의 정수를 입력하세요 : "); 
	for(int i=0;i<10;i++)
		scanf("%d", &num[i]);
	calc(num,10,&max,&min,&sum,&avg);
	printf("max : %d min : %d sum : %d avg : %.2lf\n", max,min,sum,avg);
}
//2.소문자를 대문자로, 대문자를 소문자로,
//그외 문자는 그대로 출력하세요.(변환하는 함수를 만들것)
//결과를 직접 포인터 변수를 통해 전달 받도록 합니다.
void changeChar(char* c) {
	if ('A' <= *c && *c <= 'Z') { *c = *c + 32; }
	else if ('a' <= *c && *c <= 'z') { *c = *c - 32; }
}
void problem2() {
	while (1) {
		printf("문자를 입력하세요 : ");
		char c; scanf(" %c", &c);
		changeChar(&c);
		printf("변환한 문자는 %c 입니다\n",c);
	}
}
//3. 사용자로부터 초를 입력받은 후 이를[시, 분, 초]의
//형태로 출력하는 프로그램을 작성하세요.
//1) 입력 함수
//2) 시간 계산(결과를 직접 포인터 변수를 통해 전달 받도록 합니다)
//3) 출력 함수
int inputTime() {
	int sec;
	printf("초를 입력하세요 : "); scanf("%d", &sec);
	return sec;
}
void calcTime(int *hour, int *min, int* sec) {
	*hour = *sec / 3600; *sec = *sec % 3600;
	*min = *sec / 60; *sec = *sec % 60;
}
void printTime(int hour, int min, int sec) {
	printf("%d시 %d분 %d초\n", hour, min, sec);
}
void problem3() {
	int hour, min, sec = inputTime();
	calcTime(&hour, &min, &sec);
	printTime(hour, min, sec);
}
//4. 사용자로부터 시, 분, 초를 입력받은 후 초로 변환하는 함수와
//이 계산된 초를 출력하는 함수를 만들고 사용하세요
//1) 시, 분, 초 입력
//2) 계산 함수(결과를 직접 포인터 변수를 통해 전달 받도록 합니다)
//3) 초 출력 함수
void inputTime2(int *hour, int* min, int* sec) {
	printf("시 분 초를 입력하세요 : "); scanf("%d %d %d",hour, min, sec);
}
void calcTime2(int hour, int min, int* sec) {
	printf("%d시 %d분 %d초\n", hour, min, *sec);
	*sec = *sec + hour * 3600 + min * 60;
}
void printTime2(int sec) {
	printf("%d초\n", sec);
}
void problem4() {
	int hour, min, sec;
	inputTime2(&hour,&min,&sec);
	calcTime2(hour, min, &sec);
	printTime2(sec);
}
//5. 키와 몸무게를 입력하는 함수를 만들고 사용해보세요
//결과를 직접 포인터 변수를 통해 전달 받도록 합니다
void inputBody(double* h, double* w) {
	printf("키와 몸무게를 입력하세요 : ");
	scanf("%lf %lf", h, w);
}
void problem5() {
	double height, weight;
	inputBody(&height,&weight);
	printf("키 : %.1lfcm  몸무게 : %.1lfkg\n",height,weight);
}
//6. 반드시 A를 이용해서 B의 값을 채우도록 하세요
// 배열 A, B를 선언
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
		printf("선택 : ");
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