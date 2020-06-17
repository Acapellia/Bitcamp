#include<stdio.h>
#include<windows.h>
#include<time.h>
//1. 숫자 야구 게임을 작성하세요. (아래의 함수로 구성할 것,
//	필요하면 함수 더 작성해도 됨)
//	1) 사용자 입력
//	2) 계산
//	3) 결과 보여주기
//	4) 다시 시작 여부
//
//	0 ~9 중복되지 않게
//	컴퓨터가 난수를 3개 생성
void makeNum(int num[3]) {
	int check[10] = { 0 };
	for (int i = 0; i < 3; i++) {
		while (1) {
			int n = rand() % 10;
			if (i == 0 && n == 0) continue;
			if (check[n] == 1) continue;
			num[i] = n; check[n] = 1; break;
		}
	}
}
int comparison(int com[3], int user[3]) {
	int strike = 0, ball = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (com[i] == user[j]) {
				i == j ? strike++ : ball++;
			}
		}
	}
	printf("%d strike %d ball ~~~\n\n", strike, ball);
	return strike;
}
int retryGame() {
	printf("다시 하시겠습니까?(yes:1 no:0)\n");
	int r; scanf("%d", &r);
	return r == 1 ? 1 : 0;
}
int problem1() {
	printf("컴퓨터가 게임을 위한 수를 생각합니다.\n");
	Sleep(3000);
	int com[3];
	makeNum(com);
	printf("컴퓨터가 수를 생각했습니다.\n");
	Sleep(1000);
	printf("게임을 시작합니다.\n");
	Sleep(1000);
	while (1) {
		printf("'User'가 생각한 수를 입력해주세요\n");
		int user[3] = {0};
		printf("-----------------\n");
		for (int i = 0; i < 3; i++) {
			printf("%d번째 수 : ",i + 1); scanf("%d", &user[i]);
		}
		printf("-----------------\n");
		int strike = comparison(com,user);
		if (strike == 3) { 
			printf("성공하셨습니다~~~!!\n\n"); break;
		}
	}
	int r = retryGame();
	return r == 1 ? 1 : 0;
}
int main()
{
	srand((unsigned)time(NULL));
	while (1) {
		printf("실행할 과제를 입력하세요 : ");
		int select; scanf("%d", &select);
		if (select == 0) break;
		else if (select == 1) {
			while (1) {
				int game = problem1();
				if (game == 0) break;
			}
			printf("게임을 종료하였습니다.\n");
		}
		printf("\n");

	}
}