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
void moveSharp() { //3��
	
	while (1) { // ����(1000��) �ݺ�
		
	}
}
void main()
{
	setcursortype(NOCURSOR);
	int frameCnt=0, ballCnt=3, barCnt = 1;

	// bar variable
	char* bar = "�âââ�";
	int preX, preY, newX, newY;
	preX = newX = WIDTH / 2 - strlen(bar) / 2;
	preY = newY = HEIGHT / 5 * 4;

	// move sharp variable
	int xc = 1, yc = 1; // �̵��� ����
	//xc -> 1: ������ -1 : ����  yc -> 1 : �Ʒ��� -1 : ����
	int x = 0, y = 0;// �����̴� #�� ��ǥ
	//int cnt = 0; // ������ �ٲ� Ƚ��
	int h = HEIGHT+1, w = WIDTH+1; // ���� ���� ���� ���� 0-23 �ʺ� 0-53

	// draw wall
	drawXLine(0, WIDTH / 2 + 1, HEIGHT + 2, "��");
	drawYLine(0, HEIGHT + 2, WIDTH + 2, "��");
	// draw bar
	drawBar(newX, newY, bar);

	// loop
	while (TRUE)
	{
		if (frameCnt % ballCnt == 0) {
			// move sharp
			if (0 <= x + xc && x + xc <= w && 0 <= y + yc && y + yc <= h) { // �� ���⿡�� ���� ���������� �̵�
				gotoxy(x, y);
				printf(" ");
				x += xc; y += yc; // ��ǥ �̵�
				gotoxy(x, y);
				printf("#");

			}
			// ���� ������ �� ���� ���� ����
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