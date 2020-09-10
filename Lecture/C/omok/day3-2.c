#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


int run(void) {
	int on[15] = { 0 };
	srand((unsigned)time(NULL));
	for (int r = 0; r < 15; ++r) {
		on[r] = rand() % 40;
	}
	while (1) {
		system("cls");
		for (int r = 0; r < 15; ++r) {
			for (int c = 0; c < 40; ++c) {
				printf("%s", (c == on[r]) ? "●":"○" );
			}
			printf("\n");
		}
		for (int r = 0; r < 15; ++r) {
			on[r]++;
			on[r] %= 40;
		}

		if (_kbhit()) {
			if (_getch() == '\r') {
				break;
			}
		}
	}
	printf("terminated \n\n");
	return 0;
}
int shooters(void) {
	int first_line = 0;
	int last_line = 19;
	int width = 40;
	int p1[3];
	p1[0] = rand() % width;
	p1[1] = p1[0];
	p1[2] = first_line+1;

	int p2[3];
	p2[1] = p2[0] = rand() % width;
	p2[2] = last_line - 1;

	while (1) {
		system("cls");
		// first line
		for (int c = 0; c < width; ++c) {
			if (c == p1[0]) {
				printf("■");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");

		for (int r = first_line+1; r < last_line-1; ++r) {
			for (int c = 0; c < width; ++c) {
				if (p1[2] == r && p1[1] == c) {
					printf("▽");
				}
				else if (p2[2] == r && p2[1] == c) {
					printf("▲");
				}
				else {
					printf("  ");
				}
			}
			printf("\n");
		}
		// last line
		for (int c = 0; c < width; ++c) {
			if (c == p2[0]) {
				printf("※");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");

		p1[0] += rand()%3-1;
		if (p1[0] < 0) p1[0] = 0;
		if (p1[0] >= width) p1[0] = width-1;
		p1[2]++;
		if (p1[2] == last_line) {
			p1[2] = first_line + 1;
			p1[1] = p1[0];
		}

		p2[0] += rand() % 3 - 1;
		if (p2[0] < 0) p2[0] = 0;
		if (p2[0] >= width) p2[0] = width-1;
		p2[2]--;
		if (p2[2] == first_line) {
			p2[2] = last_line - 1;
			p2[1] = p2[0];
		}

		if (_kbhit()) {
			if (_getch() == '\r') {
				break;
			}
		}
	}
	printf("terminated \n\n");
	return 0;
}

int main(void) {
	int W = 19;
	int H = 19;
	int omokpan[ 19 * 19 ] = { 1,0,1,1,0 };
	// 요소의 값이 0 이면 ┼ +

	for (int r = 0; r < H; ++r) {
		for (int c = 0; c < W; ++c) {
			// 값에 따른 분기 처리할 수 있다...
			int v = omokpan[r * W + c];
			if ( v == 0) {
				printf("┼ ");
			}
			else if ( v == 1) {
				printf("○");
			}
		}
		printf("\n");
	}

	return 0;
}

int main_02(void) {
	int shape[40] = { 1 };
	int cur = 1;
	while(1){
		system("cls");// 윈도우 명령: 화면 지우기
		for (int i = 0; i < 40; ++i) {
			// 요소의 값에 따라 출력할 문자열이 다르다...
			printf("%s", (shape[i]) ?"@ " : "  ");
		}
		printf("\n");
		// 1을 한 칸씩 오른쪽으로 옮긴다....
		shape[cur-1] = 0;
		shape[cur] = 1;
		cur++;
		cur %= 40;// 0 ~ 39
	}

	return 0;
}
int main_01(void) {
	// 길이 15인 정수형 1차 배열 선언하기
	int numbers[15] = { 0 };
	int length = 15;// sizeof(배열명)/sizeof(int);
	// 난수 발생 기준값 변경
	srand( (unsigned int)time(NULL));// 시간
	// 모든 요소에 임의 정수를 저장하기
	for (int i = length - 1; i >= 0; --i) {
		numbers[i] = rand();// 0 ~ 32656
	}
	for (int i = 0; i < length ; ++i) {
		printf("%6d", numbers[i]);
	}
	printf("\n");

	// 배열 처리 시 기본 기능
	int min;
	int max;
	min = max = numbers[0];
	// 찾기 : 값, 요소번호
	for (int i = 1; i < length; ++i) {
		if (min > numbers[i]) {
			min = numbers[i];
		}
		if (max < numbers[i]) {
			max = numbers[i];
		}
	}
	printf("Max : %d, Min : %d \n", max, min);
	// 요소번호
	min = max = 0;
	for (int i = 1; i < length; ++i) {
		if (numbers[min] > numbers[i]) {
			min = i;
		}
		if (numbers[max] < numbers[i]) {
			max = i;
		}
	}
	printf("Max : %d, Min : %d \n", numbers[max], numbers[min]);

	// 배열 요소들을 크기 순서대로 재배치 - 정렬 sort
	//	정렬 방법 - 알고리즘(다양하다)
	//	비교 - 교환
	int first = 0; // 첫 번째 요소번호
	int last = length - 1;// 마지막 요소번호

	for (int k = 0; k < 8; ++k) {
		int min = first;
		int max = first;
		for (int i = first+1; i <= last; ++i) {
			if (numbers[min] > numbers[i]) {
				min = i;
			}
			if (numbers[max] < numbers[i]) {
				max = i;
			}
		}
		// 교환
		int t = numbers[min];
		numbers[min] = numbers[first];
		numbers[first] = t;
		t = numbers[max];
		numbers[max] = numbers[last];
		numbers[last] = t;
		++first;
		--last;
	}
	// 정렬 후 출력
	for (int i = 0; i < length; ++i) {
		printf("%6d", numbers[i]);
	}
	printf("\n");


	return 0;
}
