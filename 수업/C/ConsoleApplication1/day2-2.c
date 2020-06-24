#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printBits(int n){
	for (int b = 31; b >= 0; --b) {
		// 마스킹 :  특정 비트의 상태를 파악, 0 !0
		if (n & (1 << b)) {// b번 비트의 값이 1이면
			printf("1");
		}
		else {
			printf("0");
		}
	}
	printf("\n");
}
/*
	중복없는 3자리 정수를 10개 이상 출력하시오
	- 이전에 사용한 적이 있는가에 대한 상태 표시 방법(2진수)
*/
int main(void) {
	// 조립 과정 : 10진수 정수, 각 자리 값을 합친다...
	// 2진수 연산으로 각 자리 값의 사용 여부 표시한다...
	int num = 0;
	int flag = 0;// 상태와 조작,,,,
	for (int i = 0; i < 10; ++i) {
		flag = 0;
		num = rand()%9+1;
		flag = flag | (1 << num);// 해결 방법 . 핵심
		for (int k = 1; k < 3; ++k) {
			int d;
			do {// 실행을 우선하고
				// 실행된 결과에 따라 반복 여부 결정
				d = rand() % 10;// 0 ~ 9 10진 1자리 값
			} while ( flag & ( 1<<d) );
			num = num * 10 + d;
			// 사용 표시
			flag = flag | (1 << d);
		}
		printf("%d \n", num);
	}


	return 0;
}

int main_03(void) {
	unsigned int n = 0xA5; //2진수값을 쓸 수 없다
	printBits(n);// 정수를 -> 2진수로 출력하는 함수

	// n 변수의 [2]번 비트를 0 으로 만드세요
	unsigned int a = (1 << 2);
	unsigned int c = ~(1 << 2);// [2]번을 제외한 나머지는 1
	n = n & c;// c변수의 1인 비트 자리는 모두 n 의 값이 그대로
	printBits(n);

	return 0;
}
