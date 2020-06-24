
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int drawLine(int x);

int main(void) {
	int y, x;
	int a, b;

	a = -1;
	b = 5;
	for (x = 0; x < 20; ++x) {
		y = (a * x) + b;
		system("cls");// 출력 전에 화면 지우기
		for (int r = 0; r < 20; ++r) {
			for (int c = 0; c < 20; ++c) {
//				(r == y && c == x) ?
				(c == 5) ?
					printf("○") : printf("  ");
			}
			printf("\n");
		}
	}
	return 0;
}

int main_01(int argc, char* argv[]) {
	int a = 1;
	int b = -5;// y축 이동
	int x = 0;
	int y = (a * x) + b;// 변수들의 관계(식)
	y = 5;	// 수평선
	x = 5;	// 수직선
	for (x = 0; x < 10; ++x) {// 0 ~ 9 -> y
		y = (a * x) + b;// 변수들의 관계(식)
		printf("{%d,%d}\n", x, y);
	}
	
	return 0;
}

int drawLine(int x) {
	// 화면 선을 그리는 프로그램 구현
	int y;
//	int x = 5;
	// 행, 열 표현 시 반복문 2개 겹쳐서 만드는 코드
	y = (1 * x) + 5;
	for (int r = 0; r < 10; ++r) {
		printf("[%2d]", r);
		for (int c = 0; c < 10; ++c) {
			// 각 위치(r,c)
			if (r == y && c == x) {
				printf("##");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}

	return 0;
}