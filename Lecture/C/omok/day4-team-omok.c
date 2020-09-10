#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include "day4-team01.c"

char* img[] = { "●","○","┌ ","┬ ","┐ ","├ ","┼ ","┤ ","└ ","┴ ","┘ " };
#define PAN_SIZE 19

void panInit(int stone[][PAN_SIZE])
{
	int i, j;
	for (i = 0; i < PAN_SIZE; i++)
	{
		for (j = 0; j < PAN_SIZE; j++)
		{
			if (i == 0)
			{
				if (j == 0) stone[i][j] = 2;
				else if (j == PAN_SIZE - 1) stone[i][j] = 4;
				else	stone[i][j] = 3;
			}
			else if (i == PAN_SIZE - 1)
			{
				if (j == 0) stone[i][j] = 8;
				else if (j == PAN_SIZE - 1) stone[i][j] = 10;
				else	stone[i][j] = 9;
			}
			else
			{
				if (j == 0) stone[i][j] = 5;
				else if (j == PAN_SIZE - 1) stone[i][j] = 7;
				else	stone[i][j] = 6;
			}
		}

	}
}

void panDisplay(int stone[][PAN_SIZE])
{
	int i, j;
	printf("  ");
	for (j = 0; j < PAN_SIZE; j++)
	{
		printf("%2d", j);
	}
	printf("\n");

	for (i = 0; i < PAN_SIZE; i++)
	{
		printf("%2d", i);
		for (j = 0; j < PAN_SIZE; j++)
		{
			printf("%s", img[stone[i][j]]);
		}
		printf("\n");
	}
}
int setPosition(int field[][PAN_SIZE], int stone, int x, int y)
{
	if (y > (PAN_SIZE - 1) || y < 0 || 
		x > (PAN_SIZE - 1) || x < 0 || 
		field[y][x] == 0 || field[y][x] == 1) 
	{
		printf("%s 잘못된 위치입니다.\n", (stone == 0) ? "Black" : "White");
		return 1;
	}
	else {
		field[y][x] = stone;
	}
	return 0;
}

int judge(int stone[][PAN_SIZE], int player, int px, int py)
{
	int i;
	int count;

	if (player == np) {
		nx = px; ny = py;
	}
	else if (player == mp) {
		mx = px; my = py;
	}
	count = 0;
	for (i = 0; i < PAN_SIZE; i++)
	{	// 수평
		if (stone[py][i] == player)
		{
			count++;
			if (count > 4)	return 1;
		}
		else if (count)	count = 0;
	}
	count = 0;
	for (i = 0; i < PAN_SIZE; i++)
	{	// 수직
		if (stone[i][px] == player)
		{
			count++;
			if (count > 4)	return 1;
		}
		else if (count)	count = 0;
	}
	count = 0;
	int b;
	int y;
	b = py - px;
	for (i = 0; i < PAN_SIZE ; i++)
	{	
		y = i + b;
		if (( y >= 0 && y < PAN_SIZE) && stone[y][i] == player)
		{
			count++;
			if (count > 4)	return 1;
		}
		else if (count)	count = 0;
	}
	count = 0;
	b = py + px;
	for (i = 0; i < PAN_SIZE; i++)
	{
		y = i + b;
		if ((y >= 0 && y < PAN_SIZE) && stone[y][i] == player)
		{
			count++;
			if (count > 4)	return 1;
		}
		else if (count)	count = 0;
	}
	count = 0;
	return 0;
}
int judgedred(int array[][PAN_SIZE], int size, int player)
{
	int i, j;
	int count = 0;
	int k;

	k = player;

	for (i = 0; i < PAN_SIZE - 5; i++)
	{
		for (j = 0; j < PAN_SIZE; j++)
		{
			if (array[i][j] == k && array[i + 1][j + 1] == k && array[i + 2][j + 2] == k && array[i + 3][j + 3] == k && array[i + 4][j + 4] == k)
				return 1;
			else if (array[i][j] == k && array[i - 1][j + 1] == k && array[i - 2][j + 2] == k && array[i - 3][j + 3] == k && array[i - 4][j + 4] == k)
				return 1;
			else if (array[i][j] == k && array[i - 1][j + 1] == k && array[i - 2][j + 2] == k && array[i - 3][j + 3] == k && array[i - 4][j + 4] == k)
				return 1;
			else if (array[i][j] == k && array[i][j + 1] == k && array[i][j + 2] == k && array[i][j + 3] == k && array[i][j + 4] == k)
				return 1;
			else if (array[i][j] == k && array[i + 1][j] == k && array[i + 2][j] == k && array[i + 3][j] == k && array[i + 4][j] == k)
				return 1;
		}
	}
	return 0;
}
int copyArray(int dummy[][PAN_SIZE], int pan[][PAN_SIZE]) {
	for (int i = 0; i < PAN_SIZE; ++i) {
		for (int k = 0; k < PAN_SIZE; ++k) {
			dummy[i][k] = pan[i][k];
		}
	}
	return 0;
}


int team01(int pan[][PAN_SIZE], int* px, int* py);
int team02(int pan[][PAN_SIZE], int* px, int* py);
int team03(int pan[][PAN_SIZE], int* px, int* py);
int team04(int pan[][PAN_SIZE], int* px, int* py);

int gameOn(
	int (*black)(int[][PAN_SIZE], int*, int*),
	int (*white)(int[][PAN_SIZE], int*, int*)
)
{
	int player = 0, x = 0, y = 0;
	int pan[PAN_SIZE][PAN_SIZE] = { 0 };
	int dummy[PAN_SIZE][PAN_SIZE] = { 0 };
	int stoneCount = 0;
	int replay;
	
	// x = -1 게임이 시작된다.
	// y = -1 흑돌(0), 0 백돌(1)
	x = -1, y = -1;
	black(dummy, &x, &y);
	x = -1, y = 0;
	white(dummy, &x, &y);
	x = 0, y = 0;

	panInit(pan);
	// 게임 시작
	while (1)
	{
		system("cls");
		// 오목판 출력
		panDisplay(pan);
		copyArray(dummy, pan);
		do {
			replay = 0;
			// 플레이어 함수 호출
			if (player == 0){ black(dummy, &x, &y);		}
			if (player == 1){ white(dummy, &x, &y);		}
			if (x < 0 || y < 0 || x >= PAN_SIZE || y >= PAN_SIZE) {
				replay = 1;
				printf("%s wrong position\n", (player)?"WHITE":"BLACK");
			}
		} while (replay);

		// 오목돌 저장
		if (setPosition(pan, player, x, y))
		{
			printf("놓을 수 없는 자리입니다.\n");
		}
		else
		{
			// 승패판정
			if (judge(pan, player, x, y))
			{
				system("cls");
				panDisplay(pan);
				printf("%s@{y:%d,x:%d} Win!!!!!!!\n", 
					(player)?"WHITE":"BLACK",y,x);
				break;
			}
			// 플레이어 변경
			player ^= 1;
			stoneCount++;
			if (stoneCount >= (PAN_SIZE * PAN_SIZE))
			{
				system("cls");
				panDisplay(pan);
				printf("더이상 돌을 놓을 자리가 없습니다.\n무승부입니다.");
				player = EOF;
				break;
			}
		}
	}
	return player;
}

int main(int argc, char** argv) {
	int (*play[])(int[][PAN_SIZE], int*, int*) =
	{ team01,team02,team03,team04 };
	int score[4][4] = { 0 };
	for (int bl = 0; bl < 4; ++bl) {
		for (int wh = 0; wh < 4; ++wh) {
			if (bl != wh) {
				int winner = gameOn(play[bl], play[wh]);
				printf("\n\t%d team and %d team\n", bl + 1, wh + 1);
				if (winner == EOF) {
					printf("Draw : %d vs %d \n", bl + 1, wh + 1);
				}
				else if (winner == 0) {
					printf("Winner : %d team \n", bl + 1);
					score[bl][wh] += 1;
				}
				else if (winner == 1) {
					printf("Winner : %d team \n", wh + 1);
					score[wh][bl] += 1;
				}
//				getchar();
			}
		}
	}// game

	system("cls");
	printf(" Score Board \n    ");
	for (int i = 1; i <= 4; ++i) {
		printf("%2d\t", i);
	}
	printf("\n");
	for (int i = 0; i < 4; ++i) {
		printf("%2d: ", i + 1);
		for (int k = 0; k < 4; ++k) {
			printf("%2d\t", score[i][k]);
		}
		printf("\n");
	}

}
