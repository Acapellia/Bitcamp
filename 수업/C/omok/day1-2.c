#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	C 언어의 자료형
	- 문제를 보고 처리할 값들이 어떤 종류인지
	- 값을 저장하는 기본형
	- 주소를 저장하는 참조형(포인터형)
*/
int main(void) {
	char 문자 = 'A'; // ASCII - 1byte
	int 정수_4 = 10; // 4 byte
	double 실수_8;// math .h 함수들의 기본형

	short 정수_2 = 10; // 2 byte
	long 정수_4 = 10; // int ?
	long long 정수_8 = 100;
	float 실수_4;

	// 참조형 -> 포인터형
	char *s;

	return 0;
}
