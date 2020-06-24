#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 제어문
	반복 : for while do-while 
	분기 : if(논리), switch(상수,산술)
*/
int main(void) {
	// 1 ~ 25까지 연속 정수들을 출력
	// 5 x 5 출력하는 몇 가지 방법'
	// 표 : 2차 
	int v = 1;
	for (int r = 0; r < 5; ++r) {
		for (int c = 0; c < 5; ++c) {
			printf("%d\t", v);
			v++;// 연속하는 정수 값
			if (v > 25) {
				// 강제종료
				exit(1);
			}
		}
		printf("\n");
	}

	printf("\n");
	int cnt = 0;
	for (int v = 1; v < 26; ++v) {
		printf("%d ", v);
		cnt++;
		// 행 하나에 5개씩 출력하면 행을 내린다...
		if ( cnt == 5) {
			printf("\n");
			cnt = 0;
		}
	}

	return 0;
}

int main_01(void) {
	// 1 ~ 25 까지 연속하는 정수들을 출력
//	printf("1 2 ... 25 \n"); // 직접 다 하는 경우
	// 제어문으로 코드 량 줄이거나 변경이 쉬운 
	int min = 100;// 입력
	int max = 25;// 입력
	// 사용자 순서를 반대로 입력 경우도 생김....
	// 인지(판단) - 분기문....
	if (min > max) {
		// 두 변수의 값을 교환한다...
		int temp = min;
		min = max;
		max = temp;
		// 비트연산자 XOR 연산 활용법
	}

	for ( int n = min ; n <= max ; n++)
	{
		printf("%d ", n);
	}
	printf("\n");

	return 0;
}