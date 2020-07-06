#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*	5행 3열 구조의 배열 연습
	- 0 ~ 9 사이 정수를 전달받아 숫자 모양을 출력하는 함수 
	[ ][0][ ]
	[0][ ][0]
	[0][0][0]
	[0][ ][0]
	[ ][0][ ]

	포인터 함수포인터 -> 함수를 교체할 수 있다.
	EVT ( 이벤트 발생 처리할 함수들의 표 )
*/

int display(int n) {
	char darr[10][15] = {
	{
		1, 1, 1,
		1, 0, 1,
		1, 0, 1,
		1, 0, 1,
		1, 1, 1
	},
	{
		0, 1, 0,
		1, 1, 0,
		0, 1, 0,
		0, 1, 0,
		1, 1, 1
	},
	{
		1, 1, 1,
		0, 0, 1,
		1, 1, 1,
		1, 0, 0,
		1, 1, 1
	},
	{
		1, 1, 1,
		0, 0, 1,
		1, 1, 1,
		0, 0, 1,
		1, 1, 1
	},
	{
		1, 0, 0,
		1, 0, 1,
		1, 1, 1,
		0, 0, 1,
		0, 0, 1
	},
	{
		1, 1, 1,
		1, 0, 0,
		1, 1, 1,
		0, 0, 1,
		1, 1, 1
	},
	 {
		1, 1, 1,
		1, 0, 0,
		1, 1, 1,
		1, 0, 1,
		1, 1, 1
	},
	 {
		1, 1, 1,
		1, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1
	},
	 {
		1, 1, 1,
		1, 0, 1,
		1, 1, 1,
		1, 0, 1,
		1, 1, 1
	},
	 {
		1, 1, 1,
		1, 0, 1,
		1, 1, 1,
		0, 0, 1,
		1, 1, 1
	}

	};// [10][15]
	int digit;
	int idx = 0;
	for (int i = 0; i < 5; ++i) {
		for (int k = 0; k < 3; ++k) {
			// 배열 요소번호 선택한다... if 분기문 대체할 수 있다..
			digit = darr[n][idx];
				/*
				(n == 0) ? d0[idx] :
				(n == 1) ? d1[idx] :
				(n == 2) ? d2[idx] :
				(n == 3) ? d3[idx] :
				(n == 4) ? d4[idx] :
				(n == 5) ? d5[idx] :
				(n == 6) ? d6[idx] :
				(n == 7) ? d7[idx] :
				(n == 8) ? d8[idx] :
						   d9[idx];
				*/
				++idx;
			printf("%s", (digit) ? "ㅁ" : "  ");
		}
		printf("\n");
	}

	return 0;
}

int main(void) {
	display(0);
	return 0;
}