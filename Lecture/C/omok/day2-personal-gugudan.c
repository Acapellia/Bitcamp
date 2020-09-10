/*
	구구단 출력하기 - 개별 과제
	- 제어문 학습

	2 x 1 = 2	3 x 1 = 3	4 x 1 = 4 \n
	2 x 1 = 2	3 x 1 = 3	4 x 1 = 4 \n
	...
	5 x 1 = 2	6 x 1 = 3	7 x 1 = 4 \n
	5 x 1 = 2	6 x 1 = 3	7 x 1 = 4 \n
	...
	8 x 1 = 2	9 x 1 = 3			  \n
	8 x 1 = 2	9 x 1 = 3			  \n
	...

*/
#include <stdio.h>

int main(void) {
	int leftdan = -1;
	int dan;
	int v;
	int unit = 2;// 한 줄에 몇 개 단을 ...
	for (int bl = 0; bl < 3; ++bl) {
		leftdan += unit;
		for (int row = 0; row < 9; ++row) {
			v = row+1;
			for (int col = 0; col < unit; col++) {
				dan = leftdan + col;
				if ( dan <= 9) {
					printf("%d x %d = %d\t", dan, v, (dan * v));
				}
			}
			printf("\n");
		}
		printf("------\n");
	}
	return 0;
}