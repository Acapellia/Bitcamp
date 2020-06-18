#include "turboc.h"

#define WIDTH	80
#define HEIGHT	25

#define TRUE	1
#define FALSE	0

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77


void drawXLine(int sX, int eX, int yPos, const char* icon)
{
	int x = 0;
	for (x = sX; x <= eX; x++)
	{
		gotoxy(x, yPos);
		puts(icon);
	}
}

void drawYLine(int sY, int eY, int xPos, const char* icon)
{
	int y = 0;
	for (y = sY; y <= eY; y++)
	{
		gotoxy(xPos, y);
		puts(icon);
	}
}
void drawBar(int x, int y, char* bar)
{
	gotoxy(x, y);
	puts(bar);
}
void moveSharp() { //3번
	
	while (1) { // 무한(1000번) 반복
		
	}
}
void main()
{
	setcursortype(NOCURSOR);
	int frameCnt=0, ballCnt=3, barCnt = 1;

	// bar variable
	char* bar = "▣▣▣▣";
	int preX, preY, newX, newY;
	preX = newX = WIDTH / 2 - strlen(bar) / 2;
	preY = newY = HEIGHT / 5 * 4;

	// move sharp variable
	int xc = 1, yc = 1; // 이동할 방향
	//xc -> 1: 오른쪽 -1 : 왼쪽  yc -> 1 : 아래쪽 -1 : 위쪽
	int x = 0, y = 0;// 움직이는 #의 좌표
	//int cnt = 0; // 방향을 바꿀 횟수
	int h = HEIGHT+1, w = WIDTH+1; // 벽을 위한 변수 높이 0-23 너비 0-53

	// draw wall
	drawXLine(0, WIDTH / 2 + 1, HEIGHT + 2, "▥");
	drawYLine(0, HEIGHT + 2, WIDTH + 2, "▤");
	// draw bar
	drawBar(newX, newY, bar);

	// loop
	while (TRUE)
	{
		if (frameCnt % ballCnt == 0) {
			// move sharp
			if (0 <= x + xc && x + xc <= w && 0 <= y + yc && y + yc <= h) { // 각 방향에서 벽을 만날때까지 이동
				gotoxy(x, y);
				printf(" ");
				x += xc; y += yc; // 좌표 이동
				gotoxy(x, y);
				printf("#");

			}
			// 벽을 만났을 때 다음 방향 설정
			if ((x == 0 || x == w) && (y == 0 || y == h)) { xc *= -1; yc *= -1; }
			else if (x == 0 || x == w) { xc *= -1; }
			else if (y == 0 || y == h || ((newY-1<= y &&y <= newY+1) && (newX <= x && x <= newX + 7))) { yc *= -1; }
		}
		if (frameCnt % barCnt == 0) {
			// move bar
			preX = newX;
			preY = newY;

			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				if (newY > 0) newY--;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (newY < HEIGHT + 1) newY++;
			}
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
				if (newX > 0) newX--;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
				if (newX < WIDTH - 6) newX++;
			}
			if (preX != newX || preY != newY) {
				drawBar(preX, preY, "        ");
				drawBar(newX, newY, bar);
			}
		}
		frameCnt++;
		delay(20);
	}
}