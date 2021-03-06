#include<stdio.h>
#include "turboc.h"

/*
1번
#이 시작위치에서 반복되도록
2번
#이 왕복
3번
#이 반사
*/
void print1() {	// 1번
	int x = 0;
	while (1) {// 무한 반복
		for (x = 0; x <= 80; x++) { // 0-80까지 이동
			gotoxy(x, 12);
			printf("#");
			delay(20);
			gotoxy(x, 12);
			printf(" ");
		}
	}
}
void print2() { // 2번
	int state = 1; // 어느 방향으로 이동할지 정하는 변수
	int x=0;
	while (1) {
		for (int i = 0; i < 50; i++) {
			delay(10);
			gotoxy(x, 12);
			printf("#");
			delay(20);
			gotoxy(x, 12);
			printf(" ");
			x += state;
			if (x == 0 || x == 50) state *= -1;
		}
	}
}
void print3() { //3번
	int xc = 1, yc = 1; // 이동할 방향
	//xc -> 1: 오른쪽 -1 : 왼쪽  yc -> 1 : 아래쪽 -1 : 위쪽
	int x = 0, y = 0;// 움직이는 #의 좌표
	int cnt = 0; // 방향을 바꿀 횟수
	int h = 23, w = 53; // 벽을 위한 변수 높이 0-23 너비 0-53
	while (cnt < 1000) { // 무한(1000번) 반복
		if (0 <= x + xc && x + xc <= w && 0 <= y + yc && y + yc <= h) { // 각 방향에서 벽을 만날때까지 이동
			gotoxy(x + xc, y + yc);
			printf("#");
			delay(30);
			gotoxy(x + xc, y + yc);
			printf(" ");
			x += xc; y += yc; // 좌표 이동
		}
		// 벽을 만났을 때 다음 방향 설정
		if ((x == 0 || x == w) && (y == 0 || y == h)) { xc *= -1; yc *= -1; }
		else if (x == 0 || x == w) { xc *= -1; }
		else if (y == 0 || y == h) { yc *= -1; }
		cnt++;
	}
}
void main()
{
	setcursortype(NOCURSOR);


	printf("원하는 동작을 입력하세요");
	printf("(1. 위치 초기화  2. 왕복  3. 반사) : ");
	int sel;
	scanf("%d", &sel);
	system("cls");
	if (sel == 1)	print1();
	if (sel == 2)	print2();
	if (sel == 3)	print3();
}

/*
U
x++ y-- -> x++ y++   /   x-- y-- -> x-- y++
D
x++ y++ -> x++ y--   /   x-- y++ -> x-- y--
L
x-- y++ -> x++ y++   /   x-- y-- -> x++ y--
R
x++ y++ -> x-- y++   /   x++ y-- -> x-- y--
*/