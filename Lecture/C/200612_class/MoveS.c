#include<stdio.h>
#include "turboc.h"

/* 
1��
#�� ������ġ���� �ݺ��ǵ���
2��
#�� �պ�
3��
#�� �ݻ�
*/
void print1() {	// 1��
	int x = 0;
	while (1) {// ���� �ݺ�
		for (x = 0; x <= 80; x++) { // 0-80���� �̵�
			gotoxy(x, 12);
			printf("#");
			delay(20);
			gotoxy(x, 12);
			printf(" ");
		}
	}
}
void print2() { // 2��
	int state = 0; // ��� �������� �̵����� ���ϴ� ����
	int x;
	while (1) {
		if (state == 0) { // ������
			for (x = 0; x < 50; x++) { // 0-50���� �̵�
				delay(1);
				gotoxy(x, 12);
				printf("#");
				delay(30);
				gotoxy(x, 12);
				printf(" ");
			}// �̵� ��
			state = 1; // �������� �̵��ϱ� ���� �� ����
		}
		else if (state == 1) { // ����
			for (x = 50; x > 0; x--) { // 50-0���� �̵�
				delay(1);
				gotoxy(x, 12);
				printf("#");
				delay(30);
				gotoxy(x, 12);
				printf(" ");
			}// �̵� ��
			state = 0; // ���������� �̵��ϱ� ���� �� ����
		}
	}
}
void print3() { //3��
	int xc = 1, yc = 1; // �̵��� ����
	//xc -> 1: ������ -1 : ����  yc -> 1 : �Ʒ��� -1 : ����
	int x = 0, y = 0;// �����̴� #�� ��ǥ
	int cnt = 0; // ������ �ٲ� Ƚ��
	int h = 23, w = 53; // ���� ���� ���� ���� 0-23 �ʺ� 0-53
	while (cnt<1000) { // ����(1000��) �ݺ�
		while (0 <= x + xc && x + xc <= w && 0 <= y + yc && y + yc <= h) { // �� ���⿡�� ���� ���������� �̵�
			gotoxy(x + xc, y + yc);
			printf("#");
			delay(30);
			gotoxy(x + xc, y + yc);
			printf(" ");
			x += xc; y += yc; // ��ǥ �̵�
		}
		// ���� ������ �� ���� ���� ����
		if (x == 0 && y == 0) { // LU ����
			xc = 1; yc = 1; // ��
		}
		else if (x == w && y == 0) { // RU ����
			xc = -1; yc = 1; // ��
		}
		else if (x == 0 && y == h) { // LD ����
			xc = 1; yc = -1; // ��
		}
		else if (x == w && y == h) { // RD ����
			xc = -1; yc = -1; // ��
		}
		else if (x == w) { // R
			if (xc == 1 && yc == 1) { // ��
				xc = -1; yc = 1; // ��
			}
			else if (xc == 1 && yc == -1) { // ��
				xc = -1; yc = -1; // ��
			}
		}
		else if (x == 0) { // L
			if (xc == -1 && yc == 1) { // ��
				xc = 1; yc = 1; // ��
			}
			else if (xc == -1 && yc == -1) { // ��
				xc = 1; yc = -1; // ��
			}
		}
		else if (y == h) { //D
			if (xc == 1 && yc == 1) { // ��
				xc = 1; yc = -1; // ��
			}
			else if (xc == -1 && yc == 1) { // ��
				xc = -1; yc = -1; // ��
			}
		}
		else if (y == 0) { // U
			if (xc == 1 && yc == -1) { // ��
				xc = 1; yc = 1; // ��
			}
			else if (xc == -1 && yc == -1) { // ��
				xc = -1; yc = 1; // ��
			}
		}
		cnt++;
	}
}
/*void main() 
{
	setcursortype(NOCURSOR);

	
	printf("���ϴ� ������ �Է��ϼ���");
	printf("(1. ��ġ �ʱ�ȭ  2. �պ�  3. �ݻ�) : ");
	int sel;
	scanf("%d", &sel);
	system("cls");
	if(sel == 1)	print1();
	if(sel == 2)	print2();
	if(sel == 3)	print3();
}*/

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