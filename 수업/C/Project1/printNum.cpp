#include<stdio.h>
#include<string.h> // 문자열
#include<math.h>
#include<stdlib.h> // 여러 유틸리티
#include<conio.h> // 콘솔용 입출력
#include<time.h>
#include<Windows.h>
/*
함수 1개
3*5 배열 표현
print함수 (0-9)
*/
/*char board[7][5] = { 0 };
void init() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 3; j++)
			board[i][j] = 0;
	}
}*/

/*void printNum(int n) {
	printf("num : %d\n\n", n);
	if (1) board[1][1] = '*';
	if (n != 4) board[1][2] = '*';
	if (n != 1) board[1][3] = '*';
	if (n != 1 && n != 2 && n != 3 && n != 7) board[2][1] = '*';
	if (n == 1) board[2][2] = '*';
	if (n != 1 && n != 5 && n != 6) board[2][3] = '*';
	if (n != 1 && n != 7) board[3][1] = '*';
	if (n != 0 && n != 7) board[3][2] = '*';
	if (n != 1) board[3][3] = '*';
	if (n == 0 || n == 2 || n == 6 || n == 8) board[4][1] = '*';
	if (n == 1) board[4][2] = '*';
	if (n != 1 && n != 2) board[4][3] = '*';
	if (n != 4 && n != 7) board[5][1] = '*';
	if (n != 4 && n != 7) board[5][2] = '*';
	if (1) board[5][3] = '*';
	printf("┌"); for (int i = 0; i <= 5; i++) { printf("─"); }printf("──┐\n");
	for (int i = 1; i <= 5; i++) {
		printf("│  ");
		for (int j = 1; j <= 3; j++)
			printf("%c ", board[i][j]);
		printf("│\n");
	}
	printf("└"); for (int i = 0; i <= 5; i++) { printf("─"); }printf("──┘\n");
	init();
}*/
int board[10][15] = {
	{
		1,1,1,
		1,0,1,
		1,0,1,
		1,0,1,
		1,1,1
	},
	{
		1,1,0,
		0,1,0,
		0,1,0,
		0,1,0,
		1,1,1
	},
	{
		1,1,1,
		0,0,1,
		1,1,1,
		1,0,0,
		1,1,1
	},
	{
		1,1,1,
		0,0,1,
		1,1,1,
		0,0,1,
		1,1,1
	},
	{
		1,0,1,
		1,0,1,
		1,1,1,
		0,0,1,
		0,0,1
	},
	{
		1,1,1,
		1,0,0,
		1,1,1,
		0,0,1,
		1,1,1
	},
	{
		1,1,1,
		1,0,0,
		1,1,1,
		1,0,1,
		1,1,1
	},
	{
		1,1,1,
		0,0,1,
		0,0,1,
		0,0,1,
		0,0,1
	},
	{
		1,1,1,
		1,0,1,
		1,1,1,
		1,0,1,
		1,1,1
	},
	{
		1,1,1,
		1,0,1,
		1,1,1,
		0,0,1,
		1,1,1
	}
};
void printNum(int n) {
	printf("<num:%d>\n", n); printf("\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++)
			if (board[n][(i * 3) + j] == 1)printf("* ");
			else printf("  ");
		printf("\n");
	}printf("\n");
}
/*int main()
{
	int n;
	for (int i=0;i<10;i++)
		printNum(i);
	return 0;
}*/
