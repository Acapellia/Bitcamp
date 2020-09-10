#include <stdio.h>
#include "turboc.h"
void draw_wall(int e, int w, int s, char* icon) {
	for (int i = 0; i <= e; i++) {
		if (s == 0) { 
			if (i % 2 == 1) continue;
			gotoxy(i, 0); printf("%s", icon); gotoxy(i, w); printf("%s", icon);
		}
		if (s == 1) { 
			gotoxy(0, i); printf("%s", icon); gotoxy(w, i); printf("%s", icon);
		}
	}
}
void print3() { //3��
	int xc = 1, yc = 1; // �̵��� ����
	//xc -> 1: ������ -1 : ����  yc -> 1 : �Ʒ��� -1 : ����
	int x = 1, y = 1;// �����̴� #�� ��ǥ
	int cnt = 0; // ������ �ٲ� Ƚ��
	int h = 25, w = 80; // ���� ���� ���� ���� 0-23 �ʺ� 0-53
	while (cnt < 1000) { // ����(1000��) �ݺ�
		while (0 < x + xc && x + xc < w && 0 < y + yc && y + yc < h) { // �� ���⿡�� ���� ���������� �̵�
			gotoxy(x + xc, y + yc);
			printf("#");
			delay(30);
			gotoxy(x + xc, y + yc);
			printf(" ");
			x += xc; y += yc; // ��ǥ �̵�
		}
		// ���� ������ �� ���� ���� ����
		if ((x == 1 || x == w-1) && (y == 1 || y == h-1)) { xc *= -1; yc *= -1; }
		else if (x == 1 || x == w-1) { xc *= -1; }
		else if (y == 1 || y == h-1) { yc *= -1; }
		cnt++;
	}
}
int main()
{
	setcursortype(NOCURSOR);
	draw_wall(80, 25, 0, "*");
	draw_wall(25, 80, 1, "*");
	print3();
	gotoxy(0, 25);
	printf("\n");
	return 0;
}