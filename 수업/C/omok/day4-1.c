/*
	1. 소스 파일 만들기 .c
	2. 헤더 파일 붙이기 .h
	3. main 함수 만들기 int main() { return 0;}
	4. main 함수 안에 실행 내용 작성하기
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*	선언 후 사용
	@arg : 
		argc - 인자의 개수
		argv - 문자열(들) 인자
*/
// 함수 선언부 //////////////////////////////////
// { } 뺀 앞부분만 적은 것
void fn(void);
int Sum(int a, int b);// 전달되는 값을 받을 변수 - 매개변수
int printIntArray(int ar[], int length/* 배열 길이*/ );

////////////////////////////////////////////////
int getValue(void)
{
	int result = 0;
	return result;
}

int main(int argc, char** argv) {// char* argv[]
/*
	fn();// 함수 호출(실행);
	int rt = getValue(); // 실행 후 int 형 값을 반환한다..
	// 함수의 반환은 1개만 가능, 전달은 여러 개 가능
	int hap = Sum(2, 10);
*/
	// 1차 배열을 전달한다... (배열명, 길이)
	int score[10] = { 0 };// 객체 지향의 핵심 1. 소유권
	int nums = printIntArray(score, 10);

	return 0;
}

// 함수 정의부 /////////////////////////////////////
void fn(void)
{
	// 반환형  void 일 때
	// return 생략 가능
	return; // 함수를 종료
}
int Sum(int a, int b)
{
	// 매개변수가 있는 함수를 호출할 때는
	//	반드시 전달해야 한다....
	int s = a + b;
	return s;
}
// 배열을 전달받는 함수 만들기
int printIntArray(int ar[], int length)
{
	// Q. 매개변수 이다..... 근데 int [] 배열
	int nums = 0;// 출력한 개수를 반환
	for (int i = 0; i < length; ++i) {
		printf("%d ", ar[i]);
		nums++;
	}
	printf("\n");// 화면 행 단위
	return nums;
}
// END day4-1.c ///////////////////////////////////




