#include <stdio.h>
/*
	선언 후 사용
*/
int main(void) {
	// 일정한 크기 배열을 무한한 공간처럼 사용하는 방법(알고리즘)
	// 2 개 이상의 변수들로 공간을 제어하는 방법
	// 요소 번호로 제어하는 아이디어 - 원형 큐

	// 스택 : 선입후출, 후입선출
	int score[10] = { 0 };
	int sp = -1;// 마지막 요소번호
	// 추가하기
	++sp;
	score[sp] = 1;
	// 마지막 요소를 꺼내기
	int value = score[sp];
	--sp;
	return 0;
}
int main_05(void) {
	// 정수 배열 - 추가
	// 추가 시 초기값에 따라 증감 순서 다르다.
	//	번호 범위를 판단하는 조건 다르다...
	int score[10] = { 0 };
	int last = 0;
	score[last] = 1;
	++last;
	score[last] = 2;
	++last;
	score[last] = 3;
	++last;

	// 출력 시 추가된 값들(저장한) 출력
	for (int i = 0; i < last; ++i) {
		printf("[%d] %d\n", i, score[i]);
	}

	if (last < 10) {
		score[last] = 3;// 범위 내
		++last;
	}
	else {
		printf("full \n");
	}

	return 0;
}

int main_04(void) {
	// 정수 배열 - 추가
	int score[10] = { 0 };
	int last = -1;	// 마지막 추가된 요소번호
	++last;
	score[last] = 1;// 처음이자 마지막
	++last;
	score[last] = 2;// 마지막
	++last;
	score[last] = 3;// 마지막
	// 출력 시 추가된 값들(저장한) 출력
	for (int i = 0; i <= last; ++i) {
		printf("[%d] %d\n", i, score[i]);
	}

	if ( last < 10-1 ) {
		++last;
		score[last] = 3;// 범위 내
	}
	else {
		printf("full \n");
	}

	return 0;
}
int main_03(void) {
	// 정수 배열 
	int maxLength = 10;
	int score[2 * 5] = { 0 };// 초기화된 배열 생성
	int index = 1*5 + 2;// 행번호 * 행 길이 + 열번호
	score[7] = 1;
	printf("%d \n", score[index]);
	printf("%d \n", score[7]);
	return 0;
}
int main_02(void) {
	int score[] = { 1,2,3,4,5,6,7,8,9 };// 묵시적 선언
	int length = sizeof(score)/sizeof(score[0]);// 배열의 길이를 변수에 따로 저장할 것

	printf("%d \n", score);// 배열의 시작주소, [0]번 요소의 주소

	// sizeof() 연산 : byte
	printf("size of array : %d \n", sizeof(score)); // 배열명
	printf("size of element : %d \n", sizeof(score[0]));
	// 요소명
	printf("long %d \n", sizeof(long));
	printf("long int %d \n", sizeof(long int));
	printf("long long %d \n", sizeof(long long));



	return 0;
}
int main_01(void) {
	// 배열 선언,생성 - 자료형, 최대 개수(길이)
	char string[80]; // 문자 배열 -> 문자열

	int curlength = 0;// 현재 길이, 최대 길이를 항상 비교

	int index = 0;// 요소번호 : 각 요소의 일련 번호

	// 배열명 : arr - [0]번 요소의 주소를 의미함....
	//	요소명 : 배열명[번호]
	//	요소가 배열인 경우 - 2차(다차) 배열
	//		요소명 == 배열명


	int arr[10];	// [] 하나 인 것을 1차 배열 - 선형
	int length = 10;
	// 처리 방법 - 반복문 사용
	for (int i = 0; i < length; ++i) {
		arr[i] = (i + 1);// 모든 요소에 임의 값을 저장
	}
	for (int i = 0; i < length; ++i) {
		printf("%d, ", arr[i]);// 요소의 값을 출력
	}

	return 0;
}