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
void print1() {
	int x = 0;
	while (1) {
		for (x = 0; x <= 80; x++) {
			gotoxy(x, 12);
			printf("#");
			delay(20);
			gotoxy(x, 12);
			printf(" ");
		}
	}
}
void print2() {
	int state = 0;
	int x;
	while (1) {
		if (state == 0) {
			for (x = 0; x < 50; x++) {
				delay(1);
				gotoxy(x, 12);
				printf("#");
				delay(30);
				gotoxy(x, 12);
				printf(" ");
			}
			state = 1;
		}
		else if (state == 1) {
			for (x = 50; x > 0; x--) {
				delay(1);
				gotoxy(x, 12);
				printf("#");
				delay(30);
				gotoxy(x, 12);
				printf(" ");
			}
			state = 0;
		}
	}
}
void print3() {
	int xc = 1, yc = 1;
	int x = 0, y = 0;
	int cnt = 0;
	int h = 23, w = 53;
	while (cnt<100) {
		while (0 <= x + xc && x + xc <= w && 0 <= y + yc && y + yc <= h) {
			gotoxy(x + xc, y + yc);
			printf("#");
			delay(30);
			gotoxy(x + xc, y + yc);
			printf(" ");
			x += xc; y += yc;
		}

		if (x == 0 && y == 0) {
			xc = 1; yc = 1;
		}
		else if (x == w && y == 0) {
			xc = -1; yc = 1;
		}
		else if (x == 0 && y == h) {
			xc = 1; yc = -1;
		}
		else if (x == w && y == h) {
			xc = -1; yc = -1;
		}
		else if (x == w) { // R
			if (xc == 1 && yc == 1) {
				xc = -1; yc = 1;
			}
			else if (xc == 1 && yc == -1) {
				xc = -1; yc = -1;
			}
		}
		else if (x == 0) { // L
			if (xc == -1 && yc == 1) {
				xc = 1; yc = 1;
			}
			else if (xc == -1 && yc == -1) {
				xc = 1; yc = -1;
			}
		}
		else if (y == h) { //D
			if (xc == 1 && yc == 1) {
				xc = 1; yc = -1;
			}
			else if (xc == -1 && yc == 1) {
				xc = -1; yc = -1;
			}
		}
		else if (y == 0) { // U
			if (xc == 1 && yc == -1) {
				xc = 1; yc = 1;
			}
			else if (xc == -1 && yc == -1) {
				xc = -1; yc = 1;
			}
		}
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
	if(sel == 1)	print1();
	if(sel == 2)	print2();
	if(sel == 3)	print3();
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