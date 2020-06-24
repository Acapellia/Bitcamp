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
void print3() { //3번
	int xc = 1, yc = 1; // 이동할 방향
	//xc -> 1: 오른쪽 -1 : 왼쪽  yc -> 1 : 아래쪽 -1 : 위쪽
	int x = 1, y = 1;// 움직이는 #의 좌표
	int cnt = 0; // 방향을 바꿀 횟수
	int h = 25, w = 80; // 벽을 위한 변수 높이 0-23 너비 0-53
	while (cnt < 1000) { // 무한(1000번) 반복
		while (0 < x + xc && x + xc < w && 0 < y + yc && y + yc < h) { // 각 방향에서 벽을 만날때까지 이동
			gotoxy(x + xc, y + yc);
			printf("#");
			delay(30);
			gotoxy(x + xc, y + yc);
			printf(" ");
			x += xc; y += yc; // 좌표 이동
		}
		// 벽을 만났을 때 다음 방향 설정
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