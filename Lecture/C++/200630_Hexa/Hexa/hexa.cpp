#include "Turboc.h"
#include <iostream>
using namespace std;
// keyboard 입력
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

// 난이도 조절 및 종료키
#define PGUP 73
#define PGDN 81
#define ESC 27

// 생성위치
#define BX 5
#define BY 1

// 게임 스크린
#define BW 10
#define BH 20

// define global
void DrawScreen();
void DrawBoard();

BOOL ProcessKey();
void PrintBrick(BOOL Show);
int GetAround(int x, int y);

BOOL MoveDown();
void TestFull();
void DrawNext();

void PrintInfo();
void MakeNewBrick();
//main();

enum { EMPTY, B1, B2, B3, B4, B5, B6, B7, B8, B9, B10, WALL };
char* arTile[] = { ". ","■","●","★","♣","☎","◆","♠","♥","♨","♬","□" };
int board[BW + 2][BH + 2];
int nx, ny;
int brick[3];
int nbrick[3];
int score;
int bricknum;
int level;

void main()
{
	int nFrame, nStay;
	int x, y;

	setcursortype(NOCURSOR);
	randomize();
	level = 3;

	for (; ;) {
		clrscr();
		// 벽과 빈공간 생성 -> 보드 초기화
		for (x = 0; x < BW + 2; x++) {
			for (y = 0; y < BH + 2; y++) {
				board[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY;
			}
		}
		DrawScreen();
		nFrame = 20;	
		score = 0;
		bricknum = 0;
		//처음 떨어질 벽돌
		MakeNewBrick();
		for (; ;) {
			bricknum++;
			// nbrick에 make를 하므로  brick(현재)로 복사해줌
			memcpy(brick, nbrick, sizeof(brick));
			// 다음에 떨어질 벽돌 만들기
			MakeNewBrick();
			// main 화면 옆에 있는 화면 그리기
			DrawNext();
			// 벽돌 생성위치
			nx = BW / 2;
			ny = 3;
			// 현재 떨어지는 벽돌 계속 그려주기
			PrintBrick(TRUE);
			//생성위치까지 블럭이 차 있으면 게임 오버
			if (GetAround(nx, ny) != EMPTY) break;
			
			nStay = nFrame;
			for (; ;) {
				//gotoxy(0, 0);
				//printf("stay %2d frame %2d brick %2d", nStay, nFrame, bricknum); delay(100);
				// stay가 계속 줄어 들다가 frame(일정시간)과 같아지면 한칸 내려옴
				if (--nStay == 0) {
					nStay = nFrame;
					if (MoveDown()) break; // 블럭이 천천히 내려옴
				}
				if (ProcessKey()) break; // 플레이어 키 입력
				//PrintInfo();
				delay(1000 / 20); // 키 입력이 너무 빠르지 않게 딜레이
			}

			// 벽돌이 10개 생성될 때마다 frame이 1씩 줄어
			// 벽돌이 머무는 시간이 줄어듬 (난이도 느낌)
			if (bricknum % 10 == 0 && nFrame > 5) {
				nFrame--;
			}
		}
		clrscr();
		gotoxy(30, 12); puts("G A M E  O V E R");
		gotoxy(25, 14); puts("다시 시작하려면 Y를 누르세요");
		if (tolower(getch()) != 'y') break;
	}
	setcursortype(NORMALCURSOR);
}

// 스크린 그리기
void DrawScreen()
{
	int x, y;

	// 게임 메인 스크린
	for (x = 0; x < BW + 2; x++) {
		for (y = 0; y < BH + 2; y++) {
			gotoxy(BX + x * 2, BY + y);
			puts(arTile[board[x][y]]);
		}
	}
	/*for (x = 0; x < BW + 2; x++) {
		for (y = 0; y < BH + 2; y++) {
			gotoxy(80+x*3, y);
			printf(" %2d ",board[x][y]);
		}printf("\n");
	}*/
	gotoxy(50, 3); puts("Hexa Ver 1.0");
	gotoxy(50, 5); puts("좌우:이동, 위:회전, 아래:내림");
	gotoxy(50, 6); puts("공백:전부 내림, ESC:종료");
	gotoxy(50, 7); puts("P:정지,PgUp,PgDn:난이도 조절");
	DrawNext();
	PrintInfo();
}
// board 전체 그리기
void DrawBoard()
{
	int x, y;

	for (x = 1; x < BW + 1; x++) {
		for (y = 1; y < BH + 1; y++) {
			gotoxy(BX + x * 2, BY + y);
			puts(arTile[board[x][y]]);
		}
	}
}
// 키보드 입력 처리
BOOL ProcessKey()
{
	int ch;
	int t;

	if (kbhit()) {
		ch = getch();
		if (ch == 0xE0 || ch == 0) {
			ch = getch();
			switch (ch) {
			case LEFT:
				if (GetAround(nx - 1, ny) == EMPTY) {
					PrintBrick(FALSE);
					nx--;
					PrintBrick(TRUE);
				}
				break;
			case RIGHT:
				if (GetAround(nx + 1, ny) == EMPTY) {
					PrintBrick(FALSE);
					nx++;
					PrintBrick(TRUE);
				}
				break;
			case UP:
				PrintBrick(FALSE);
				t = brick[0];
				brick[0] = brick[1];
				brick[1] = brick[2];
				brick[2] = t;
				PrintBrick(TRUE);
				break;
			case DOWN:
				if (MoveDown()) {
					return TRUE;
				}
				break;
			case PGDN:
				if (level > 2) {
					level--;
					PrintInfo();
				}
				break;
			case PGUP:
				if (level < 10) {
					level++;
					PrintInfo();
				}
				break;
			}
		}
		else {
			switch (tolower(ch)) {
			case ' ':
				while (MoveDown() == FALSE) { ; }
				return TRUE;
			case ESC:
				exit(0);
			case 'p':
				clrscr();
				gotoxy(15, 10);
				puts("Tetris 잠시 중지. 다시 시작하려면 아무 키나 누르세요.");
				getch();
				clrscr();
				DrawScreen();
				PrintBrick(TRUE);
				break;
			}
		}
	}
	return FALSE;
}
// 벽돌 출력
void PrintBrick(BOOL Show)
{
	int i;
	// Show(True - 벽돌그리기 False - 빈칸)
	for (i = 0; i < 3; i++) {
		gotoxy(BX + nx * 2, BY + ny + i);
		puts(arTile[Show ? brick[i] : EMPTY]);
	}
}
// 주위에 벽돌이 있는지 체크
int GetAround(int x, int y)
{
	int i, k = EMPTY;

	for (i = 0; i < 3; i++) {
		k = max(k, board[x][y + i]);
	}
	return k;
}
// 밑으로 한칸씩 내려옴
BOOL MoveDown()
{
	if (GetAround(nx, ny + 1) != EMPTY) {
		TestFull();
		return TRUE;
	}
	PrintBrick(FALSE);
	ny++;
	PrintBrick(TRUE);
	return FALSE;
}

void TestFull()
{
	int i, x, y;
	int t, ty;
	BOOL Remove;
	static int arScoreInc[] = { 0,1,3,7,15,30,100,500 };
	int count = 0;
	BOOL Mark[BW + 2][BH + 2];

	// 배열에 기록
	for (i = 0; i < 3; i++) {
		board[nx][ny + i] = brick[i];
	}

	for (;;) {
		// 연속 무늬 점검
		memset(Mark, 0, sizeof(Mark));
		Remove = FALSE;
		for (y = 1; y < BH + 1; y++) {
			for (x = 1; x < BW + 1; x++) {
				t = board[x][y];
				if (t == EMPTY) continue;

				// 수평
				if (board[x - 1][y] == t && board[x + 1][y] == t) {
					for (i = -1; i <= 1; i++) Mark[x + i][y] = TRUE;
					Remove = TRUE;
				}
				// 수직
				if (board[x][y - 1] == t && board[x][y + 1] == t) {
					for (i = -1; i <= 1; i++) Mark[x][y + i] = TRUE;
					Remove = TRUE;
				}
				// 우하향
				if (board[x - 1][y - 1] == t && board[x + 1][y + 1] == t) {
					for (i = -1; i <= 1; i++) Mark[x + i][y + i] = TRUE;
					Remove = TRUE;
				}
				// 좌하향
				if (board[x + 1][y - 1] == t && board[x - 1][y + 1] == t) {
					for (i = -1; i <= 1; i++) Mark[x - i][y + i] = TRUE;
					Remove = TRUE;
				}
			}
		}

		if (Remove == FALSE) return;

		// 제거 애니메이션
		// 깜빡임
		for (i = 0; i < 6; i++) {
			for (y = 1; y < BH + 1; y++) {
				for (x = 1; x < BW + 1; x++) {
					if (board[x][y] != EMPTY && Mark[x][y] == TRUE) {
						gotoxy(BX + x * 2, BY + y);
						puts(arTile[i % 2 ? EMPTY : board[x][y]]);
					}
				}
			}
			delay(150);
		}

		// 삭제된 무늬 위쪽에 있는것들을 모두 한칸씩 내림
		for (y = 1; y < BH + 1; y++) {
			for (x = 1; x < BW + 1; x++) {
				if (board[x][y] != EMPTY && Mark[x][y] == TRUE) {
					for (ty = y; ty > 1; ty--) {
						//gotoxy(22+(x*7), 80+ty);
						//printf("%d %d %d\n", x, ty, ty - 1);
						board[x][ty] = board[x][ty - 1];
					}
					board[x][1] = EMPTY; //- 무쓸모(도대체 왜 있는지 모르겠음...)
					count++;
				}
			}
		}
		// 연속된 무늬 삭제 후 다시 그림
		DrawBoard();
		score += arScoreInc[min(count / 3, 7)];
		PrintInfo();
	}
}
// 옆에 게임 정보창 및 다음 벽돌
void DrawNext()
{
	int x, y, i;
	// 옆 게임창 벽
	for (x = 50; x <= 70; x += 2) {
		for (y = 12; y <= 18; y++) {
			gotoxy(x, y);
			puts(arTile[(x == 50 || x == 70 || y == 12 || y == 18) ? WALL : EMPTY]);
		}
	}

	// 다음 벽돌
	for (i = 0; i < 3; i++) {
		gotoxy(60, 14 + i);
		puts(arTile[nbrick[i]]);
	}
}

// 게임화면 오른쪽 정보칸
void PrintInfo()
{
	gotoxy(50, 9); printf("난이도 : %d  ", level);
	gotoxy(50, 10); printf("점수 : %d     ", score);
	gotoxy(50, 11); printf("벽돌 : %d 개  ", bricknum);
}
// 새로운 벽돌을 만드는데 level만큼의 벽돌 종류 중에 랜덤하게 만듬
// 3개의 벽돌이 모두 같으면 다시 만듬
void MakeNewBrick()
{
	int i;

	do {
		for (i = 0; i < 3; i++) {
			nbrick[i] = random(level) + 1;
		}
	} while (nbrick[0] == nbrick[1] && nbrick[1] == nbrick[2] && nbrick[0] == nbrick[2]);
}

