#include "turboc.h"

#define col 50
#define row 25
#define JumpH 3
#define JumpT 10

int Absolute_coordinates[row][col * 2] = { 0 };

void ready()
{
	for (int rowW = 0; rowW < row; rowW++) // 0~25 +1 = 26
	{
		for (int colW = 0; colW < col; colW++)
		{
			Absolute_coordinates[0][colW] = -1;
			gotoxy(colW, 0);
			puts("��");
			Absolute_coordinates[row - 1][colW] = -1;
			gotoxy(colW, row);
			puts("��");;
		}
		Absolute_coordinates[rowW][0] = -1;
		gotoxy(0, rowW);
		puts("��");
		Absolute_coordinates[rowW][col - 1] = -1;
		gotoxy(col * 2 - 2, rowW); // Ư�����ڴ� " " 2���� ������ ����. �׷��Ƿ� ���� ǥ���Ϸ��� // ǥ���ϰ� ���� ���� *2�� �ϰ�// 0���� �����ϴ� ���� ����� -2(Ư������1���� ���� ���ش�)
		puts("��");
	}
	gotoxy(2, 24);
	puts("��");
}

/*void usermove(int* x, int* y, int* jump)
{
	setcursortype(NOCURSOR);

	if (_kbhit())
	{
		char ch = _getch();
		if (ch == '\r')
		{
			exit(0);
		}
		else if (ch == 'a' || ch == 'A') // �������� �̵�
		{
			if (*x - 2 == 0)
			{

			}
			else
			{
				Absolute_coordinates[*y][*x] = 0;
				gotoxy(*x, *y);
				printf("  ");
				*x -= 1;
				Absolute_coordinates[*y][*x] = 9;
				gotoxy(*x, *y);
				printf("��");
			}
		}
		else if (ch == 'd' || ch == 'D') // ���������� �̵�
		{
			if (*x + 2 == col * 2 - 2)
			{

			}
			else
			{
				Absolute_coordinates[*y][*x] = 0;
				gotoxy(*x, *y);
				printf("  ");
				*x += 1;
				Absolute_coordinates[*y][*x] = 9;
				gotoxy(*x, *y);
				printf("��");
			}
		}
		else if (ch == '5') // ���� Ű
		{
			if (*jump == 0)
			{

				Absolute_coordinates[*y][*x] = 0;
				gotoxy(*x, *y);
				printf("  ");
				*y -= 2;
				Absolute_coordinates[*y][*x] = 9;
				gotoxy(*x, *y);
				printf("��");

				*jump = 2;
			}
		}
	}
}*/
void usermove(int* x, int* y, int* jump) {
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		if (*jump == 0)
		{
			Absolute_coordinates[*y][*x] = 0;
			gotoxy(*x, *y);
			printf("  ");
			*y -= JumpH;
			Absolute_coordinates[*y][*x] = 9;
			gotoxy(*x, *y);
			printf("��");

			*jump = JumpH;
		}
	}
	/*if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		if (newY < HEIGHT + 1) newY++;
	}*/
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		if (*x - 2 == 0)
		{

		}
		else
		{
			Absolute_coordinates[*y][*x] = 0;
			gotoxy(*x, *y);
			printf("  ");
			*x -= 1;
			Absolute_coordinates[*y][*x] = 9;
			gotoxy(*x, *y);
			printf("��");
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		if (*x + 2 == col * 2 - 2)
		{

		}
		else
		{
			Absolute_coordinates[*y][*x] = 0;
			gotoxy(*x, *y);
			printf("  ");
			*x += 1;
			Absolute_coordinates[*y][*x] = 9;
			gotoxy(*x, *y);
			printf("��");
		}
	}
}
void userjump(int* x, int* y, int* jump)
{
	if(*jump==JumpH) delay(20);

	Absolute_coordinates[*y][*x] = 0;
	gotoxy(*x, *y);
	printf("  ");
	*y += 1;
	Absolute_coordinates[*y][*x] = 9;
	gotoxy(*x, *y);
	printf("��");

	(*jump)--;
	if(*jump==0) delay(20);
}

void main()
{
	setcursortype(NOCURSOR);
	int x = 24, y = 2; // x�� y(��), y�� x(��) �߸� ������.
	int jump = 0;
	int moveCnt=0,jumpCnt = 0;
	ready();

	while (1)
	{
		if(moveCnt++%2==0)
			usermove(&y, &x, &jump);
		if (jump > 0 && jumpCnt % JumpT == 0)
		{
			userjump(&y, &x, &jump);
			if (jump == 0) jumpCnt = 0;
		}
		jumpCnt++;
		delay(10);
	}
}