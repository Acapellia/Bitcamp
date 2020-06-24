#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	// 자료형 변수의 선언과 사용
	int num;
	num = 10;
	printf("%d \n", num);// 형식 문자열
	int score;// 변수 선언 시 에러나면 위로 이동
	score = 20;
	printf("%c %d %lf %s \n", 
		   'A',12, 32.45, "string" );// 형식 문자열
	return 0;
}
