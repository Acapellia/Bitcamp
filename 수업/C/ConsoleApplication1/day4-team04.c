#include<stdio.h>
#define PAN_SIZE 19
void setWeightW(int board[21][21], int Cboard[21][21], int check[21][21], char stone, int x, int y, int w) {
	int cnt, tcnt = 0, mw;
	int tx = x, ty = y;
	char stone1, stone2;
	if (stone == 0) {
		stone1 = 0; stone2 = 1;
	}
	else { stone1 = 1; stone2 = 0; }
	cnt = 1; tcnt = 0;
	x = tx; y = ty;
	if (w == -1) mw = 3;
	else mw = 1;
	//가로
	for (int i = x, j = y + 1; j < 20; j++) {
		if (tcnt + cnt > 4) break;
		check[i][j - 1] = 1;
		if (board[x][y] == board[i][j]) {
			cnt++; mw *= 10;// printf("가로 %d\n", cnt);
			if ((cnt + tcnt) == 4) mw *= 10;
			if ((cnt + tcnt) == 3) mw *= 5;
		}
		else {
			// 양쪽다 공백
			if (board[x][y - 1] == -1 && board[i][j] == -1) {
				if (cnt == 1) { Cboard[x][y - 1] += (1 * cnt * mw * w); Cboard[i][j] += (1 * cnt * w); }
				else { Cboard[x][y - 1] += (9 * cnt * mw * w); Cboard[i][j] += (9 * cnt * mw * w); }
			}
			// 한쪽만 공백
			else if (board[x][y - 1] == -1 && board[i][j] != -1) {
				Cboard[x][y - 1] += (1 * cnt * mw * w);
			}
			else if (board[x][y - 1] != -1 && board[i][j] == -1) {
				Cboard[i][j] += (1 * cnt * mw * w);
			}
			// 둘다 막힘
			else if (board[x][y - 1] != -1 && board[i][j] != -1) {
			}
			if (board[i][j] == -1) {
				tcnt = cnt; cnt = 0; x = i; y = j + 1;
				if (board[x][y] == -1 || board[x][y] == stone2) break;
			}
			else break;
		}
	}
}
void setWeightH(int board[21][21], int Cboard[21][21], int check[21][21], char stone, int x, int y, int w) {
	int cnt, tcnt = 0, mw;
	int tx = x, ty = y;
	char stone1, stone2;
	if (stone == 0) {
		stone1 = 0; stone2 = -1;
	}
	else { stone1 = -1; stone2 = 0; }
	//세로
	cnt = 1; tcnt = 0;
	x = tx; y = ty;
	if (w == -1) mw = 3;
	else mw = 1;
	for (int i = x + 1, j = y; i < 20; i++) {
		if (tcnt + cnt > 4) break;
		check[i - 1][j] = 1;
		if (board[x][y] == board[i][j]) {
			cnt++; mw *= 10; //printf("세로 %d\n", cnt);
			if ((cnt + tcnt) == 4) mw *= 10;
			if ((cnt + tcnt) == 3) mw *= 5;
		}
		else {
			// 양쪽다 공백
			if (board[x - 1][y] == -1 && board[i][j] == -1) {
				if (cnt == 1) { Cboard[x - 1][y] += (1 * cnt * mw * w); Cboard[i][j] += (1 * cnt * mw * w); }
				else { Cboard[x - 1][y] += (9 * cnt * mw * w); Cboard[i][j] += (9 * cnt * mw * w); }
			}
			// 한쪽만 공백
			else if (board[x - 1][y] == -1 && board[i][j] != -1) {
				Cboard[x - 1][y] += (1 * cnt * mw * w);
			}
			else if (board[x - 1][y] != -1 && board[i][j] == -1) {
				Cboard[i][j] += (1 * cnt * mw * w);
			}
			// 둘다 막힘
			else if (board[x - 1][y] != -0 && board[i][j] != -1) {
			}
			if (board[i][j] == -1) {
				tcnt = cnt; cnt = 0; x = i + 1; y = j;
				if (board[x][y] == -1 || board[x][y] == stone2) break;
			}
			else break;
		}
	}
}
void setWeightDL(int board[21][21], int Cboard[21][21], int check[21][21], char stone, int x, int y, int w) {
	int cnt, tcnt = 0, mw;
	int tx = x, ty = y;
	char stone1, stone2;
	if (stone == 0) {
		stone1 = 0; stone2 = 1;
	}
	else { stone1 = 1; stone2 = 0; }
	// 대각 /
	cnt = 1; tcnt = 0;
	x = tx; y = ty;
	if (w == -1) mw = 3;
	else mw = 1;
	for (int i = x + 1, j = y - 1; i < 20; i++, j--) {
		if (tcnt + cnt > 4) break;
		check[i - 1][j + 1] = 1;
		if (board[x][y] == board[i][j]) {
			cnt++; mw *= 10; //printf("대각\/ %d\n", cnt);
			if ((cnt + tcnt) == 4) mw *= 10;
			if ((cnt + tcnt) == 3) mw *= 5;
		}
		else {
			// 양쪽다 공백
			if (board[x - 1][y + 1] == -1 && board[i][j] == -1) {
				if (cnt == 1) { Cboard[x - 1][y + 1] += (1 * cnt * mw * w); Cboard[i][j] += (1 * cnt * w); }
				else { Cboard[x - 1][y + 1] += (9 * cnt * mw * w); Cboard[i][j] += (9 * cnt * mw * w); }
			}
			// 한쪽만 공백
			else if (board[x - 1][y + 1] == -1 && board[i][j] != -1) {
				Cboard[x - 1][y + 1] += (1 * cnt * mw * w);
			}
			else if (board[x - 1][y + 1] != -1 && board[i][j] == -1) {
				Cboard[i][j] += (1 * cnt * mw * w);
			}
			// 둘다 막힘
			else if (board[x - 1][y + 1] != -1 && board[i][j] != -1) {
			}
			if (board[i][j] == -1) {
				tcnt = cnt; cnt = 0; x = i + 1; y = j - 1;
				if (board[x][y] == -1 || board[x][y] == stone2) break;
			}
			else break;
		}
	}
}
void setWeightDR(int board[21][21], int Cboard[21][21], int check[21][21], char stone, int x, int y, int w) {
	int cnt, tcnt = 0, mw;
	int tx = x, ty = y;
	char stone1, stone2;
	if (stone == 0) {
		stone1 = 0; stone2 = 1;
	}
	else { stone1 = 1; stone2 = 0; }
	// 대각 '\'
	cnt = 1; tcnt = 0;
	x = tx; y = ty;
	if (w == -1) mw = 3;
	else mw = 1;
	for (int i = x + 1, j = y + 1; i < 20; i++, j++) {
		if (tcnt + cnt > 4) break;
		check[i - 1][j - 1] = 1;
		if (board[x][y] == board[i][j]) {
			cnt++; mw *= 10; //printf("대각\\ %d\n", cnt);
			if ((cnt + tcnt) == 4) mw *= 10;
			if ((cnt + tcnt) == 3) mw *= 5;
		}
		else {
			// 양쪽다 공백
			if (board[x - 1][y - 1] == -1 && board[i][j] == -1) {
				if (cnt == 1) { Cboard[x - 1][y - 1] += (1 * cnt * mw * w); Cboard[i][j] += (1 * cnt * mw * w); }
				else { Cboard[x - 1][y - 1] += (9 * cnt * mw * w); Cboard[i][j] += (9 * cnt * mw * w); }
			}
			// 한쪽만 공백
			else if (board[x - 1][y - 1] == -1 && board[i][j] != -1) {
				Cboard[x - 1][y - 1] += (1 * cnt * mw * w);
			}
			else if (board[x - 1][y - 1] != -1 && board[i][j] == -1) {
				Cboard[i][j] += (1 * cnt * mw * w);
			}
			// 둘다 막힘
			else if (board[x - 1][y - 1] != -1 && board[i][j] != -1) {
			}
			if (board[i][j] == -1) {
				tcnt = cnt; cnt = 0; x = i + 1; y = j + 1;
				if (board[x][y] == -1 || board[x][y] == stone2) break;
			}
			else break;
		}
	}
}
void maxValue(int board[21][21], int s, int point[4]) {
	int Cboard[21][21] = { 0 };
	int check1[21][21] = { 0 };
	int check2[21][21] = { 0 };
	int check3[21][21] = { 0 };
	int check4[21][21] = { 0 };
	char myStone, yourStone;
	if (s == 0) {
		myStone = 0; yourStone = 1;
	}
	else { myStone = 1; yourStone = 0; }
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == myStone && check1[i][j] != 1) {
				setWeightW(board, Cboard, check1, yourStone, i, j, 1);
			}
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == myStone && check2[i][j] != 1) {
				setWeightH(board, Cboard, check2, yourStone, i, j, 1);
			}
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == myStone && check3[i][j] != 1) {
				setWeightDL(board, Cboard, check3, yourStone, i, j, 1);
			}
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == myStone && check4[i][j] != 1) {
				setWeightDR(board, Cboard, check4, yourStone, i, j, 1);
			}
		}
	}
	int stone[4] = { 0 };
	stone[0] = 10; stone[1] = 10; stone[2] = 0; stone[3] = 1;
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (Cboard[i][j] > stone[2]) {
				stone[0] = i; stone[1] = j; stone[2] = Cboard[i][j]; stone[3] = 1;
			}
			else if (Cboard[i][j] == stone[2]) {
				if (rand() % 2 == 0) { continue; }
				stone[0] = i; stone[1] = j; stone[2] = Cboard[i][j]; stone[3] = yourStone;
			}
		}
	}
	if (stone[2] == 0) { stone[0] = 10; stone[1] = 10; stone[2] = 0; stone[3] = 1; }
	point[0] = stone[0]; point[1] = stone[1]; point[2] = stone[2]; point[3] = stone[3];
	//show_board(Cboard);
}
void minValue(int board[21][21], int s, int point[4]) {
	int Cboard[21][21] = { 0 };
	int check1[21][21] = { 0 };
	int check2[21][21] = { 0 };
	int check3[21][21] = { 0 };
	int check4[21][21] = { 0 };
	char myStone, yourStone;
	if (s == 0) {
		myStone = 1; yourStone = 0;
	}
	else { myStone = 0; yourStone = 1; }

	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == yourStone && check1[i][j] != 1) {
				setWeightW(board, Cboard, check1, yourStone, i, j, -1);
			}
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == yourStone && check2[i][j] != 1) {
				setWeightH(board, Cboard, check2, yourStone, i, j, -1);
			}
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == yourStone && check3[i][j] != 1) {
				setWeightDL(board, Cboard, check3, yourStone, i, j, -1);
			}
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == yourStone && check4[i][j] != 1) {
				setWeightDR(board, Cboard, check4, yourStone, i, j, -1);
			}
		}
	}
	int stone[4] = { 0 };
	stone[0] = 10; stone[1] = 10; stone[2] = 99999; stone[3] = yourStone;
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (Cboard[i][j] < stone[2]) {
				stone[0] = i; stone[1] = j; stone[2] = Cboard[i][j]; stone[3] = yourStone;
			}
			else if (Cboard[i][j] == stone[2]) {
				if (rand() % 2 == 0) { continue; }
				stone[0] = i; stone[1] = j; stone[2] = Cboard[i][j]; stone[3] = yourStone;
			}
		}
	}
	//printf("Cboard\n");
	//show_board(Cboard);
	if (stone[2] == 0) { stone[0] = 10; stone[1] = 10; stone[2] = 0; stone[3] = 1; }
	point[0] = stone[0]; point[1] = stone[1]; point[2] = stone[2]; point[3] = stone[3];
}
void copyBoard(int board[21][21], int pan[][PAN_SIZE]) {
	for (int i = 0; i < 21; i++) { board[i][0] = 9; board[i][20] = 9; board[0][i] = 9; board[20][i] = 9; }
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (pan[i][j] == 0) board[i + 1][j + 1] = 0;
			else if (pan[i][j] ==1) board[i + 1][j + 1] = 1;
			else board[i + 1][j + 1] = -1;
		}
	}
}
void omokAI(int pan[PAN_SIZE][PAN_SIZE], int s, int point[2]) {
	int board[21][21] = {0};
	copyBoard(board, pan);
	int myStone, yourStone;
	int max[4] = { 0 };
	int min[4] = { 0 };
	if (s == 0) {
		myStone = 0; yourStone = 1;
	}
	else { myStone = 1; yourStone = 0; }
	maxValue(board, myStone, max);
	//printf("max %d %d %d %d\n", max[0], max[1], max[2], max[3]);
	minValue(board, yourStone, min);
	//printf("min %d %d %d %d\n", min[0], min[1], min[2], min[3]);
	if (max[2] > min[2] * (-1)) {
		point[0] = max[0];
		point[1] = max[1];
	}
	else {
		point[0] = min[0];
		point[1] = min[1];
	}

}
// x : 게임시작 y : 본인의 돌
// -1 -1 -> 0 : 흑돌
// -1  0 -> 1 : 백돌
int team04(int pan[][PAN_SIZE], int* px, int* py)
{
	int point[2] = { 0 };
	static int stone;

	if (*px == -1) {
		if (*py == -1) { stone = -1; }
		else if (*py == 0) { stone = 0; }
	}
	if (stone == -1) omokAI(pan, 0, point);
	else if (stone == 0) omokAI(pan, 1, point);

	srand((unsigned int)time(NULL));
	//printf("AI4 %d %d\n", point[0]-1, point[1]-1);
	
	*px = point[1]-1;
	*py = point[0]-1;
	
	return 0;
}
