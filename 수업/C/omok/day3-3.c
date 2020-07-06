
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/*	드디어~ 포인터~ 와~~~
	
*/
int main(void) {
	int n[10] = { 0 };
	int (*p)[10] = &n;// 2차배열
	printf("n : %d \n", n);
	// 주소에 있는 값의 크기
	printf("n : %d \n", sizeof(*n) );

	// 배열의 주소 : &배열명
	printf("n : %d \n", &n);
	// 주소에 있는 값의 크기
	printf("n : %d \n", sizeof(*(&n)));

	int* p1;
	p1 = n;	// n == &n[0];
	int (*p2)[10] = &n;// 배열 포인터


	return 0;
}

int main_01(void) {
	char ch = 'A';
	printf("size : %d \n", sizeof(ch));
	printf("address : %d \n", &(ch));// 변수의 주소
	printf("size : %d \n", sizeof(&ch));// 주소의 크기

	char* p;
	printf("size : %d \n", sizeof(p));
	printf("address : %d \n", &(p));// 변수의 주소
	printf("size : %d \n", sizeof(&p));// 주소의 크기

	p = &ch;	// ch 변수의 주소를 저장한다...
	printf("%d \n", p);	// 주소
	printf("%d \n", *p);	// 이름 ch 의 값
	*p = 'B';
	printf("%c \n", ch);	// 이름 ch 의 값

	p = 'C';


	return 0;
}

/*
int main_01(void) {
	// 포인터 변수의 선언 : 자료형 * 변수명;
	//	포인터 변수에 저장된 주소에 어떤 유형 있냐

	char ch;	// 문자 1개 저장하는 변수
	char* p1;	// char 변수를 가리키는 포인터 변수
		// char 변수 여러 개를 다룰 수 있다.... ( 배열 처럼 )
	char** p2;
		// char 변수를 가리키는 포인터변수를 가리키는 포인터변수
		//	삼중 이하만 사용

	char* ap1[3];// 포인터변수들을 요소로하는 1차 배열
	char	(*ap2)[3];// 배열을 가리키는 배열 포인터변수
	char* (*ap3)[3];// 배열을 가리키는 배열 포인터변수

	char (*fp)(void);	// 함수를 가리키는 함수 포인터변수
	char (*evt[5])(void);	// 함수 포인터 배열

	return 0;
}
*/






