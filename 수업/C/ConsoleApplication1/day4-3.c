#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
// 매크로 상수 : 이름이 있는 상수
#define ASIZE 5

// 2차 배열 사용하기
// step 2. 2차배열을 전달한다....
int display(int numbers[][ASIZE], int rows) {
	// 길이를 계산 가능
	// 1차배열 여러 개가 있다... 길이 10인 1차 배열 5개가 있다...
	printf("\t");
	for (int i = 0; i < ASIZE; ++i) {
		printf("%d\t", i);
	}
	printf("\n");

	for (int row = 0; row < rows; ++row) {
		// row번 행, 1차배열
		printf("%d\t", row);
		for (int col = 0; col < ASIZE; ++col) {
			// col번 열, 변수 10개 
			printf("%d\t", numbers[row][col]);
		}
		printf("\n");
	}
	return 0;
}

int main(int argc, char** argv) {

	return 0;
}

int main_01(int argc, char** argv) {
	int pan[ASIZE][ASIZE] = { 0 };

	pan[0][1] = 1;	// [0]번이 [1]번에게 이김
	pan[1][0] = -1;	// 따라서 [1]번은 [0]번에게 짐
	display(pan, ASIZE);// 배열명, 길이

	return 0;
}
